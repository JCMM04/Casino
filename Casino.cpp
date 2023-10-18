#include <iostream>
#include <ctime>
#include <map>

using namespace std;

//variables globales
int valorMasoJugador = 0;
int valorMasoCrupier = 0;
int AsDelMaso=0;
string cartaActual;
string barajaMaso[52];
string barajaPartida[52];


void menu();
string cartaAlAzar();
int valorMaso(string carta, int valorDelMaso);

main(){
    menu();
}

void menu(){
    system("cls"); //Borra lo anterior en la consola
    int opcionMenu;

    cout << "¡Bienvenido al Casino!" << endl;
    cout << "Selecciona un juego:" << endl;
    cout << "1. Ruleta" << endl;
    cout << "2. Blackjack" << endl;
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
            cout << "Bienvenido a Blackjack..." << endl;
            cout << "El crupier debe plantarse en 17 y robar en 16..."<<endl;
            cout << "-------------------------------------------------"<<endl;
            cout << "Maso del crupier..."<<endl;
            valorMasoCrupier=valorMaso(cartaAlAzar(),valorMasoCrupier);
            cout<<cartaActual<<endl;
            cout<<"CALTA OCULTA"<<endl;
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
            }else{
                cout<<"JUGANDO EL CRUPIER..."<<endl;
                do{
                    valorMasoCrupier=valorMaso(cartaAlAzar(),valorMasoCrupier);
                    cout<<cartaActual<<endl;
                }while(valorMasoCrupier<17);
                cout<<"Valor del maso del crupier: "<<valorMasoCrupier;
            }
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
