#ifndef SYMPTOM_H
#define SYMPTOM_H
#include <string>
using namespace std;

/*
    Symptom Class
    stores a symptom's information
*/

class symptom
{
    private:
        string name; //symptom name
        bool ifMeds; //is there medicine to take it?
        string medicineName; //medicine name 
        string medicineInfo; //medicine info
        string symptomInfo; //information on symptom
        string tips; //tips to get better
    public:
        //Constructors
        symptom();
        symptom(string name, bool ifMeds, string medicineName, string medicineInfo, string symptomInfo, string tips);
        //Mutator Functions - Gets
        string getName(); 
        bool getIfMeds();
        string getMedicineName();
        string getMedicineInfo();
        string getSymptomInfo();
        string getTips();
};

#endif