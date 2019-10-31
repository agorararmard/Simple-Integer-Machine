#include"Instruction3Param.cpp"
#include "sizes.h"
class addInstruction: public Instruction3Param{
    public:
    addInstruction(int& rs1, bool isRs1Address,int& rs2, bool isRs2Address,int& rd, bool isRdAddress ): Instruction3Param(rs1, isRs1Address, rs2, isRs2Address, rd, isRdAddress){
        if(!isRs2Address){
            throw(101);
        }
    }
    void exec(){
        if(*rs2 <0 || *rs2 > dataMemorySize)
            throw(102);
        if(!*rs1){
            *rd = *rs2 - 1;
        }
    }
    ~addInstruction(){}
};