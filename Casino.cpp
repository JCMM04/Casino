#include <iostream>
#include <ctime>
#include <map>
#include <array>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

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

main(){
    menu();
}

void menu(){
    system("cls"); //Borra lo anterior en la consola
    int opcionMenu;
    
    cout << "¡Bienvenido al Casino!" <<endl;

    if(saldo<=0){
        cout << "Ingrese su saldo inicial: "<<endl;
        cin>>saldo;
        validarSaldo();
    }else{
        cout<<"Su saldo actual es: "<<saldo<<endl;
    }
    
    cout << "Selecciona un juego:" << endl;
    cout << "1. Ruleta" << endl;
    cout << "2. Blackjack" << endl;
    cout << "3. Datos y Saldo"<<endl;
    cout << "0. Salir" << endl;

    cout << "Ingresa tu elección: ";
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
                SinSaldo();
                cout << "Bienvenido a Blackjack..." << endl;
                cout<<"Su saldo actual es: "<<saldo<<endl;
                cout << "Ingrese su apuesta: "<<endl;
                cin>>apuesta;
                apuesta = validarApuestas(apuesta);
                
                cout << "El crupier debe plantarse en 17 y robar en 16..."<<endl;
                cout << "-------------------------------------------------"<<endl;
                cout << "Maso del crupier..."<<endl;
                valorMasoCrupier=valorMaso(cartaAlAzar(),valorMasoCrupier);
                cout<<cartaActual<<endl;
                cout<<"CARTA OCULTA"<<endl;
                cout<<"---------------------------------------------------"<<endl;
                cout<<"Maso incial de jugador... "<<endl;
                valorMasoJugador=valorMaso(cartaAlAzar(),valorMasoJugador);
                cout<<cartaActual<<endl;
                
                do{
                    valorMasoJugador=valorMaso(cartaAlAzar(),valorMasoJugador);
                    cout<<cartaActual<<endl;
                    cout<<"Valor del maso: "<<valorMasoJugador<<endl;
                    if(valorMasoJugador<21){
                        cout<<"Desea coger una carta del maso, (S/N): ";
                        cin>>generarCarta;
                    }
                }while((generarCarta=='s' || generarCarta=='S') && valorMasoJugador<21);
                cout<<"--------------------------------------------------"<<endl;
                if(valorMasoJugador>21){
                    cout<<"TE HAS PASADO, HAS PERDIDO ESTA RONDA"<<endl;
                    cout<<"Tu apuesta: "<<apuesta<<endl;
                    cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,false)<<endl;
                }else{
                    cout<<"JUGANDO EL CRUPIER..."<<endl;
                    do{
                        valorMasoCrupier=valorMaso(cartaAlAzar(),valorMasoCrupier);
                        cout<<cartaActual<<endl;
                    }while(valorMasoCrupier<17);
                    cout<<"Valor del maso del crupier: "<<valorMasoCrupier<<endl;

                    if(valorMasoCrupier<=21){
                        if(valorMasoJugador>valorMasoCrupier){
                            cout<<"HAS GANADO ESTA RONDA"<<endl;
                            cout<<"Tu apuesta: "<<apuesta<<endl;
                            cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,true)<<endl;
                        }else if(valorMasoJugador<valorMasoCrupier){
                            cout<<"HAS PERDIDO ESTA RONDA"<<endl;
                            cout<<"Tu apuesta: "<<apuesta<<endl;
                            cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,false)<<endl;
                        }else{
                            cout<<"HAS EMPATADO ESTA RONDA"<<endl;
                            cout<<"Tu apuesta: "<<apuesta<<endl;
                            cout<<"Tu nuevo saldo es: "<<saldo<<endl;
                        }
                    }else{
                        cout<<"HAS GANADO ESTA RONDA"<<endl;
                        cout<<"Tu apuesta: "<<apuesta<<endl;
                        cout<<"Tu nuevo saldo es: "<<calcularSaldo(apuesta,true)<<endl;
                    }
                }
                cout<<"Desea jugar una nueva ronda (S/N): "<<endl;
                cin>>nuevaRonda;
            }while(nuevaRonda=='S' || nuevaRonda=='s');
            menu();
            break;
        case 0:
            cout << "Saliendo del Casino. ¡Hasta pronto!" << endl;
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
            cout<<"Monto invalido, ingrese una suma mayor a 0$ y menor a su saldo: "<<saldo<<"$"<<endl;
            cin>>monto;
        }else{
            if(monto<=saldo){
                montoInvalido=false;
            }else{
                cout<<"Ingrese un valor menor o igual a su saldo: "<<saldo<<"$"<<endl;
                cin>>monto;
            }
        }
    }while(montoInvalido);
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
        if(saldo<0){
            cout<<"Ingrese un saldo mayor a 0$: "<<endl;
            cin>>saldo;
        }else{
            saldoInvalido = false;
        }
    }while(saldoInvalido);
}
