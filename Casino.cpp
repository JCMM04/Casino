#include <iostream>

using namespace std;

void menu();

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
            cout << "Iniciar el juego de Blackjack..." << endl;
            // Agrega la lógica para el juego de Blackjack aquí
            break;
        case 0:
            cout << "Saliendo del Casino. ¡Hasta pronto!" << endl;
            break; // Salir del programa
        default:
            cout << "Opción no válida. Por favor, elige una opción válida." << endl;
            break;
    }
}