#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H
#include "sizes.h"
#include "Instructions.h"
#include "Exceptions.h"
#include <cstdlib>

class InstructionFactory
{
private:
    int convertToInt(std::string s);
    bool interpretParam(std::string &param,int* &p,int* &dataMemory);
public:
    InstructionFactory(){}
    Instruction* createInstruction(std::string instType, std::string firstParam, std::string secondParam, std::string thirdParam,int&pc, int* &dataMemory);
    ~InstructionFactory(){}
};

#include"InstructionFactory.cpp"
#endif