#include <iostream>
#include <ctime>
#include <map>

using namespace std;

void menu();
string cartaAlAzar();
int valorMaso();

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
            cout<<"Carta incial... "<<endl;
            do{
                cout<<"El valor del maso es: "<<valorMaso(cartaAlAzar());
                cout<<"Desea coger una carta del maso, (S/N): ";
                cin>>generarCarta;
            }while(generarCarta=='s' || generarCarta=='S');
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
    string baraja[52];
    bool cartaRepetida = true;
    int indiceCarta;
    int indicePalo;

    //Evita repetir una carta y se almacena en el array baraja
    do{
        // Generar números aleatorios para seleccionar una carta y un palo
        int indiceCarta = rand() % 13;
        int indicePalo = rand() % 4;

        //Recorre el array en busca de cartas iguales
        for(int i = 0; i <52 ; i++){
            if(!baraja[i].empty()){ //determina si el espacio esta vacio, de ser asi se sale
                if ((cartas[indiceCarta]+palos[indicePalo])==baraja[i]){
                    cartaRepetida=true;
                    break;
                }else{
                    cartaRepetida=false;
                    break;
                }
            }else{
                baraja[i] = (cartas[indiceCarta]+palos[indicePalo]);
                break;
            }
        }
    }while(cartaRepetida);

    // Mostrar la carta seleccionada al azar
    cout << "Carta: " << cartas[indiceCarta] <<" de "<< palos[indicePalo] << endl;
    return cartas[indiceCarta];
}
int valorMaso(string carta){
    int valorMaso;
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
    if((valorMaso+11)>21){
        valores["A"] = 1;
    }else{
        valores["A"]= 11;
    }
    valorMaso+=valores[carta];
    return valorMaso;
}
