#include<iostream>
//#include<thread>
#include<windows.h>
#include<string>
using namespace std;

string numeroruleta(int n, int numero){
    
        cout<<" ";
    
    if(n%2==0){
        return (" \033[37m"+to_string(numero)+"\033[0m");
    }else{
        return(" \033[31m"+to_string(numero)+"\033[0m");
    }
    
}

void marcoRuleta(){
    int Numero[30]={30, 16, 9, 6, 11, 19, 15, 7, 8, 25, 17, 10, 29, 18, 27, 5, 1, 14, 22, 2, 21, 28, 3, 20, 13, 4, 23, 26, 12, 24};
    //int Numero[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    int n, bandera, contador, contador2;
    n=0;
    for(int i=0;i<1;i++){// hacer la animacion de la ruleta
        bandera=0;
        contador=0;
        contador2=30;
        

///////////////////////////////////////////////////        
        for(n=0;n<9;n++){
            if(n==0){
                bandera=9;
            }else{
                
                if(n==7){
                    bandera=9;
                }else{
                    if(n>=1){
                        if(n<=6){
                            bandera=1;
                        }
                        
                        
                    }

                }
                
            }
            
/////////////////////////////////////////////////

            for(int ii=0; ii<bandera;ii++){
                
                if(n==0){
                    cout<<numeroruleta(contador, Numero[contador]);
                    
                    
                }else{
                    if(n>=1){
                        if(n<=6){
                            contador2=contador2-1;
                            cout<<numeroruleta((contador2), Numero[(contador2)])<<"                         ";
                            if(n==5){
                                cout<<" ";
                            }
                            cout<<numeroruleta(contador, Numero[contador]);
                        }
                    }
                    if(n==7){
                        contador2=contador2-1;
                        cout<<numeroruleta(contador2,Numero[contador2]);
                        
                    }
                }
                contador++;
            }
            cout<<"\n\n";
            
            
        }
      
    }
    
    /*
    cout<<"     ___________________"<<endl;
    cout<<"   / 1 2 3 4 5 6 7 8 9 \\"<<endl;
    cout<<"  / 32                  10\\"<<endl;   22
    cout<<"* |31                   11| *"<<endl;
    cout<<"* |30                   12| *"<<endl;
    cout<<"* |29                   13| *"<<endl;
    cout<<"* |28                   14| *"<<endl;
    cout<<"* |27                   15| *"<<endl;
    cout<<"* |26                   16| *"<<endl;
    cout<<"* |25                   17| *"<<endl;
    cout<<"  \\ 24 23 22 21 20 19 18 /"<<endl;
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

