#include<iostream>
//#include<thread>
#include<windows.h>
#include<string>
using namespace std;

void marcoRuleta(){
    int Numero[32]={7,18,25,10,15,3,16,31,8,29,2,23,13,6,9,30,5,12,27,4,21,17,28,19,14,11,26,1,20,24,22,32};
    int n;
    n=1;
    string r1, r2, b1, b2;
    r1="\033[31m";
    r2="\033[0m";
    cout<<"     ___________________"<<endl;
    cout<<"   /  2 3 4 5 6 7 8 9 10 \\"<<endl;
    cout<<"  /  1                 11 \\"<<endl;
    cout<<"* |18                   12| *"<<endl;
    cout<<"* |19                   13| *"<<endl;
    cout<<"* |20                   14| *"<<endl;
    cout<<"* |31                   32| *"<<endl;
    cout<<"* |21                   15| *"<<endl;
    cout<<"* |22                   16| *"<<endl;
    cout<<"* |23                   17| *"<<endl;
    cout<<"  \\ 24 25 26 27 28 29 30 /"<<endl;
    cout<<"   \\____________________/"<<endl;
    Sleep(1000);
    cout<<"hola";

}
main(){
    int contador, opcion1, opcion2, n;
    //cout<<"Para jugar la ruleta seleccione una de los tipos de apuesta a continuacion"<<endl;
    marcoRuleta();
    
    
}

