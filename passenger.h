#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std;

/*
    Passenger Class
    stores a passenger's information
*/

class passenger
{
    private:
        string firstName; //passenger first name
        string lastName; //passenger last name
        long unsigned int passengerId; //passenger ID number
        long unsigned int flightNum; //passenger flight number
        bool onMeds; //if passenger is on meds
        int numMeds; //num of meds passenger is on
        string medCondition; //medical condition "Good", "Bad"
        string flightdestination;
        string airport;
        string time;

    public:
        //Constructors
        passenger();
        passenger(string firstName, string lastName, int passengerId, int flightNum, bool onMeds, int numMeds, string medCondition, string flightdestination, string airport, string time);
        //Mutator Functions - Gets
        string getFullName();
        long unsigned int getPassengerId();
        int getFlightNum();
        bool getOnMeds();
        int getNumMeds();
        string getMedConditon();
        string getflightDestination();
        string getAirport();
        string getTime();
        void setMedCondition(string text, int num);
};

#endif