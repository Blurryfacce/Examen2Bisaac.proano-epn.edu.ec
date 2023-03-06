#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include "..\lib\ipcolor.h"
#include "..\lib\iploading.h"
#include <windows.h>

using namespace std;

const string IONOMBRE_COMPLETO = {"Isaac Joshua Proano Zambrano"};
const int IOCEDULA = 175575709;
struct coordenada
{
    int capacidadBelica;
    string geoloc, detalleArs;

};
void ioLecturaarchivo(string ionombre);
int main()
{

    ioLecturaarchivo("files/datos.txt");

    return 0;
}
void ioLecturaarchivo(string ionombre) {
  
    string texto;
    int num_linea = 0;
    vector<string> coordenadas_validas;

    ifstream archivo(ionombre);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << ionombre << endl;
        return;
    }

    while (getline(archivo, texto)) {
        cout << "Presentando datos: " << (num_linea * 100 / 10) << "%\r";
        cout.flush();
        num_linea++;

        size_t pos1 = texto.find(",");
        size_t pos2 = texto.find(",", pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos || pos2 == texto.length() - 1) {
            cout << "\033[31mError en la línea " << num_linea << ": no es una coordenada válida.\033[0m" << endl;
            continue;
        }

        string cap = texto.substr(0, pos1);
        string geo = texto.substr(pos1 + 1, pos2 - pos1 - 1);
        string tipo_arsenal = texto.substr(pos2 + 1);

        string coordenada = cap + "," + geo + "," + tipo_arsenal;
        if (find(coordenadas_validas.begin(), coordenadas_validas.end(), coordenada) != coordenadas_validas.end()) {
            continue;
        }

        coordenadas_validas.push_back(coordenada);
        io_loading();
        cout << "  \033[32m" << cap << ", " << geo << ", " << tipo_arsenal << "\033[0m" << endl;
    }

    
    archivo.close();

}
