#include <iostream>
#include <stdlib.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
static llvm::LLVMContext TheContext;
static llvm::IRBuilder<> Builder(TheContext);
static std::unique_ptr<llvm::Module> TheModule;
int main(){
    TheModule = std::make_unique<llvm::Module>("tinpo", TheContext);
    llvm::Function* mainFunc = llvm::Function::Create(
        llvm::FunctionType::get(llvm::Type::getInt32Ty(TheContext), false),
        llvm::Function::ExternalLinkage, "main", TheModule.get());
    Builder.SetInsertPoint(llvm::BasicBlock::Create(TheContext, "", mainFunc));
    Builder.CreateRet(Builder.getInt32(42));
    TheModule->print(llvm::errs(),nullptr);   
}