#include"../sizes.h"
class Instruction3Param: public Instruction{
    protected:
        int *rd;    //rd is always an address
        int *rs1;
        int *rs2;
        bool isRdAddress;
        bool isRs1Address;
        bool isRs2Address;
    public:
    
    Instruction3Param(int& rs1, bool isRs1Address,int& rs2, bool isRs2Address,int& rd, bool isRdAddress):rd(&rd),isRdAddress(isRdAddress),rs1(&rs1),isRs1Address(isRs1Address),rs2(&rs2),isRs2Address(isRs2Address){

    }
    
    Instruction3Param(Instruction3Param& I):isRdAddress(I.isRdAddress),isRs1Address(isRs1Address),isRs2Address(isRs2Address){
        if(isRdAddress){
            rd = I.rd;
        }else{
            rd = new int;
            *rd = *I.rd;
        }

        if(isRs1Address){
            rs1 = I.rs1;
        }else{
            rs1 = new int;
            *rs1 = *I.rs1;
        }

        if(isRs2Address){
            rs2 = I.rs2;
        }else{
            rs2 = new int;
            *rs2 = *I.rs2;
        }
    }
    virtual void exec()=0;
    virtual ~Instruction3Param(){
        if(!isRdAddress) delete rd;
        if(!isRs1Address) delete rs1;
        if(!isRs2Address) delete rs2;
    };    //here the destructor of P is called so there is no need to do anything
};