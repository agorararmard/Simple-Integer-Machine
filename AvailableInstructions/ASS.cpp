#include"../sizes.h"
class assInstruction: public Instruction2Param{
    public:
    assInstruction(int& rs, bool isRsAddress,int& rd, bool isRdAddress ): Instruction2Param(rs, isRsAddress, rd, isRdAddress){
        if(!isRdAddress){
            throw(101);
        }
    }
    void exec(){
        *rd = *rs;
    }
    ~assInstruction(){}
};