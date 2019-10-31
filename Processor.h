#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Parser.h"
#include "sizes.h"
#include "Instructions.h"

class Proccessor{
    private:
        int dataMemory[dataMemorySize];
        Instruction *instMemory[InstructionMemorySize];
        int pc;
    public:
        Proccessor(){}
        void loadInstMem(std::string filename);
        void run();
        ~Proccessor(){
            for (int i =0; i < InstructionMemorySize;i++)
                if(instMemory[i] != nullptr)
                    delete instMemory[i];
                else
                    break;
                

        }
};
#include"Processor.cpp"
#endif