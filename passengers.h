#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <vector>
#include <string>
using namespace std;

class passengers
{
    private:
        int pCounter;
        long unsigned int idManage;
        vector<passenger*> passengerList;
    public:
        passengers(); 
        //increase counters used for space management and ids
        void incPCounter();
        void decPCounter();
        void incIdManage();
        int getPCounter();
        long unsigned int getIdManage();
        void addPassenger();
        void deletePassenger(long unsigned int id);
        passenger* searchPassengerName(string name); 
        void printAllPassengers(); 
        void printPassengerFlightInfo(long unsigned int id); 
        void loadPassengers(); //load into array
        void storePassengers(); //store to data field
        void editPassengerMedical(long unsigned int id); 
        void cleanup(); //cleanup space and memory
};
#endif