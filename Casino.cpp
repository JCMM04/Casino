#include<iostream>
//#include<thread>
#include<windows.h>
#include<string>
using namespace std;

string numeroruleta(int n, int numero){
    
        cout<<" ";
    
    if(n%2==0){
        return ("\033[37m"+to_string(numero)+"\033[0m");
    }else{
        return("\033[31m"+to_string(numero)+"\033[0m");
    }
    
}

void marcoRuleta(){
    int Numero[32]={7,18,25,10,15,3,16,31,8,29,2,23,13,6,9,30,5,12,27,4,21,17,28,19,14,11,26,1,20,24,22,32};
    int n, bandera, contador;
    n=0;
    for(int i=0;i<32;i++){// hacer la animacion de la ruleta
        
        cout<<"     ___________________"<<endl;
        cout<<"   /";
        for(n=0;n<10;n++){
            if(n==0){
                bandera=9;
            }else{
                
                if(n==9){
                    bandera==7;
                }else{
                    if(n>=1){
                        if(n<=8){
                            bandera=2;
                        }
                    }

                }
                
            }
            for(int ii=0; ii<bandera;ii++){
                if (/* condition */)
                {
                    /* code */
                }
                
            }
            
            
        }
        cout<<" /"<<endl;
        cout<<"   \\____________________/"<<endl;
      
    }
    
    /*
    cout<<"     ___________________"<<endl;
    cout<<"   / 2 3 4 5 6 7 8 9 10 \\"<<endl;
    cout<<"  / 1                  11\\"<<endl;
    cout<<"* |32                   12| *"<<endl;
    cout<<"* |31                   13| *"<<endl;
    cout<<"* |30                   14| *"<<endl;
    cout<<"* |29                   15| *"<<endl;
    cout<<"* |28                   16| *"<<endl;
    cout<<"* |27                   17| *"<<endl;
    cout<<"* |26                   18| *"<<endl;
    cout<<"  \\ 25 24 23 22 21 20 19 /"<<endl;
    cout<<"   \\____________________/"<<endl;
    Sleep(1000);
    cout<<"hola";
    */
}
main(){
    int contador, opcion1, opcion2, n;
    //cout<<"Para jugar la ruleta seleccione una de los tipos de apuesta a continuacion"<<endl;
    marcoRuleta();
    
    
}

