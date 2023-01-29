#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passenger.h"
#include "passengers.h"
using namespace std;

passengers::passengers()
{
    this->pCounter = 0;
    this->idManage = 111111;
}
void passengers::incPCounter(){this->pCounter = pCounter + 1;}
void passengers::decPCounter(){this->pCounter = pCounter - 1;}
void passengers::incIdManage(){this->idManage = idManage + 1;}
int passengers::getPCounter(){return pCounter;}
long unsigned int passengers::getIdManage(){return idManage;}
void passengers::addPassenger()
{
    string fName, lName, medCondition, flightdestination, airport, time;
    long unsigned int pasId, flightNum; 
    bool onMeds;
    int numMeds, n; //num of meds passenger is on

    pasId = idManage; 
    cout << "Enter new passenger's first name: " << endl;
    cin >> fName;
    cout << "Enter the new passenger's last name: " << endl;
    cin >> lName;
    cout << "Enter the flight number: " << endl;
    cin >> flightNum;
    cout << "Is the passenger on medicine? (1: True, 0: False)" << endl;
    cin >> n;
    if (cin.fail())
    {
        cout << "Error: labeled as false" << endl;
        onMeds = false;
    }
    cout << "Description of the passenger's medical condition: " << endl;
    cin >> medCondition;
    cout << "Enter the passenger's flight destination airport code: " << endl;
    cin >> flightdestination;
    cout << "Enter the passenger's airport code: " << endl;
    cin >> airport;
    cout << "Enter the flight time: " << endl;
    cin >> time;

    passenger *newPassenger = new passenger(fName, lName, pasId, flightNum, onMeds, numMeds, medCondition, flightdestination, airport, time);
    passengerList.push_back(newPassenger);
    incIdManage();
    incPCounter(); 
}
void passengers::deletePassenger(long unsigned int id)
{
    long unsigned int i;
    int x = 0;
    for (i = 0; i < passengerList.size(); ++i)
    {
        if (passengerList.at(i)->getPassengerId() == id)
        {
            delete passengerList.at(i);
            passengerList.erase(passengerList.begin() + i);
            decPCounter();
            x++;
        }
    }
    if (x == 0)
    {
        cout << "No Passenger Found with ID provided. Please try again with a valid ID" << endl;
    }
}
passenger* passengers::searchPassengerName(string name)
{
    long unsigned int i;
    long unsigned int y;
    int x = 0;
    for (i = 0; i < passengerList.size(); ++i)
    {
        if (passengerList.at(i)->getFullName() == name)
        {
            x++;
            y = i;
            break;
        }
    }
    if (x != 0)
    {
        return passengerList.at(y);
    }
    else
    {
        cout << "No Passenger Found with name provided. Please try again with a valid name";
        passenger *x = new passenger();
        return x;
    }
}
void passengers::printAllPassengers()
{
    long unsigned int i;
    for (i = 0; i < passengerList.size(); ++i)
    {
        cout << "Name: " << passengerList.at(i)->getFullName() << " - ";
        cout << "Passenger ID: " << passengerList.at(i)->getPassengerId() << endl;
    }
}
void passengers::printPassengerFlightInfo(long unsigned int id)
{
    long unsigned int i;
    for (i = 0; i < passengerList.size(); ++i)
    {
        cout << "Name: " << passengerList.at(i)->getFullName() << " - ";
        cout << "Airport: " << passengerList.at(i)->getPassengerId() << " - ";
        cout << "Destination: " << passengerList.at(i)->getAirport() << " - ";
        cout << "Time: " << passengerList.at(i)->getTime() << endl;
    }
}
void passengers::loadPassengers()
{
    string fName, lName, medCondition, flightdestination, airport, time;
    long unsigned int pasId, flightNum; 
    bool onMeds;
    int numMeds;
    int pCounter;
    ifstream fin;
    fin.open("passengers.dat");
    fin >> pCounter; fin.ignore();

    for (int i = 0; i < pCounter; i++)
    {
        fin >> fName >> lName >> pasId >> flightNum >> onMeds >> numMeds >> medCondition >> flightdestination >> airport >> time;
        passenger *newPassengers = new passenger(fName, lName, pasId, flightNum, onMeds, numMeds, medCondition, flightdestination, airport, time);
        passengerList.push_back(newPassengers);
        incIdManage();
    }
    fin.close();
}
void passengers::storePassengers()
{
    ofstream fout;
    fout.open("passengers.dat");
    fout << pCounter << endl;

    passenger *temp;
    long unsigned int i;
    for (i = 0; i < passengerList.size(); ++i)
    {
        temp = passengerList.at(i);
        fout << temp->getFullName() << " ";
        fout << temp->getPassengerId() << " ";
        fout << temp->getFlightNum() << " " << temp->getOnMeds() << " " << temp->getNumMeds() << " " << endl;
    }
    fout.close();
}
void passengers::editPassengerMedical(long unsigned int id)
{
    long unsigned int i;
    for (i = 0; i < passengerList.size(); ++i)
    {
        if (passengerList.at(i)->getPassengerId() == id)
        {
            string in;
            int num;
            cout << "Enter the passenger's new medical description: ";
            cin >> in;
            cout << endl;
            cout << "Enter the passenger's new number of medications: ";
            cin >> num;
            cout << endl;

            passengerList.at(i)->setMedCondition(in, num);
        }
    }
}
void passengers::cleanup()
{
    long unsigned int i;
    for(i = 0; i < passengerList.size(); i++)
    {
        delete passengerList.at(i);
    }
    passengerList.clear();
}; //cleanup space and memory