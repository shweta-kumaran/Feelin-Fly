#include <iostream>
#include <string>
#include "symptom.h"
using namespace std;

symptom::symptom()
{
    name = "";
    ifMeds = false;
    medicineName = "";
    medicineInfo = "";
    symptomInfo = "";
    tips = "";
}
symptom::symptom(string name, bool ifMeds, string medicineName, string medicineInfo, string symptomInfo, string tips)
{
    (*this).name = "";
    (*this).ifMeds = false;
    (*this).medicineName = "";
    (*this).medicineInfo = "";
    (*this).symptomInfo = "";
    (*this).tips = "";
}
//Mutator Functions - Gets
string symptom::getName(){return name;}
bool symptom::getIfMeds(){return ifMeds;}
string symptom::getMedicineName(){return medicineName;}
string symptom::getMedicineInfo(){return medicineInfo;}
string symptom::getSymptomInfo(){return symptomInfo;}
string symptom::getTips(){return tips;} 