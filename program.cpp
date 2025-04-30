/*
#Program: Personnel Management
#Objective: Modify personnel...
#Author: Pablo Flores Rodriguez jytjtj
#Author: Ethan Rivera Saldivar
#Author:Christopher Reeker Cireno
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
#include <sstream>
using namespace std;

//DECLARACION DE ARCHIVOS
ifstream movements("movementsTest1.csv");
ifstream personnel("personnelTest1.csv");
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
bool readMovement(){
    string linea;
    char delimitador = ',';

    if (!getline(movements, linea)) {
        return false;
    }

    //if (getline(movements, linea)) {
        stringstream stream(linea);

        string moveTypeStr, baseSalaryStr;

        getline(stream, moveTypeStr, delimitador);
        getline(stream, workerMovements, delimitador);
        getline(stream, groupMovements, delimitador);
        getline(stream, companyMovements, delimitador);
        getline(stream, plantMovements, delimitador);
        getline(stream, departmentMovements, delimitador);
        getline(stream, cveMovements, delimitador);
        getline(stream, nameMovements, delimitador);
        getline(stream, baseSalaryStr, delimitador);
        getline(stream, hireDateMovements, delimitador);

        // Conversión de tipo
        moveTypeMovements = moveTypeStr.empty() ? ' ' : moveTypeStr[0];
        try {
            baseSalaryMovements = stod(baseSalaryStr);
        } catch (const std::invalid_argument& e) {
            baseSalaryMovements = 0; // Default value if conversion fails
        }

        return true;

    //}
}

//Read personal archive
bool readPersonnel(){
    string line;
    char delimiter = ',';
    if (!getline(personnel, line)){
        return false;
    }

    //if (getline(personnel, line)) {
        stringstream stream(line);

        getline(stream, workerPersonnel, delimiter);
        getline(stream, groupPersonnel, delimiter);
        getline(stream, companyPersonnel, delimiter);
        getline(stream, plantPersonnel, delimiter);
        getline(stream, departmentPersonnel, delimiter);
        getline(stream, cvePersonnel, delimiter);
        getline(stream, namePersonnel, delimiter);

        string baseSalaryStr;
        getline(stream, baseSalaryStr, delimiter);
        try {
            baseSalaryPersonnel = stoi(baseSalaryStr);
        } catch (const std::invalid_argument&) {
            baseSalaryPersonnel = 0; // Default value if conversion fails
        }

        getline(stream, hireDatePersonnel, delimiter);

        return true;
    //}
}

/***************** REGISTER *******************/
/*
No es necesario en Alta validar si el trabajador existe. 
*/
void registerEmployee(){
    if (workerMovements == ""){
        workerNewPersonnel = "";
    } else {
        workerNewPersonnel = workerMovements;
    }
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
    newPersonnel 
    << workerNewPersonnel << ", "
    << groupNewPersonnel  << ", "
    << companyNewPersonnel<< ", "
    << plantNewPersonnel  << ", "
    << departmentNewPersonnel << ", "
    << cveNewPersonnel    << ", "
    << nameNewPersonnel   << ", "
    << baseSalaryNewPersonnel << ", "
    << hireDateNewPersonnel << "\n";
}


/***************** CHANGE *******************/

void changeEmployee(){ //Cambiar a empty
    if (workerMovements!="0"){
        workerNewPersonnel=workerMovements;
    } else {
        workerNewPersonnel=workerPersonnel;
    }
    if (groupMovements!="000"){
        groupNewPersonnel=groupMovements;
    } else {
        groupNewPersonnel=groupPersonnel;
    }
    if (companyMovements!="000"){
        companyNewPersonnel=companyMovements;
    } else {
        companyNewPersonnel=companyPersonnel;
    }
    if (plantMovements!="000"){
        plantNewPersonnel=plantMovements;
    } else {
        plantNewPersonnel=plantPersonnel;
    }
    if (departmentMovements!="000000"){
        departmentNewPersonnel=departmentMovements;
    } else {
        departmentNewPersonnel=departmentPersonnel;
    }
    if (cveMovements!="O"){
        cveNewPersonnel=cveMovements;
    } else {
        cveNewPersonnel=cvePersonnel;
    }
    if (nameMovements!=""){
        nameNewPersonnel=nameMovements;
    } else {
        nameNewPersonnel=namePersonnel;
    }
    if (baseSalaryMovements!=0){
        baseSalaryNewPersonnel=baseSalaryMovements;
    } else {
        baseSalaryNewPersonnel=baseSalaryPersonnel;
    }
    if (hireDateMovements!=systemDate){
        hireDateNewPersonnel=hireDateMovements;
    } else {
        hireDateNewPersonnel=hireDatePersonnel;
    }
    newPersonnel 
        << workerNewPersonnel << ", "
        << groupNewPersonnel  << ", "
        << companyNewPersonnel<< ", "
        << plantNewPersonnel  << ", "
        << departmentNewPersonnel << ", "
        << cveNewPersonnel    << ", "
        << nameNewPersonnel   << ", "
        << baseSalaryNewPersonnel << ", "
        << hireDateNewPersonnel
        << '\n';
}

/***************** COPY *******************/
void personnelCopy(){
    newPersonnel
        << workerPersonnel << ", "
        << groupPersonnel  << ", "
        << companyPersonnel<< ", "
        << plantPersonnel  << ", "
        << departmentPersonnel << ", "
        << cvePersonnel    << ", "
        << namePersonnel   << ", "
        << baseSalaryPersonnel << ", "
        << hireDatePersonnel
        << "\n";
}

/***************** DELETE *******************/

/*
Baja no se realiza ninguna acción
*/
void deleteEmployee(){

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


/***************** PERSONNEL MOVEMENTS *******************/
void personnelMovements(bool &hasMov, bool &hasPers){
    //Same Keys
    if (workerMovements == workerPersonnel){
        switch (moveTypeMovements)
        {
        //Invalid Register
        case 'A':
            //Mark Invalid Register on Report
            //Call COPY
            personnelCopy();
            writeReport << workerMovements << " INVALID REGISTER\n";
            break;
        
        //Valid Delete
        case 'B':
            //Mark valid Delete on Report
            writeReport << workerMovements << " VALID DELETE\n";
            break;
        
        //Valid Change
        case 'C':
            //Call Change
            changeEmployee();
            writeReport << workerMovements << " VALID CHANGE\n";
            break;
        
        default:
            cout << "Fail on recognizign movement type" << endl;
            break;
        }
        hasMov  = readMovement();
        hasPers = readPersonnel();
    
    } else if (workerMovements < workerPersonnel){ 
        switch (moveTypeMovements)
        {
        //Valid Register
        case 'A':
            registerEmployee();
            writeReport << workerMovements << " VALID REGISTER\n";
            break;
        
        //Invalid Delete
        case 'B':
            //Mark Invalid Delete on Report
            writeReport << workerMovements << " INVALID DELETE\n";
            break;
        
        //Invalid Change
        case 'C':
            personnelCopy();
            //Mark Invalid Change on Report
            writeReport << workerMovements << " INVALID CHANGE\n";
            break;
        
        default:
            cout << "Fail on recognizign movement type" << endl;
            break;
        
        }
        hasMov = readMovement();

    } else {
        //Call COPY
        personnelCopy();
        hasPers = readPersonnel();
    }
}

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


/***************** CONTROL PROGRAM *******************/

void controlProgram(){
    bool hasMov  = readMovement();
    bool hasPers = readPersonnel();

    // 2) Procesa hasta que ambos archivos se acaben
    while (hasMov && hasPers) {
        personnelMovements(hasMov, hasPers);
    }
    
}



/***************** MAIN PROGRAM *******************/


int main(){
    openFiles();
    controlProgram();
    closeFiles();
    return 0;
}