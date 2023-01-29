#ifndef SYMPTOMS_H
#define SYMPTOMS_H
#include <vector>
#include <string>
#include "symptom.h"
using namespace std;

class symptoms
{
    private:
        int counter;
        long unsigned int idManage;
        vector<symptom*> symptomList;
    public:
        symptoms(); 
        void incCounter(); //increase counter
        void decCounter(); //decrease counter
        int getCounter(); // get counter
        void incIdManage(); //get manage
        long unsigned int getIdManage(); //manage ids
        void addSymptom();
        void printAllSymptoms();
        void printSymptomByName(string name);
        void loadSymptoms();
        void storeSymptoms();
        void cleanup();
};

#endif