#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Parser.h"
#include "sizes.h"
#include "Instructions.h"

class Proccessor{
    private:
        int dataMemory[dataMemorySize];
        Instruction instMemory[InstructionMemorySize];
        int pc;
    public:
        Proccessor();
        void loadInstMem(std::string filename);
        void run();
        ~Proccessor(){}
};
#include"Processor.cpp"
#endif