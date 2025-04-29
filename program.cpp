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
ifstream movements("movements.txt");
ifstream personnel("personnel.csv");
ofstream newPersonnel("newpersonnel.csv");
ofstream writeMovements("writeMovements.txt");



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
/***************** GLOBAL VARIABLES *******************/
//Variables for Movement Archive
char moveTypeMovements;
string workerMovements;
string groupMovements;
string companyMovements;
string plantMovements;
string departmentMovements;
string cveMovements;
string nameMovements;
int baseSalaryMovements;
string hireDateMovements;

//Variables for Personnel Archive
string workerPersonnel;
string groupPersonnel;
string companyPersonnel;
string plantPersonnel;
string departmentPersonnel;
string cvePersonnel;
string namePersonnel;
int baseSalaryPersonnel;
string hireDatePersonnel;

//Variables for New Personnel Archive
string workerNewPersonnel;
string groupNewPersonnel;
string companyNewPersonnel;
string plantNewPersonnel;
string departmentNewPersonnel;
string cveNewPersonnel;
string nameNewPersonnel;
int baseSalaryNewPersonnel;
string hireDateNewPersonnel;

bool existe=false;
string systemDate="4/29/2025";
/***************** READ ARCHIVES *******************/
//Read Personnel Movement Archive
void readMovement(){
    while ( movements >> moveTypeMovements >> workerMovements >> groupMovements >> companyMovements >> plantMovements >> departmentMovements >> cveMovements >> nameMovements >> baseSalaryMovements >> hireDateMovements){
        cout << moveTypeMovements << " " << workerMovements << " " << groupMovements << " "  << companyMovements << " "  << plantMovements << " "  << departmentMovements << " "  << cveMovements << " "  << nameMovements << " " << baseSalaryMovements << " " << hireDateMovements << endl;
    }

}

//Read personal archive
void readPersonnel(){
    while (personnel >> workerPersonnel >> groupPersonnel >> companyPersonnel >> plantPersonnel >> departmentPersonnel >> cvePersonnel >> namePersonnel >> baseSalaryPersonnel >> hireDatePersonnel) {
        cout << workerPersonnel << " " << groupPersonnel << " " << companyPersonnel << " " << plantPersonnel << " " << departmentPersonnel << " " << cvePersonnel << " " << namePersonnel << " " << baseSalaryPersonnel << " " << hireDatePersonnel << endl;
    }

}

/***************** ABORT *******************/


/*
La acción de abortar por archivos desordenados, se debe
realizar en el módulo que lee y sugiero que se detecte al 
momento de que el trabajador leído sea menor al anterior.
*/
//Aborts porgram (ETHAN)
/*void abort(){
    //Abort
}*/

/***************** FINAL REPORT *******************/

//Write Report
void writeReport(){
    //Impresion de como se veria el reporte
}

/***************** CONTROL PROGRAM *******************/

void controlProgram(){
    //Modulo de control (ETHAN)
}


/***************** PERSONNEL MOVEMENTS *******************/
void personnelCopy(){
    newPersonnel << workerPersonnel << ", " 
    << groupPersonnel << ", "
    << companyPersonnel << ", "
    << plantPersonnel << ", "
    << departmentPersonnel << ", "
    << cvePersonnel << ", "
    << namePersonnel << ", "
    << baseSalaryPersonnel << ", "
    << hireDatePersonnel;
}

void personnelMovements(){
    
    //Same Keys
    if (workerMovements == workerPersonnel){
        switch (moveTypeMovements)
        {
        //Invalid Register
        case 'A':
            //Call COPY
            break;
        
        //Invalid Dismiss
        case 'B':
            //Call Dismiss (Baja)
            break;
        
        //Valid Change
        case 'C':
            //Call Change
            break;
        
        default:
            cout << "Fail on recognizign movement type" << endl;
            break;

        readMovement();
        readPersonnel();
        }
    
    } else if (workerMovements < workerPersonnel){ 
        switch (moveTypeMovements)
        {
        //Valid Register
        case 'A':
            //Call COPY
            break;
        
        //Invalid Dismiss
        case 'B':
            //Call Dismiss (Baja)
            break;
        
        //Invalid Change
        case 'C':
            //Call Change
            break;
        
        default:
            cout << "Fail on recognizign movement type" << endl;
            break;
        
        readMovement();
        }

    } else {
        //Call COPY
        readPersonnel();
    }
}

//ALTA DE UN TRABAJADOR
/*
No es necesario en Alta validar si el trabajador existe. 
*/
void registerEmployee(){
    if(existe){
        cout<<"ALTA INVALIDA"<<endl;
        personnelCopy();
    } else{
        if(groupMovements==""){
            companyNewPersonnel="000";
        } else{
            groupNewPersonnel=groupMovements;
        }
        if(companyMovements==""){
            companyNewPersonnel="000";
        } else{
            companyNewPersonnel=companyMovements;
        }
        if(plantMovements==""){
            plantNewPersonnel="000";
        } else{
            plantNewPersonnel=plantMovements;
        }
        if(departmentMovements==""){
            departmentNewPersonnel="000000";
        } else{
            departmentNewPersonnel=departmentMovements;
        }
        if(cveMovements==""){
            cveNewPersonnel="0";
        } else{
            cveNewPersonnel=cveMovements;
        }
        if(nameMovements==""){
            nameNewPersonnel="0";
        } else{
            nameNewPersonnel=nameMovements;
        }
        if(baseSalaryMovements==0){
            baseSalaryMovements=0;
        } else{
            baseSalaryNewPersonnel=baseSalaryMovements;
        }
        if(hireDateMovements==""){
            hireDateNewPersonnel=systemDate;
        } else{ 
            hireDateNewPersonnel=hireDateMovements;
        }

    }
}

//BAJA DE UN TRABAJADOR
/*
Baja no se realiza ninguna acción
*/
void deleteEmployee(){
    if(existe){
        writeMovements << workerMovements <<" BAJA VALIDA\n";
    } else{
        writeMovements << workerMovements <<" BAJA INVALIDA\n";
    }
}

//CAMBIO DE UN TRABAJADOR
void changeEmployee(){
}

//Copia


/*
Mejorar el diseño en módulos Copia, Alta, Baja y Cambio. Por 
ejemplo para Alta bastaría indicando solamente: "Generar registro en 
NP con la información de Mov y valores defaults"
*/





/***************** CLOSE ARCHIVES *******************/


//CERRAR ARCVHIVOS
void closeFiles(){
    movements.close();
    personnel.close();
    newPersonnel.close();
}


/***************** MAIN PROGRAM *******************/



int main(){
    openFiles();
    readMovement();
    closeFiles();
    return 0;
}
