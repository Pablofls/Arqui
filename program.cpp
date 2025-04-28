/*
#Program: Personnel Management
#Objective: Modify personnel...
#Author: Pablo Flores Rodriguez
#Author: Ethan Rivera Saldivar
#Author:Christopher Reeker Sireno
#Author:Arturo Vargas Espinosa
#Date: April 25th, 2025
#Class: Arquitectura de software.
#Honor pledge: We hereby affirm that we have done this activity with academic integrity.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//DECLARACION DE ARCHIVOS
ifstream movements("movements.csv");
ifstream personnel("personnel.csv");
ifstream newPersonnel("newpersonnel.csv");

//VERIFICAR ARCHIVOS
void openFiles(){
    if (!movements) 
    {
        cerr << "Movements file is not available" << endl;
        exit (EXIT_FAILURE);
    }
    if (!personnel) 
    {
        cerr << "Personnel file is not available" << endl;
        exit (EXIT_FAILURE);
    }
    if (!newPersonnel) 
    {
        cerr << "New Personnel file us not available" << endl;
        exit (EXIT_FAILURE);
    }
}

//LEER ARCHIVOS
void movimientosTrabajador(){
}

//ALTA DE UN TRABAJADOT
void registerEmployee(){
}

//BAJA DE UN TRABAJADOR
void deleteEmployee(){
}

//CAMBIO DE UN TRABAJADOR
void changeEmployee(){
}


int main(){
    openFiles();
    
    return 0;
}
