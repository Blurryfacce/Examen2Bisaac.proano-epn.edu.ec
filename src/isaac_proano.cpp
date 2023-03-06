#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "..\lib\ipcolor.h"

using namespace std;

const string IONOMBRE_COMPLETO = {"Isaac Joshua Proano Zambrano"};
const int IOCEDULA = 175575709;
// struct coordenada
// {
//     int capacidadBelica;
//     string geoloc, detalleArs;

// };
void ioLecturaarchivo()
{
    ifstream archivo;
    string texto;

    archivo.open("coord.txt",ios::in);

    if(archivo.fail())
    {
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    
    archivo.close();


}
int main()
{

    ioLecturaarchivo();


    return 0;
}
