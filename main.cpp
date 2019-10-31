#include<iostream>
#include<string>
#include <cstdlib>
#include "InstructionFactory.h"
using namespace std;


void getInstructionType(std::string& line,std::string& instType){
    std::size_t pos = line.find(" ");
    
    instType = line.substr(0,pos);
}
void getFirstParameter(std::string& line,std::string& firstParam){
    std::size_t pos1 = line.find(" ");
    std::size_t pos2 = line.find(",");
    
    if(pos1 != std::string::npos)
        firstParam = line.substr(pos1+1,pos2-pos1-1);
    else
        firstParam = "";
    
}
void getSecondParameter(std::string& line,std::string& secondParam){
    std::size_t pos1 = line.find(",");
    std::size_t pos2 = line.rfind(",");
    if(pos1 != std::string::npos)
        secondParam = line.substr(pos1+1,pos2-pos1-1);
    else
        secondParam ="";
}
void getThirdParameter(std::string& line,std::string& thirdParam){
    
    std::size_t pos1 = line.rfind(",");
    std::size_t pos2 = line.length();
   
    if(pos1 == line.find(","))
        {
            thirdParam = "";
            return;
        }
    
    if(pos1 != std::string::npos)
        thirdParam = line.substr(pos1+1,pos2-pos1-1);
    else
        thirdParam = "";
}


int convertToInt(std::string s){
    cout << s << endl;
    int ret = atoi(s.c_str());
    if(!ret && s[0] != '0' && s.length()==1) throw(104);
    return ret;
}

bool interpretParam(std::string &param,int* &p, int* dataMemory){
            if(param[0] == '$'){
                cout << "interpretting " << param << endl;
                int address = convertToInt(param.substr(1));
                cout << address << endl;
                if(address >0 && address < dataMemorySize)
                    {
                        p = &dataMemory[address];
                         cout << "ptr val is " << *p << endl;        
                        return true;
                    }
            }else {
                p = new int;
                *p = convertToInt(param); 
                cout << "int val is " << convertToInt(param) << endl;
                cout << "ptr val is " << *p << endl;
            }
            return false;
}

int main(){
    string line = "JMP 1";
    string instType;
    string firstParam;
    string secondParam;
    string thirdParam;
    int* arr = new int[1024];
    int pc= 5;
    
    getInstructionType(line, instType);
    getFirstParameter(line, firstParam);
    getSecondParameter(line, secondParam);
    getThirdParameter(line, thirdParam);
    
    cout <<  instType<< endl;
    cout << firstParam <<endl;
    cout << secondParam <<endl;
    cout << thirdParam <<endl;


    arr[3] = 5;

    arr[1] = 5;
    /*int *p1, *p2, *p3;
    bool f1 = interpretParam(firstParam,p1,arr);
    bool f2 = interpretParam(secondParam,p2,arr);
    bool f3 = interpretParam(thirdParam,p3,arr);
    
    cout << f1 << " " << *p1 << endl;
    cout << f2 << " " << *p2 << endl;
    cout << f3 << " " << *p3 << endl;
     */
 
    //cout <<arr[1]<< endl;
    //delete[] arr;
    //delete p1,p2,p3;
    

    
    InstructionFactory fact;
    try{

    cout << "arr is now "<<arr[3]<< endl;
    Instruction* inst = fact.createInstruction(instType,firstParam,secondParam,thirdParam, pc, arr);
    cout << "pc is now "<<pc<< endl;
    inst->exec();
    cout << "pc is now "<<pc<< endl;
  
    delete inst;
    delete[] arr;
    }catch(int&exceptionS){
        cout << exceptionS <<endl;
    }
    
/*    
    
    cout << line << endl;
    cout << atoi(firstParam.c_str()) << endl;
    cout << atoi(secondParam.c_str()) << endl;
    
    cout << atoi(thirdParam.c_str()) << endl;
   */
    return 0;
}
