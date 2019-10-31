#include "InstructionFactory.h"

int InstructionFactory::convertToInt(std::string s){
    int ret = atoi(s.c_str());
    if(!ret && s[0] != '0' && s.length()==1) throw(104);
    return ret;
}
bool InstructionFactory::interpretParam(std::string &param,int* &p, int* &dataMemory){
            if(param[0] == '$'){
                int address = convertToInt(param.substr(1));
                std::cout << "address is : " << address << std::endl;
                if(address >0 && address < dataMemorySize)
                    {
                        p = &dataMemory[address];
                        return true;
                    }
            }else {
                p = new int;
                *p = convertToInt(param); 
            }
            return false;
}

Instruction* InstructionFactory::createInstruction(std::string instType, std::string firstParam, std::string secondParam, std::string thirdParam,int&pc, int* &dataMemory)
{
    if(instType == "ADD"){

        if(firstParam!="" &&secondParam !="" && thirdParam !="")
        {
            int *p1,*p2,*p3;

            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            bool fp3 = interpretParam(thirdParam,p3,dataMemory);
            return new addInstruction(*p1,fp1,*p2,fp2,*p3,fp3);
        }
        else 
            throw(104);
    }
    
    if(instType =="NEG"){
        if(firstParam!="" &&secondParam !="" && thirdParam =="")
        {
            int *p1,*p2;
            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            return new assInstruction(*p1,fp1,*p2,fp2);
        }
        else 
            throw(104);
    }


    if(instType =="MUL"){
        if(firstParam!="" &&secondParam !="" && thirdParam !="")
        {
            int *p1,*p2,*p3;

            bool fp3 = interpretParam(thirdParam,p3,dataMemory);
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            return new mulInstruction(*p1,fp1,*p2,fp2,*p3,fp3);
        }
        else 
            throw(104);
    }

    if(instType =="JMP"){

       if(firstParam!="" &&secondParam =="" && thirdParam =="")
        {
            int *p1;
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            return new jmpInstruction(*p1,fp1, pc,true);
        }
        else 
            throw(104);
    }

    if(instType =="JMP0"){
       if(firstParam!="" &&secondParam !="" && thirdParam =="")
        {
            int *p1,*p2;

            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            return new jmp0Instruction(*p1,fp1,*p2,fp2,pc,true);
        }
        else 
            throw(104);
 
    }

    if(instType =="ASS"){
        if(firstParam!="" &&secondParam !="" && thirdParam =="")
        {
            int *p1,*p2;

            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            return new assInstruction(*p1,fp1,*p2,fp2);
        }
        else 
            throw(104);
    }

    if(instType =="LE"){
        if(firstParam!="" &&secondParam !="" && thirdParam !="")
        {
            int *p1,*p2,*p3;

            bool fp3 = interpretParam(thirdParam,p3,dataMemory);
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            return new leInstruction(*p1,fp1,*p2,fp2,*p3,fp3);
        }
        else 
            throw(104);
    }

    if(instType =="READ"){

        if(firstParam!="" &&secondParam =="" && thirdParam =="")
        {

            int *p;
            bool fp = interpretParam(firstParam,p,dataMemory);
            return new readInstruction(*p,fp);
        }else throw(104);
    }

    if(instType =="WRITE"){
        if(firstParam!="" &&secondParam =="" && thirdParam =="")
        {
            int *p;
            bool fp = interpretParam(firstParam,p,dataMemory);
            return new writeInstruction(*p,fp);
        }else throw(104);
        
    }


    if(instType =="HALT"){
        if(firstParam =="" && secondParam =="" && thirdParam =="")
            return new haltInstruction();
        else{
            throw(104);
        }
    }
    throw(104); //invalid instruction
}

