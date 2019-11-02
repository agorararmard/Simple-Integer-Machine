#include "InstructionFactory.h"

int InstructionFactory::convertToInt(std::string s){
    int ret = atoi(s.c_str());
    if(!ret && s[0] != '0' && s.length()==1) throw InvalidParameter(s);
    return ret;
}
bool InstructionFactory::interpretParam(std::string &param,int* &p, int* &dataMemory){
            if(param[0] == '$'){
                int address = convertToInt(param.substr(1));
                if(address >=0 && address < dataMemorySize)
                    {
                        p = &dataMemory[address];
                        return true;
                    }
                    else throw OutOfDataMemoryBounds();
            }else {
                p = new int;
                *p = convertToInt(param); 
            }
            return false;
}

Instruction* InstructionFactory::createInstruction(std::string instType, std::string firstParam, std::string secondParam, std::string thirdParam,int&pc, int* &dataMemory){

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
            throw InsufficientParameters("ADD",std::to_string(pc));
    }
    
    if(instType =="NEG"){
        if(firstParam!="" &&secondParam !="" && thirdParam =="")
        {
            int *p1,*p2;
            bool fp2 = interpretParam(secondParam,p2,dataMemory);
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            return new negInstruction(*p1,fp1,*p2,fp2);
        }
        else 
            throw InsufficientParameters("NEG",std::to_string(pc));
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
            throw InsufficientParameters("MUL",std::to_string(pc));
    }

    if(instType =="JMP"){

       if(firstParam!="" &&secondParam =="" && thirdParam =="")
        {
            int *p1;
            bool fp1 = interpretParam(firstParam,p1,dataMemory);
            return new jmpInstruction(*p1,fp1, pc,true);
        }
        else 
            throw InsufficientParameters("JMP",std::to_string(pc));
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
            throw InsufficientParameters("JMP0",std::to_string(pc));
 
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
            throw InsufficientParameters("ASS",std::to_string(pc));
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
            throw InsufficientParameters("LE",std::to_string(pc));
    }

    if(instType =="READ"){

        if(firstParam!="" &&secondParam =="" && thirdParam =="")
        {

            int *p;
            bool fp = interpretParam(firstParam,p,dataMemory);
            return new readInstruction(*p,fp);
        }
        else 
            throw InsufficientParameters("READ",std::to_string(pc));
    }

    if(instType =="WRITE"){
        if(firstParam!="" &&secondParam =="" && thirdParam =="")
        {
            int *p;
            bool fp = interpretParam(firstParam,p,dataMemory);
            return new writeInstruction(*p,fp);
        }
        else 
            throw InsufficientParameters("WRITE",std::to_string(pc));
        
    }


    if(instType =="HALT"){
        if(firstParam =="" && secondParam =="" && thirdParam =="")
            return new haltInstruction();
        else{
            throw InsufficientParameters("HALT",std::to_string(pc));
        }
    }


    
    throw InvalidInstruction(instType, std::to_string(pc));
}

