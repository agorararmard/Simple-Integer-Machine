#include "Processor.h"

void Proccessor::loadInstMem(std::string filename){
    int *d =dataMemory;
    Instruction **i = instMemory;
    Parser P(d,i,pc, filename);
    P.readInstMem();
}


void Proccessor::run(){
    pc =0;
    while(true){
        try{
            if(pc == InstructionMemorySize) return;
            std::cout << "\nPC: " << pc<< " output -> ";
       
            instMemory[pc]->exec();
            pc++;
        }catch(int& ex){
            if(ex == 103)
                return;
            else std::cout << ex << std::endl;
        }
    }
}