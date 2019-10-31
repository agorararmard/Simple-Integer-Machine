#include "Processor.h"
using namespace std;

int main(){
    try{
    Proccessor Pr;
    Pr.loadInstMem("code.txt");
    Pr.run();
    }catch(int& i){
        cout << i << endl;
    }
}