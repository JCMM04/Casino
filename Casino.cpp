#include <iostream>
#include <ctime>
#include <map>
#include <array>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <windows.h> 

using namespace std;

//variables globales
int saldo=0;
int valorMasoJugador = 0;
int valorMasoCrupier = 0;
int AsDelMaso=0;
string cartaActual;
string barajaMaso[52];
string barajaPartida[52];


void menu();
string cartaAlAzar();
int valorMaso(string carta, int valorDelMaso);
int calcularSaldo(double apuesta, bool resultado);
double validarApuestas(double monto);
void SinSaldo();
void validarSaldo();
void gotoxy(int x,int y);
void imprimirMarco(int opcion);

main(){
    menu();
}

void menu(){
    system("cls"); //Borra lo anterior en la consola
    int opcionMenu;

    imprimirMarco(1);
    gotoxy(13,1);
    cout<<"Bienvenido al Casino!"<<endl;

    if(saldo<=0){
        gotoxy(2,3);
        cout<<"Ingrese su saldo inicial ->"<<endl;
        gotoxy(30,3);
        cin>>saldo;
        validarSaldo();
    }else{
        gotoxy(2,3);
        cout<<"Su saldo actual es: "<<saldo<<endl;
    }
    gotoxy(1,5);
    cout << "Selecciona un juego:" << endl;
    gotoxy(1,6);
    cout << "1. Ruleta" << endl;
    gotoxy(1,7);
    cout << "2. Blackjack" << endl;
    gotoxy(1,8);
    cout << "3. Datos y Saldo"<<endl;
    gotoxy(1,9);
    cout << "0. Salir"<<endl;
    gotoxy(1,10);
    cout << "Ingresa tu eleccion:"<<endl;
    gotoxy(22,10);
    cin >> opcionMenu;
    
    switch (opcionMenu) {
        case 1:
            cout << "Iniciar el juego de Ruleta..." << endl;
            // Agrega la lógica para el juego de Ruleta aquí
            break;
        case 2:
            char generarCarta;
            double apuesta;
            char nuevaRonda;
           
            do{
                valorMasoCrupier=0;
                valorMasoJugador=0;
                AsDelMaso=0;

                for(int i=0; i<52; i++){
                    barajaMaso[i]="";
                }
                for(int i=0; i<52; i++){
                    barajaPartida[i]="";
                }
                
                system("cls");
                //SinSaldo();
                imprimirMarco(2);
                gotoxy(10,1);
                cout<<"...Bienvenido a Blackjack..."<<endl;
                gotoxy(2,3);
                cout<<"Su saldo actual es: "<<saldo<<endl;
                gotoxy(2,5);
                cout<<"Ingrese su apuesta: "<<endl;
                gotoxy(21,5);
                cin>>apuesta;
                apuesta = validarApuestas(apuesta);
                gotoxy(2,6);
                cout << "El crupier debe plantarse en 17 y robar en 16"<<endl;
                gotoxy(15,8);
                cout << "MASO DEL CRUPIER"<<endl;
                valorMasoCrupier=valorMaso(cartaAlAzar(),valorMasoCrupier);
                gotoxy(2,9);
                cout<<cartaActual<<endl;
                gotoxy(2,10);
                cout<<"CARTA OCULTA"<<endl;
                gotoxy(15,12);
                cout<<"MASO DEL JUGADOR"<<endl;
                valorMasoJugador=valorMaso(cartaAlAzar(),valorMasoJugador);
                gotoxy(2,13);
                cout<<cartaActual<<endl;
                int generadorMaso=14;
                do{
                    valorMasoJugador=valorMaso(cartaAlAzar(),valorMasoJugador);
                    gotoxy(2,generadorMaso);
                    generadorMaso++;
                    cout<<cartaActual<<endl;
                    gotoxy(25,13);
                    cout<<"Valor del maso: "<<valorMasoJugador<<endl;
                    if(valorMasoJugador<21){
                        gotoxy(24,15);
                        cout<<"Desea coger una carta"<<endl; 
                        gotoxy(24,16);
                        cout<<"del maso, (S/N) -> ";
                        cin>>generarCarta;
                    }
                }while((generarCarta=='s' || generarCarta=='S') && valorMasoJugador<21);
                
                imprimirMarco(3);

                if(valorMasoJugador>21){
                    gotoxy(51,12);
                    cout<<"TE HAS PASADO, HAS PERDIDO ESTA RONDA"<<endl;
                    gotoxy(51,14);
                    cout<<"Tu apuesta: "<<apuesta<<endl;
                    gotoxy(51,15);
                    cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,false)<<endl;
                }else{
                    imprimirMarco(4);
                    gotoxy(62,1);
                    cout<<"...JUGANDO EL CRUPIER..."<<endl;
                    int generadorMaso=3;
                    do{
                        valorMasoCrupier=valorMaso(cartaAlAzar(),valorMasoCrupier);
                        gotoxy(51,generadorMaso);
                        generadorMaso++;
                        cout<<cartaActual<<endl;
                        gotoxy(2,10);
                        cout<<"                  "<<endl;
                    }while(valorMasoCrupier<17);
                    gotoxy(66,3);
                    cout<<"Valor del maso del crupier: "<<valorMasoCrupier<<endl;
                    if(valorMasoCrupier<=21){
                        if(valorMasoJugador>valorMasoCrupier){
                            gotoxy(51,12);
                            cout<<"HAS GANADO ESTA RONDA"<<endl;
                            gotoxy(51,14);
                            cout<<"Tu apuesta: "<<apuesta<<endl;
                            gotoxy(51,15);
                            cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,true)<<endl;
                        }else if(valorMasoJugador<valorMasoCrupier){
                            gotoxy(51,12);
                            cout<<"HAS PERDIDO ESTA RONDA"<<endl;
                            gotoxy(51,14);
                            cout<<"Tu apuesta: "<<apuesta<<endl;
                            gotoxy(51,15);
                            cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,false)<<endl;
                        }else{
                            gotoxy(51,12);
                            cout<<"HAS EMPATADO ESTA RONDA"<<endl;
                            gotoxy(51,14);
                            cout<<"Tu apuesta: "<<apuesta<<endl;
                            gotoxy(51,15);
                            cout<<"Tu nuevo saldo es: "<<saldo<<endl;
                        }
                    }else{
                        gotoxy(51,12);
                        cout<<"HAS GANADO ESTA RONDA"<<endl;
                        gotoxy(51,14);
                        cout<<"Tu apuesta: "<<apuesta<<endl;
                        gotoxy(51,15);
                        cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,true)<<endl;
                    }
                }
                if(saldo<=0){
                    int nuevoSaldo;
                    gotoxy(75,14);
                    cout<<"Debes ingresar"; 
                    gotoxy(75,15);
                    cout<<"un nuevo saldo";
                    gotoxy(51,17);
                    cout<<"1.Ingresar saldo / 2.Salir del casino -> "<<endl;
                    gotoxy(92,17);
                    cin>>nuevoSaldo;
                    if(nuevoSaldo==2){
                        gotoxy(0,20);
                        cout<<"Saliendo del casino, vuelva pronto...";
                        exit(3);
                    }
                }else{
                    gotoxy(51,17);
                    cout<<"Desea jugar una nueva ronda (S/N) -> "<<endl;
                    gotoxy(88,17);
                    cin>>nuevaRonda;
                }
            }while((nuevaRonda=='S' || nuevaRonda=='s') && saldo>0);
            menu();
            break;
        case 0:
            gotoxy(0,13);
            cout << "Saliendo del Casino. Hasta pronto!" << endl;
            break; // Salir del programa
        default:
            cout << "Opción no válida. Por favor, elige una opción válida." << endl;
            break;
    }
}
string cartaAlAzar(){
    const string cartas[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const string palos[] = {"Picas", "Corazon", "Diamante", "Trebol"};
    bool cartaRepetida;
    int indiceCarta;
    int indicePalo;

    //Evita repetir una carta y se almacena en el array baraja
    do{
        // Generar números aleatorios para seleccionar una carta y un palo
        srand(time(NULL));
        indiceCarta = rand() % 13;
        indicePalo = rand() % 4;
        int posicionBaraja = 0;

        //Recorre el array en busca de cartas iguales
        for( posicionBaraja = 0; posicionBaraja <52 ; posicionBaraja++){
            if(!barajaMaso[posicionBaraja].empty()){ //determina si el espacio esta vacio, de ser asi se sale
                if ((cartas[indiceCarta]+palos[indicePalo])==barajaMaso[posicionBaraja]){
                    cartaRepetida=true;
                    break;
                }else{
                    cartaRepetida=false;
                }
            }else{
                if(!cartaRepetida){
                    barajaMaso[posicionBaraja] = (cartas[indiceCarta]+palos[indicePalo]);
                    barajaPartida[posicionBaraja]=cartas[indiceCarta];
                }
                break;
            }
        }
    }while(cartaRepetida);

    // Mostrar la carta seleccionada al azar
    cartaActual = (cartas[indiceCarta] +" de "+ palos[indicePalo]);
    return cartas[indiceCarta];
}
int valorMaso(string carta, int valorDelMaso)
{
    int AsEncontrados = 0;
    map<string, int> valores = {
        {"2", 2}, 
        {"3", 3}, 
        {"4", 4}, 
        {"5", 5}, 
        {"6", 6},
        {"7", 7}, 
        {"8", 8}, 
        {"9", 9}, 
        {"10", 10}, 
        {"J", 10},
        {"Q", 10}, 
        {"K", 10}
    };
    if(carta=="A"){
        if((valorDelMaso+11)>21){
            valores["A"] = 1;
            AsDelMaso++;
        }else{
            valores["A"]= 11;
        }
    }

    valorDelMaso+=valores[carta];

    for(int i=0; i<52 ; i++){
        if(valorDelMaso>21){
            if(!barajaPartida[i].empty()){
                if(barajaPartida[i]=="A"){
                    AsEncontrados++;
                    if(AsEncontrados>AsDelMaso){
                        valorDelMaso-=10;
                        AsDelMaso++;
                    }
                }
            }else{
                break;
            }
        }else{
            break;
        }
    }

    return valorDelMaso;
}
int calcularSaldo(double apuesta, bool resultado){
    if(resultado){
        apuesta*=2;
        saldo+=apuesta;
    }else{
        saldo-=apuesta;
    }
    return saldo;
}
double validarApuestas(double monto){
    bool montoInvalido = true;
    do{
        if(monto<=0){
            gotoxy(49,5);
            cout<<"Monto invalido, ingrese una suma mayor a 0$ y menor a su saldo: "<<saldo<<"$"<<endl;
            gotoxy(21,5);
            cout<<"              ";
            gotoxy(21,5);
            cin>>monto;
        }else{
            if(monto<=saldo){
                montoInvalido=false;
            }else{
                gotoxy(49,5);
                cout<<"                                                                            ";
                gotoxy(49,5);
                cout<<"Ingrese un valor menor o igual a su saldo: "<<saldo<<"$"<<endl;
                gotoxy(21,5);
                cout<<"              ";
                gotoxy(21,5);
                cin>>monto;
            }
        }
    }while(montoInvalido);
    gotoxy(49,5);
    cout<<"                                                                            ";
    return monto;
}
void SinSaldo(){
    int continuar;
    if(saldo<=0){
        cout<<"Su saldo es 0$"<<endl;
        cout<<"1. Ingresar nuevo saldo"<<endl;
        cout<<"2. Salir del casino"<<endl;
        cin>>continuar;
        if(continuar==1){
            cout<<"Ingrese su nuevo saldo: "<<endl;
            cin>>saldo;
            validarSaldo();
        }else if (continuar==2){
            exit(3);
        }
    }
}
void validarSaldo(){
    bool saldoInvalido = true;
    do{
        if(saldo<=0){
            gotoxy(49,3);
            cout<<"Ingrese un saldo mayor a 0$: "<<endl;
            gotoxy(30,3);
            cout<<"                ";
            gotoxy(30,3);
            cin>>saldo;
        }else{
            saldoInvalido = false;
        }
    }while(saldoInvalido);
    gotoxy(49,3);
    cout<<"                             ";
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
void imprimirMarco(int opcion){
    if(opcion==1){
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
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
    }else if(opcion == 2){
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
        cout<<"|                                              |"<<endl;
        cout<<"|                    |                         |"<<endl;
        cout<<"|                    |                         |"<<endl;
        cout<<"|                    |                         |"<<endl;
        cout<<"|                    |                         |"<<endl;
        cout<<"|                    |                         |"<<endl;
        cout<<"|                    |                         |"<<endl;
        cout<<"+----------------------------------------------+"<<endl;
    }else if(opcion== 3){
        gotoxy(50,11);
        cout<<"+----------------------------------------------+"<<endl;
        gotoxy(50,12);
        cout<<"|                                              |"<<endl;
        gotoxy(50,13);
        cout<<"+----------------------------------------------+"<<endl;
        gotoxy(50,14);
        cout<<"|                                              |"<<endl;
        gotoxy(50,15);
        cout<<"|                                              |"<<endl;
        gotoxy(50,16);
        cout<<"+----------------------------------------------+"<<endl;
        gotoxy(50,17);
        cout<<"|                                              |"<<endl;
        gotoxy(50,18);
        cout<<"+----------------------------------------------+"<<endl;
    }else if(opcion==4){
        gotoxy(50,0);
        cout<<"+----------------------------------------------+"<<endl;
        gotoxy(50,1);
        cout<<"|                                              |"<<endl;
        gotoxy(50,2);
        cout<<"+----------------------------------------------+"<<endl;
        gotoxy(50,3);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,4);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,5);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,6);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,7);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,8);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,9);
        cout<<"|              |                               |"<<endl;
        gotoxy(50,10);
        cout<<"|              |                               |"<<endl;
        
    }
}
