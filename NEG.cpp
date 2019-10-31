#include"Instruction2Param.cpp"
class negInstruction: public Instruction2Param{
    public:
    negInstruction(int& rs, bool isRsAddress,int& rd, bool isRdAddress ): Instruction2Param(rs, isRsAddress, rd, isRdAddress){
        if(!isRdAddress){
                throw(101);
        }
    }
    void exec(){
        *rd = -*rs;
    }
    ~negInstruction(){}
};