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
    
    int ioCapacidadBelica;
    string ioGeoloc, ioDetalleArs;
    coordenada *der;
    coordenada *izq;

};
struct nodo
{
    int dato;
    nodo *der;
    nodo *izq;
};

nodo *ioCrear_Nodo(int);
nodo *ioArbol = NULL;
void ioInsertarNodo(nodo *&, int);


void ioLecturaarchivo(string ionombre);
void datos();
int main()
{
    cout<<BLUE"[+] Leyendo coordenadas..."<<endl;
    ioLecturaarchivo("files/datos.txt");
    cout<<"\n";
    datos();

    return 0;
}
nodo *ioCrearNodo(int n)
{
    nodo *nuevo_nodo = new nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}
void ioInsertarNodo(nodo *&ioArbol, int n)
{
    if (ioArbol == NULL)
    {
        nodo *nuevo_nodo = ioCrearNodo(n);
        ioArbol = nuevo_nodo;
    }
    else
    {
        int valorRaiz = ioArbol->dato;
        if (n<valorRaiz)
        {
            ioInsertarNodo(ioArbol->izq,n);
        }
        else{
            ioInsertarNodo(ioArbol->der,n);
        }
        
    }

    


}
void ioLecturaarchivo(string ionombre) {
  
    string ioTexto;
    int ioNum_linea = 0;
    vector<string> coordenadas_validas;

    ifstream archivo(ionombre);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << ionombre << endl;
        return;
    }

    while (getline(archivo, ioTexto)) {
        cout << "Presentando datos: " << (ioNum_linea * 100 / 10) << "%\r";
        cout.flush();
        ioNum_linea++;

        size_t pos1 = ioTexto.find(",");
        size_t pos2 = ioTexto.find(",", pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos || pos2 == ioTexto.length() - 1) {
            cout << "\033[31mError en la línea " << ioNum_linea << ": no es una coordenada válida.\033[0m" << endl;
            continue;
        }

        string cap = ioTexto.substr(0, pos1);
        string geo = ioTexto.substr(pos1 + 1, pos2 - pos1 - 1);
        string tipo_arsenal = ioTexto.substr(pos2 + 1);

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
void datos()
{
    cout<<BLUE<<"\n\n[+] Informacion Arbol Binario de capacidad belica Ucraniana "<<endl;
    cout<<GRAY<<"Developer-Nombre: "<<IONOMBRE_COMPLETO<<endl;
    cout<<"Developer-Cedula: "<<IOCEDULA<<endl;


}