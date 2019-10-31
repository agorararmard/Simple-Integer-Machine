#ifndef PARSER_H
#define PARSER_H
#include "InstructionFactory.h"
#include <string>
#include <fstream>
class Parser{
    private:
        InstructionFactory instFactory;
        int* dataMemory;
        Instruction* instMemory;
        int* pc;
       
        std::string fileInst;
       
        void getInstructionType(std::string& line,std::string& instType);
        void getFirstParameter(std::string& line,std::string& firstParam);
        void getSecondParameter(std::string& line,std::string& secondParam);
        void getThirdParameter(std::string& line,std::string& thirdParam);
    public:
        Parser(int* &dataMemory,Instruction* &instMemory,int& pc, std::string fileInst):dataMemory(dataMemory),instMemory(instMemory),pc(&pc),fileInst(fileInst){}
        
        void readInstMem();

        ~Parser(){}


};

#endif