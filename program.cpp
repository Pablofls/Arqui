/*
#Program: Personnel Management
#Objective: Modify personnel...
#Author: Pablo Flores Rodriguez
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
string archMovements = "movementsTest4.csv"; //We declare this 2 string so abort can be used
string archPersonnel = "personnelTest4.csv";
ifstream movements(archMovements);
ifstream personnel(archPersonnel);
ofstream newPersonnel("newpersonnel.csv");
ofstream writeReport("writeReport.txt");

//VERIFICAR ARCHIVOS
void openFiles(){
    cout<<"Inicio de Programa"<<endl;
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
string systemDate="20250310";
string auxiliar="",auxiliar2="";

/***************** READ ARCHIVES *******************/

void abortProgram(const std::string &current,
    std::string &previous,
    const std::string &fileName)
{
if (!previous.empty() && previous > current) {
std::cerr << "ERROR: " << fileName
      << " desordenado: "
      << previous << " > " << current << "\n";
std::abort();  // termina al instante
}
previous = current;
}

//Read Personnel Movement Archive
bool readMovement(){
    static std::string previousMov;  
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
        } catch (const std::invalid_argument& error) {
            baseSalaryMovements = 0; // Default value if conversion fails
        }

        abortProgram(workerMovements, previousMov, archMovements);

        return true;

    //}
}

//Read personal archive
bool readPersonnel(){
    static string previousPers;
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

        abortProgram(workerPersonnel, previousPers, archPersonnel);

        return true;
    //}
}

/***************** REGISTER *******************/
/*
No es necesario en Alta validar si el trabajador existe. 
*/
void registerEmployee(){
    if (workerMovements == " "){
        workerNewPersonnel = "";
    } else {
        workerNewPersonnel = workerMovements;
    }
    if(groupMovements==" "){
        groupNewPersonnel="OOO";
    } else{
        groupNewPersonnel=groupMovements;
    }
    if(companyMovements==" "){
        companyNewPersonnel="OOO";
    } else{
        companyNewPersonnel=companyMovements;
    }
    if(plantMovements==" "){
        plantNewPersonnel="OOO";
    } else{
        plantNewPersonnel=plantMovements;
    }
    if(departmentMovements==" "){
        departmentNewPersonnel="OOOOOO";
    } else{
        departmentNewPersonnel=departmentMovements;
    }
    if(cveMovements==" "){
        cveNewPersonnel="O";
    } else{
        cveNewPersonnel=cveMovements;
    }
    if(nameMovements==" "){
        nameNewPersonnel="OOOOOO";
    } else{
        nameNewPersonnel=nameMovements;
    }
    if(baseSalaryMovements==0){
        baseSalaryMovements=0000000;
    } else{
        baseSalaryNewPersonnel=baseSalaryMovements;
    }
    if(hireDateMovements=="0"){
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
    if (groupMovements!=" "){
        groupNewPersonnel=groupMovements;
    } else {
        groupNewPersonnel=groupPersonnel;
    }
    if (companyMovements!=" "){
        companyNewPersonnel=companyMovements;
    } else {
        companyNewPersonnel=companyPersonnel;
    }
    if (plantMovements!=" "){
        plantNewPersonnel=plantMovements;
    } else {
        plantNewPersonnel=plantPersonnel;
    }
    if (departmentMovements!=" "){
        departmentNewPersonnel=departmentMovements;
    } else {
        departmentNewPersonnel=departmentPersonnel;
    }
    if (cveMovements!=" "){
        cveNewPersonnel=cveMovements;
    } else {
        cveNewPersonnel=cvePersonnel;
    }
    if (nameMovements!=" "){
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
        hireDateNewPersonnel=systemDate;
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


/***************** PERSONNEL MOVEMENTS *******************/
void personnelMovements(bool &hasMov, bool &hasPers){
    if(workerMovements==auxiliar&&workerPersonnel==auxiliar2){
        hasPers= readPersonnel();
        hasMov= readMovement();
        return;
    }
    auxiliar=workerMovements;
    auxiliar2=workerPersonnel;
    //Same Keys
    if (hasMov && hasPers){
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
            personnelCopy();
            hasPers = readPersonnel();
        }
        return;
    }
    if (hasMov){
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
        
        return;

    } 
    if (hasPers){
        personnelCopy();
        hasPers = readPersonnel();
        return;
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
    cout<<"Final de Programa"<<endl;
}


/***************** CONTROL PROGRAM *******************/

void controlProgram(){
    bool hasMov  = readMovement();
    bool hasPers = readPersonnel();

    //Procesa hasta que ambos archivos se acaben
    while (hasMov || hasPers) {
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