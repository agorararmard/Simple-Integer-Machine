#include "../sizes.h"
class jmpInstruction: public Instruction2Param{
    public:
    jmpInstruction(int& rs, bool isRsAddress,int& rd, bool isRdAddress ): Instruction2Param(rs, isRsAddress, rd, isRdAddress){
        if(isRsAddress){
                throw(101);
        }
    }
    virtual void exec(){
        if(*rs <0 || *rs > InstructionMemorySize)
            throw(102);
        *rd = (*rs) - 1;
    }
    ~jmpInstruction(){}
};