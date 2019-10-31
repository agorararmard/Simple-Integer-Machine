#include"../sizes.h"
class haltInstruction: public Instruction{
    protected:
        int *rs;
        bool isRsAddress;
    public:
    haltInstruction(){}
    virtual void exec(){
        throw(103); //to be handled in main as breaking exception
    }
    ~haltInstruction(){};    //here the destructor of P is called so there is no need to do anything
};