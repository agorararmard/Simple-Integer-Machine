#include "Processor.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    try{
    Proccessor Pr;
    if(argc == 1) {
        cout << "Please specify the input program through the command line; read the README.md for more details" << endl;
        return 0;
    }
    Pr.loadInstMem(argv[1]);
    Pr.run();
    return 0;
    }catch(exception& exp){
        cout << exp.what() << endl;
        return 0;
    }
}