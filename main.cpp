#include<iostream>
using namespace std;
void func(int *i);

int main(){
    int arr[100];
    arr[5] = 10;
    int *i;
    func(i);
    cout <<*i;
    return 0;
}

void func(int *i){
    int j = 5;
    i = &j;
    return;
}