#include<iostream>
//#include<thread>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;
int cTotales=5000;
int numeroRuleta(int n, int numero, int i);
int marcoRuleta(int numeroApostado, int cActuales);
void menuRuleta();
main(){
    menuRuleta();
}
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
    
}

int marcoRuleta(int numeroApostado, int cActuales){
    
    //int puntoApuestas=0;
    int resultado;
    //resultado=1+rand() % (31-1);
    resultado=30;

    int Numero[30]={30, 16, 9, 6, 11, 19, 15, 7, 8, 25, 17, 10, 29, 18, 27, 5, 1, 14, 22, 2, 21, 28, 3, 20, 13, 4, 23, 26, 12, 24};
    int n, bandera, contador, contador2;
    n=0;
    for(int i=0;i<resultado;i++){// hacer la animacion de la ruleta
        Sleep(100);
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
    if(numeroApostado==Numero[resultado-1]){
        return 1;
    }else{
        return 0;
    }
}

void menuRuleta(){
        int eleccion, opcion, vApostado, bandera;
        int apuesta[3];
        string reIntentar;
        opcion=0;
        do{
            bandera=0;
            srand(time(NULL));
            cout<<"Creditos actuales: "<<cTotales;
            cout<<"\n     +-------------------------------------+"<<endl;
            cout<<"     |Bienvenido a la ruleta millonaria (: |"<<endl;    
            cout<<"     +-------------------------------------+\n"<<endl;
            do
            {
                if(bandera==0){
                    cout<<"     Por favor ingrese el valor que desea apostar: ";
                    cin>>vApostado;
                }else{
                    cout<<"     Ingrese un valor valido: ";
                    cin>>vApostado;
                }
                
                
                if(vApostado>cTotales || vApostado<0){
                    bandera=1;
                }
            } while (vApostado>cTotales || vApostado<=0);
            
                

            cout<<"     Ingresa el numero al que deseas apostar: "<<endl;
            cin>>apuesta[0];
            cout<<"     ----------\n"<<endl;
            cout<<"     |1. JUGAR|"<<endl;
            cout<<"     |0. salir|"<<endl;
            cout<<"     ----------\n"<<endl;
            cout<<"     Ingrese el numero de opcion a elegir, si deseas girar la ruleta escribe Y, si deseas regresar al menu principal digita N ";
            cin>>eleccion;
            if (eleccion==1){
                opcion=marcoRuleta(apuesta[0], vApostado);
                if(opcion==1){
                    cout<<"\n       ERES EL GANADOR";
                    cTotales=cTotales+(vApostado*30);
                    cout<<"     Creditos actuales: "<<cTotales;
                    //main();
                }else{
                    cout<<"\n       Sigue intentando perdiste";
                    cTotales=cTotales-vApostado;
                    //main();
                }
            }
            if(eleccion==0){
                main();
            }
            cout<<"\n¿Desea volver a intentarlo? Y/N: ";
            cin>>reIntentar;
            if(cTotales==0){
                cout<<"\nEs imposible volver a jugar, por favor recargue nuevamente";
                reIntentar="N";
                Sleep(1500);
                
            }
        }while(reIntentar=="Y" || reIntentar=="y");
        main();
}

void plantilla1(int foto1){
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|     Bienvenido a la ruleta millonaria        |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
}
