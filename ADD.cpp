#include<Instruction.cpp>
class addInstruction: public Instruction{
    private:
        int
    public:
        void exec(){
            *P.rd = *P.rs1 + *P.rst
        }
}