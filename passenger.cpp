#include <iostream>
#include <string>
#include "passenger.h"
using namespace std;

passenger::passenger()
{
    firstName = "";
    lastName = "";
    passengerId = 0;
    flightNum = 0;
    onMeds = false;
    numMeds = 0;
    medCondition = "Good";
    flightdestination = "";
    airport = "";
    time = "";
}
passenger::passenger(string firstName, string lastName, int passengerId, int flightNum, bool onMeds, int numMeds, string medCondition,  string flightdestination, string airport, string time)
{
    (*this).firstName = firstName;
    (*this).lastName = lastName;
    (*this).passengerId = passengerId;
    (*this).flightNum = flightNum;
    (*this).onMeds = onMeds;
    (*this).numMeds = numMeds;
    (*this).medCondition = medCondition;
    (*this).flightdestination = flightdestination;
    (*this).airport = airport;
    (*this).time = time;
}
//Mutator Functions - Gets
string passenger::getFullName(){ return (firstName + " " + lastName); }
long unsigned int passenger::getPassengerId(){ return passengerId; }
int passenger::getFlightNum(){return flightNum;}
bool passenger::getOnMeds(){return onMeds;}
int passenger::getNumMeds(){return numMeds;}
string passenger::getMedConditon(){return medCondition;}
string passenger::getflightDestination(){return flightdestination;}
string passenger::getAirport(){return airport;}
string passenger::getTime(){return time;}
void passenger::setMedCondition(string text, int num)
{
    (*this).medCondition = text;
    (*this).numMeds = num;
    if( num > 0)
    {
        (*this).onMeds = true;
    }
}
