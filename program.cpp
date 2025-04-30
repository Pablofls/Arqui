/*
#Program: Personnel Management
#Objective: Modify personnel...
#Author: Pablo Flores Rodriguez jytjtj
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
ofstream writeReport("writeReport.txt");



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
    movements >> moveTypeMovements >> workerMovements >> groupMovements >> companyMovements >> plantMovements >> departmentMovements >> cveMovements >> nameMovements >> baseSalaryMovements >> hireDateMovements;
    

}

//Read personal archive
void readPersonnel(){
    personnel >> workerPersonnel >> groupPersonnel >> companyPersonnel >> plantPersonnel >> departmentPersonnel >> cvePersonnel >> namePersonnel >> baseSalaryPersonnel >> hireDatePersonnel;
}

/***************** ABORT *******************/


/*
La acción de abortar por archivos desordenados, se debe
realizar en el módulo que lee y sugiero que se detecte al 
momento de que el trabajador leído sea menor al anterior.
*/
//Aborts porgram (ETHAN)
void abort(){
    string previousWorker = "";

    //Checks Movements Archive
    while (movements >> moveTypeMovements >> workerMovements >> groupMovements >> companyMovements >> plantMovements >> departmentMovements >> cveMovements >> nameMovements >> baseSalaryMovements >> hireDateMovements){
        if (!previousWorker.empty() && previousWorker > workerMovements) {
            cerr << "ERROR: El archivo 'movements.txt' no está ordenado.\n";
            exit(EXIT_FAILURE);
        }
        previousWorker = workerMovements;

    }

    previousWorker = "";

    //Checks Personnel Archive
    while (personnel >> workerPersonnel >> groupPersonnel >> companyPersonnel >> plantPersonnel >> departmentPersonnel >> cvePersonnel >> namePersonnel >> baseSalaryPersonnel >> hireDatePersonnel) {
        if (!previousWorker.empty() && previousWorker > workerPersonnel) {
            cerr << "ERROR: El archivo 'personnel.csv' no está ordenado.\n";
            exit(EXIT_FAILURE);
        }
        previousWorker = workerPersonnel;
    }
}

/***************** FINAL REPORT *******************/

//Write Report
//void writeReport(){
    //Impresion de como se veria el reporte
//}

/***************** CONTROL PROGRAM *******************/

void controlProgram(){
    bool eofMovements = false;
    bool eofPersonnel = false;

    readMovement();
    readPersonnel();

    while (!(eofPersonnel && eofMovements)) {
        personnelMovements();

        if (personnel.eof()){
            eofPersonnel = true;
        } else {
            readPersonnel();
        }

        if (movements.eof()){
            eofMovements = true;
        }
        else {
            readMovement();
        }
    }

    //Call to create Final Report
    //writeReport();
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
            //Mark Invalid Register on Report
            break;
        
        //Invalid Delete
        case 'B':
            //Mark invalid Delete on Report
            break;
        
        //Valid Change
        case 'C':
            //Call Change
            changeEmployee();
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
            personnelCopy();
            break;
        
        //Invalid Delete
        case 'B':
            //Mark Invalid Delete on Report
            break;
        
        //Invalid Change
        case 'C':
            //Mark Invalid Change on Report
            break;
        
        default:
            cout << "Fail on recognizign movement type" << endl;
            break;
        
        readMovement();
        }

    } else {
        //Call COPY
        personnelCopy();
        readPersonnel();
    }
}

//ALTA DE UN TRABAJADOR
/*
No es necesario en Alta validar si el trabajador existe. 
*/
void registerEmployee(){
    if(existe){
        writeReport << workerMovements << " ALTA INVALIDA\n";
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
        writeReport << workerMovements <<" BAJA VALIDA\n";
    } else{
        writeReport << workerMovements <<" BAJA INVALIDA\n";
    }
}

//CAMBIO DE UN TRABAJADOR
void changeEmployee(){
    if (workerMovements!="0"){
        workerNewPersonnel=workerMovements;
    } else {
        workerNewPersonnel=workerPersonnel;
    }
    if (groupMovements!="0"){
        groupNewPersonnel=groupMovements;
    } else {
        groupNewPersonnel=groupPersonnel;
    }
    if (companyMovements!="0"){
        companyNewPersonnel=companyMovements;
    } else {
        companyNewPersonnel=companyPersonnel;
    }
    if (plantMovements!="0"){
        plantNewPersonnel=plantMovements;
    } else {
        plantNewPersonnel=plantPersonnel;
    }
    if (departmentMovements!="0"){
        departmentNewPersonnel=departmentMovements;
    } else {
        departmentNewPersonnel=departmentPersonnel;
    }
    if (cveMovements!="0"){
        cveNewPersonnel=cveMovements;
    } else {
        cveNewPersonnel=cvePersonnel;
    }
    if (nameMovements!="0"){
        nameNewPersonnel=nameMovements;
    } else {
        nameNewPersonnel=namePersonnel;
    }
    if (baseSalaryMovements!=0){
        baseSalaryNewPersonnel=baseSalaryMovements;
    } else {
        baseSalaryNewPersonnel=baseSalaryPersonnel;
    }
    if (hireDateMovements!="0"){
        hireDateNewPersonnel=hireDateMovements;
    } else {
        hireDateNewPersonnel=hireDatePersonnel;
    }

    newPersonnel<<workerNewPersonnel
    << groupNewPersonnel
    << companyNewPersonnel
    << plantNewPersonnel
    << departmentNewPersonnel
    << cveNewPersonnel
    << nameNewPersonnel
    << baseSalaryNewPersonnel
    << hireDateNewPersonnel;
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
    controlProgram();
    closeFiles();
    return 0;
}
