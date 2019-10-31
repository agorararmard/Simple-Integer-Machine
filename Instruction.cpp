struct Parameters
{
    int* rd;
    int* rs1;
    int* rs2;
    bool isRdAddress;
    bool isRs1Address;
    bool isRs2Address;
    bool nullified = false;
    public:
    void nullify(){
        rd = nullptr;
        rs1 = nullptr;
        rs2 = nullptr;
        nullified = true;
    }
    ~Parameters(){
        if (!nullified){
            if(!isRdAddress){
                delete rd;
            }
            if(!isRs1Address){
                delete rs1;
            }
            if(!isRs2Address){
                delete rs2;
            }
        }
    }
};

class Instruction{
private:
    Parameters P;
public:
Instruction(Parameters P):P(P){}
Instruction(Instruction& I):P(I.P){}
Instruction(Instruction&& I):P(I.P){
    I.P.nullify();
}
virtual void exec()=0;
virtual ~Instruction(){};    //here the destructor of P is called so there is no need to do anything

};

