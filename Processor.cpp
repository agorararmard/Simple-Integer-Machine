#include "Processor.h"


void Proccessor::loadInstMem(std::string filename){
    int *d =dataMemory;
    Instruction **i = instMemory;
    Parser P(d,i,pc, filename);
    try{
    P.readInstMem();
    }catch(std::exception& exp){
        std::cout << exp.what() << std::endl;
        return;
    }
}


void Proccessor::run(){
    pc =0;
    while(true){
        try{
            if(pc == InstructionMemorySize) return;
            std::cout << "\nProgram Counter: " << pc<< " Input/Output ---> ";
            if(instMemory[pc] == nullptr)   throw NullInstruction();
            instMemory[pc]->exec();
            pc++;
        }catch(std::runtime_error& exp){
            if(exp.what() == HALTException().what())
                return;
            else {
                std::cout << exp.what() << std::endl;
                return;
            }
        }
    }
}