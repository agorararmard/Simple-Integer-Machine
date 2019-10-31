#include "Instruction.cpp"
class HALT: public Instruction{
    protected:
        int *rs;
        bool isRsAddress;
    public:
    HALT(){}
    virtual void exec(){
        throw(103); //to be handled in main as breaking exception
    }
    ~HALT(){};    //here the destructor of P is called so there is no need to do anything
};