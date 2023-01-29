#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "symptom.h"
#include "symptoms.h"
using namespace std;

symptoms::symptoms()
{
    this->counter = 0;
    this->idManage = 111111;
}
void symptoms::incCounter() { counter = counter + 1;}//increase counter
void symptoms::decCounter() { counter = counter - 1;} //decrease counter
int symptoms::getCounter() {return counter;} // get counter
void symptoms::incIdManage() {idManage = idManage + 1;} //get manage
long unsigned int symptoms::getIdManage(){return idManage;}
void symptoms::addSymptom()
{
    string name; //symptom name
    bool ifMeds; //is there medicine to take it?
    string medicineName; //medicine name 
    string medicineInfo; //medicine info
    string symptomInfo; //information on symptom
    string tips;
    int n;

    cout << "Enter the symptom name: ";
    cin >> name; cout << endl;
    cout << "Enter if the symptom has medicine (1 true, other false): ";
    cin >> n;
    if (n == 1)
    {
        ifMeds = true;
    }
    else
    {
        ifMeds = false;
    }
    cout << endl;
    cout << "Enter the medicine name: "; cin >> medicineName; cout << endl;
    cout << "Enter the medicine info: "; cin >> medicineInfo; cout << endl;
    cout << "Enter the symptom info: "; cin >> symptomInfo; cout << endl;
    cout << "Enter some tips: "; cin >> tips; cout << endl;
    symptom* newSymptom = new symptom(name, ifMeds, medicineName, medicineInfo, symptomInfo, tips);
    symptomList.push_back(newSymptom);
    incIdManage();
    incCounter();
}
void symptoms::printAllSymptoms()
{
    long unsigned int i;
    for (i = 0; i < symptomList.size(); i++)
    {
        cout << symptomList.at(i)->getName() << ": " << symptomList.at(i)->getSymptomInfo() << endl;
    }
}
void symptoms::printSymptomByName(string name)
{
    long unsigned int i;
    for (i = 0; i < symptomList.size(); i++)
    {
        if (symptomList.at(i)->getName() == name)
        {
            cout << symptomList.at(i)->getName() << ": " << symptomList.at(i)->getSymptomInfo() << endl;
        }
    }
}
void symptoms::loadSymptoms()
{
     string name; //symptom name
        bool ifMeds; //is there medicine to take it?
        string medicineName; //medicine name 
        string medicineInfo; //medicine info
        string symptomInfo; //information on symptom
        string tips;
    ifstream fin;
    fin.open("symptoms.dat");
    fin >> counter; fin.ignore();

    for (int i = 0; i < counter; i++)
    {
        fin >> name >> ifMeds >> medicineName >> medicineInfo >> symptomInfo >> tips;
        symptom* news = new symptom(name, ifMeds, medicineName, medicineInfo, symptomInfo, tips);
        symptomList.push_back(news);
        incIdManage();
    }
    fin.close();
}
void symptoms::storeSymptoms()
{
    ofstream fout;
    fout.open("symptoms.dat");
    fout << counter << endl;

    long unsigned int i;
    for (i = 0; i < symptomList.size(); ++i)
    {
        fout << symptomList.at(i)->getName() << ": " << symptomList.at(i)->getSymptomInfo() << endl;
    }
    fout.close();
}
void symptoms::cleanup()
{
    long unsigned int i;
    for(i = 0; i < symptomList.size(); i++)
    {
        delete symptomList.at(i); //delete memore
    }
    symptomList.clear();
}