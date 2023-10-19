#include<iostream>
//#include<thread>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include <ctime>
#include <map>
#include <array>
#include <iterator>
#include <algorithm>



using namespace std;
int cTotales=5000;
int numeroRuleta(int n, int numero, int i);
int marcoRuleta(int numeroApostado, int cActuales);
void menuRuleta();
void gotoxy(int x,int y);
void plantilla1(int n);
main(){
    menuRuleta();
}
int numeroRuleta(int n, int numero, int i){
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
    Sleep(600);
    for(int i=0;i<resultado;i++){// hacer la animacion de la ruleta
        
        Sleep(100);
        system("cls");
        plantilla1(2);
        bandera=0;
        contador=0;
        contador2=30;

///////////////////////////////////////////////
        for(n=0;n<9;n++){
            gotoxy(28, 4+(n*2));
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
                    numeroRuleta(contador, Numero[contador], i);
                    
                    
                    
                }else{
                    if(n>=1){
                        if(n<=6){
                            contador2=contador2-1;
                            numeroRuleta((contador2), Numero[(contador2)], i);
                            cout<<"                         ";
                            if(n==5){
                                cout<<" ";
                            }
                            numeroRuleta(contador, Numero[contador], i);
                        }
                    }
                    if(n==7){
                        contador2=contador2-1;
                        numeroRuleta(contador2,Numero[contador2], i);
                        
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
            
            system("cls");
            bandera=0;
            srand(time(NULL));
            plantilla1(1);
            gotoxy(4,1);
            cout<<"C "<<cTotales;
            gotoxy(30, 4);
            cout<<"     Bienvenido a la ruleta millonaria\n"<<endl;    
            do
            {
                if(bandera==0){
                    gotoxy(28,7);
                    cout<<"Por favor ingrese el valor que desea apostar: ";
                    cin>>vApostado;
                }else{
                    
                    gotoxy(28,7);
                    cout<<"                                                  ";
                    gotoxy(28,7);
                    cout<<"Ingrese un valor valido: ";
                    cin>>vApostado;
                }
                
                
                if(vApostado>cTotales || vApostado<0){
                    bandera=1;
                }
            } while (vApostado>cTotales || vApostado<=0);
            bandera=0;
                
           
            do
            {
                if(bandera==0){
                    gotoxy(28,9);
                    cout<<"Ingresa el numero al que deseas apostar: ";
                    cin>>apuesta[0];
                }else{
                    
                    gotoxy(28,9);
                    cout<<"                                                  ";
                    gotoxy(28,9);
                    cout<<"Ingrese un valor valido entre 1 y 30: ";
                    cin>>apuesta[0];
                }
                
                
                if(apuesta[0]>30 || apuesta[0]<=0){
                    bandera=1;
                }
            } while (apuesta[0]>30 || apuesta[0]<=0);
            
            
            gotoxy(37, 11);
            cout<<"DESEA GIRAR LA RULETA Y/N: ";
            cin>>reIntentar;
            if (reIntentar=="Y" || reIntentar=="y"){
                opcion=marcoRuleta(apuesta[0], vApostado);
                if(opcion==1){
                    gotoxy(35, 35);
                    cout<<"\nERES EL GANADOR";
                    cTotales=cTotales+(vApostado*30);
                    cout<<"     Creditos actuales: "<<cTotales;
                    //main();
                }else{
                    gotoxy(35, 35);
                    cout<<"\nSigue intentando perdiste";
                    cTotales=cTotales-vApostado;
                    gotoxy(35, 38);
                    cout<<"\nCreditos actuales: "<<cTotales;
                    //main();
                }
            }else{
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

void plantilla1(int n){
    if(n==1){
        cout<<"                 "<<endl;
        cout<<"                 "<<endl;
        cout<<"    --------"<<endl;
        cout<<"                         +-----------------------------------------------------+"<<endl;
        cout<<"                         |                                                     |"<<endl;
        cout<<"                         |                                                     |"<<endl;
        cout<<"                         +-----------------------------------------------------+"<<endl;
        cout<<"                         |                                                     |"<<endl;
        cout<<"                         +---------------------------------------------------- +"<<endl;
        cout<<"                         |                                                     |"<<endl;
        cout<<"                         -------------------------------------------------------"<<endl;
        cout<<"                         |                                                     |"<<endl;
        cout<<"                         -------------------------------------------------------"<<endl;
    }
    if(n==2){
        
        cout<<"\n\n\n                          /---------------------------------------------------+"<<endl;
        cout<<"                         /                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;                    
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         *                                    *"<<endl;
        cout<<"                         +------------------------------------+"<<endl;

    }
/*                                      30  16  9  6  11  19  15  7  8

                                        24                           25

                                        12                           17

                                        26                           10

                                        23                           29

                                        4                            18

                                        13                           27

                                        20  3  28  21  2  22  14  1  5*/
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
