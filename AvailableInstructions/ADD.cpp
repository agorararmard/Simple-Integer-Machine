#include"../sizes.h"
class addInstruction: public Instruction3Param{
    public:
    addInstruction(int& rs1, bool isRs1Address,int& rs2, bool isRs2Address,int& rd, bool isRdAddress ): Instruction3Param(rs1, isRs1Address, rs2, isRs2Address, rd, isRdAddress){
        if(!isRdAddress){
            throw(101);
        }
    }
    virtual void exec(){
        *rd = *rs1 + *rs2;
    }
    ~addInstruction(){}
};