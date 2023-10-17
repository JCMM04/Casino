#include<iostream>
//#include<thread>
#include<windows.h>
#include<string>
using namespace std;

int numeroruleta(int n, int numero, int i){
    int par;
    par=n%2;
    if(n==i){
        cout<<" \033[32m"+to_string(numero)+"\033[0m ";
    }else{
        if(par==0){
            cout<<" \033[37m"+to_string(numero)+"\033[0m ";
        }else{
            cout<<" \033[31m"+to_string(numero)+"\033[0m ";
        }
    }
    return(0);
    /*
    if(opcion==1){
        if(par==0){
            if(numero%2==0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(numero%2!=0){
                return 1;
            }else{
                return 0;
            }
        }
    }
    if(opcion==2){
        if(apuesta==1){
            if(numero%2==0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(numero%2!=0){
                return 1;
            }else{
                return 0;
            }
        }
    }
    if(opcion==3){
        if(apuesta==numero){
            return 1;
        }else{
            return 0;
        }
    }
    */
    
}

void marcoRuleta(int opcion, int apuesta, int detentesatanas){
    int Numero[30]={30, 16, 9, 6, 11, 19, 15, 7, 8, 25, 17, 10, 29, 18, 27, 5, 1, 14, 22, 2, 21, 28, 3, 20, 13, 4, 23, 26, 12, 24};
    //int Numero[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    int n, bandera, contador, contador2;
    
    
    n=0;
    for(int i=0;i<detentesatanas;i++){// hacer la animacion de la ruleta
        Sleep(800);
        system("cls");
        bandera=0;
        contador=0;
        contador2=30;

///////////////////////////////////////////////
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
                    numeroruleta(contador, Numero[contador], i);
                    
                    
                    
                }else{
                    if(n>=1){
                        if(n<=6){
                            contador2=contador2-1;
                            numeroruleta((contador2), Numero[(contador2)], i);
                            cout<<"                         ";
                            if(n==5){
                                cout<<" ";
                            }
                            numeroruleta(contador, Numero[contador], i);
                        }
                    }
                    if(n==7){
                        contador2=contador2-1;
                        numeroruleta(contador2,Numero[contador2], i);
                        
                    }
                }
                contador++;
            }
            cout<<"\n\n";
            
        }
        
    }
    if(Numero[detentesatanas-1]==apuesta){
        cout<<"Ganaste papucho";
    }else{
        cout<<"Perdiste wapo";
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
    int opcion, apuesta, vApostado, detentesatanas;
    cout<<"Para jugar la ruleta seleccione una de los tipos de apuesta a continuacion: "<<endl;
    cout<<"1. Apostar a color."<<endl;
    cout<<"2. Apostar a par o impar."<<endl;
    cout<<"3. Apostar a numero."<<endl;
    cout<<"Ingrese el numero de opcion a elegir: ";
    cin>>opcion;
    if(opcion==1){
        cout<<"Ingrese a que color desea apostar: ";
        cin>>apuesta;
    }else{
        if(opcion==2){
            cout<<"Ingrese el numero de opcion a la que desea apostar: "<<endl;
            cout<<"1. Par"<<endl;
            cout<<"2. Impar"<<endl;
            cin>>apuesta;

        }else{
            if(opcion==3){
                //detentesatanas=1+rand() % (31-1);
                detentesatanas=30;
                cout<<"--"<<detentesatanas<<"--"<<endl;
                cout<<"Ingrese el numero al que desea apostar(1-30): ";
                cin>>apuesta;
            }
        }
    }
    
    marcoRuleta(opcion, apuesta, detentesatanas);
    
    
}

