#include "Instruction1Param.cpp"
#include "sizes.h"
class writeInstruction: public Instruction1Param{
    public:
    writeInstruction(int& rs, bool isRsAddress): Instruction1Param(rs, isRsAddress){
        if(!isRsAddress){
                throw(101);
        }
    }
    void exec(){
        std::cout << *rs;
    }
    ~writeInstruction(){}
};