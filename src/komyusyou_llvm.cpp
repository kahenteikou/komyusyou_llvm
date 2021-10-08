#include <iostream>
#include <stdlib.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
int main(){
    char* data=(char*)calloc(32767,sizeof(char));
    char* ptr=data;
    free(data);
    return 0;
}