#include "Processor.h"

void Proccessor::loadInstMem(std::string filename){
    int *d =dataMemory;
    Instruction *i = instMemory;
    Parser P(d,i,pc, filename);
    P.readInstMem();
}


void Proccessor::run(){
    while(1){
        try{
            if(pc ==InstructionMemorySize) return;
            instMemory[pc].exec();
            pc++;
        }catch(int& ex){
            if(ex == 3)
                return;
        }
    }
}