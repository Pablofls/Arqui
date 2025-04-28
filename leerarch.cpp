//*
/* Autor: Felipe Rdz
 * Programa: Archivos 3
 * Objetivo: Gestionar archivos secuenciales en C++.
 * Fecha: 06 de Noviembre de 2024
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std ;
int eofcte;
string cuenta;
string nombre;
double saldo;
//* DeclaraciÃ³n del archivo Clients.txt en modo Input
ifstream inClientFile("clients.txt",ios::in);
/* Funcion : Abrir
 * Objetivo: Abrir archivo Clients.
*/
void abrir ()
{
    if (!inClientFile) 
    {
        cerr << "Archivo no pudo ser abierto" << endl;
        exit (EXIT_FAILURE);
    }
}
/* FunciÃ³n : Leer
 * Objetivo: Leer archivo Clients.
*/
void leer () 
{
    inClientFile >> cuenta >> nombre >> saldo;
    if (cuenta == "XXXXXX") {
        eofcte = 1;
    } else {
        eofcte = 0;
    }
}
/* FunciÃ³n : Cerrar
 * Objetivo: Cerrar archivo Clients.
*/
void cerrar () 
{
    inClientFile.close();    
}
/* FunciÃ³n : Main
 * Objetivo: Presentar en pantalla (registro a registro) archivo Clients.
*/


int main () 
{
    abrir ();
    leer ();
    while (eofcte != 1) {
        cout << cuenta << " " << nombre << " " << saldo << " " << endl;
        leer ();
    }
    cerrar ();
}