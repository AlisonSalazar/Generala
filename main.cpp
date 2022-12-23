#include <iostream>
#include <ctime>
#include <stdio.h>
#include <windows.h>
#define today 20221107
using namespace std;
struct jugador{
    string nombre;
    int id_jugada;
    int fecha;
    int puntaje;
};
struct celdas{
     int dado[6];
     int numeros[6];
     bool e=false;
     bool f=false;
     bool p=false;
     bool g=false;
     bool dg=false;
     jugador datos_jugador;
 };
void iniciar_juego();
int menu();
int tirar(int[]);
void mostrar_dado(int[]);
void mostrar_tabla(celdas);
void empezar(int, celdas[]);
void jugar(int);
int main()
{
    celdas player;
    setlocale(LC_ALL,"spanish");
    //mostrar_tabla(player);
    iniciar_juego();
    return 0;
}
void iniciar_juego()
{
    cout <<"\t ___  ___  __  _  ___  ___   __       __"<<endl;
    cout <<"\t|  _ |___  ||  | |___ |___| |__| |   |__|"<<endl;
    cout <<"\t|___||___  | |_| |___ | |   |  | |__ |  |\n"<<endl;
    system("pause");
    system("cls");
    int op = menu();
    while(op!=4)
    {
        jugar(op);
        op = menu();
    }
    cout<<"\n\t GAME OVER"<<endl;

}
void llenar_dato(celdas player)
{
    cout<<"Ingrese nombre del jugador: ";
    cin>>player.datos_jugador.nombre;
}
void get_date(celdas players[], int cantidad)
{
    for(int i=0 ; i<cantidad; i++)
    {
        llenar_dato(players[i]);
    }
}
void jugar(int tipo)
{
    switch(tipo)
    {
    case 1:
        celdas player;
        break;
    case 2:
        celdas players[2];
        get_date(players);
        break;
    case 3:
        int cant_jug;
        cout<<"\tIngrese la cantidad de jugadores a participar"<<endl;
        cin>>cant_jug;
        celdas players = new celdas[cant_jug];
        get_date(players);
        break;
    }
    cout<<"Hola estoy jugando";
}
void mostrar_tabla(celdas player)
{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hc, 2);
    cout<<"\t<<<<<<<<<<<<<<<<<<<<<<< "<<player.datos_jugador.nombre<<" >>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    SetConsoleTextAttribute(hc, 6);
    cout<<"\t|   1   |   2   |   3   |   4   |   5   |   6   |"<<endl;
    SetConsoleTextAttribute(hc, 5);
    cout<<"\t";
    mostrar_dado(player.numeros);
    cout<<endl;
    SetConsoleTextAttribute(hc, 6);
    cout<<"\t| Escalera |  Full  | Poker | Generala | Doble Generala |"<<endl;
    SetConsoleTextAttribute(hc, 5);
    cout<<"\t      "<<player.e<<"         "<<player.f<<"       "<<player.p<<"         "<<player.g<<"             "<<player.dg<<endl;
    SetConsoleTextAttribute(hc, 7);
}

int menu(){
    int op;
    cout<<"1) Un jugador"<<endl;
    cout<<"2) Dos jugadores"<<endl;
    cout<<"3) Multijugador"<<endl;
    cout<<"4) Quit"<<endl;
    cin>>op;
    return op;
}

void mostrar_dado(int dado[])
{
    cout<<"    "<<dado[0]<<"       "<<dado[1]<<"       "<<dado[2]<<"       "<<dado[3]<<"       "<<dado[4]<<"       "<<dado[5]<<endl;
}
int tirar(int juego[6])
{
    for(int i = 0; i<6 ; i++)
    {
        juego[i] = 1+(rand()%6);
    }
    return 1+(rand()%3);
}


