#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"
#include "passengers.h"
#include "symptom.h"
#include "symptoms.h"
using namespace std;

passengers pas;
symptoms sym;

void menu()
{
    cout << "******************** MENU **********************" << endl;
    cout << "                 1 - Passenger Symptom Check    " << endl;
    cout << "                 2 - Passenger View             " << endl;
    cout << "                 3 - Manage Symptoms            " << endl;
    cout << "                 4 - Manage Passengers          " << endl;
    cout << "                 5 - Leave item menu            " << endl;
    cout << "************************************************" << endl;
}

void checker_instructions(passenger person)
{
    cout << "Hello " << person.getFullName() << "! Thank you for flying with us! We are sorry to hear that you are not feeling well." << endl;
    cout << "To help your experience travelling with us, here is a tool to better understand your health issues while flying." << endl;
    cout << "Based on the data you provided, you are currently: " << endl;
    cout << "   - on " << person.getNumMeds() << " medication(s)" << endl;
    cout << "   - health condition: " << person.getMedConditon() << endl << endl;
}

string symptom_checker(passenger person)
{
    checker_instructions(person);
    int feeling = 0;
    int n = 0;
    bool correct = true;
    while (correct == true)
    {

        cout << "Are you experiencing any discomfort including nausea, headache, ear ringing, etc.? (1: yes, 0: No) " << endl;
        cin >> n;
        if (cin.fail() || n < 0 || n > 1)
        {
            cout << "Error: no discomfort" << endl;
            correct = false;
        }


        cout << "What are you feeling? Enter the corresponding number based on the menu below: " << endl;
        cout << "   - 1: Is your head hurting or are your ears ringing? " << endl;
        cout << "   - 2: Are you experiencing nausea? " << endl;
        cout << "   - 3: Do you feel anxiety? " << endl;
        cout << "   - 4: Are you having body pain?" << endl;
        cout << "   - 5: Other" << endl;
        cin >> feeling;
        if (feeling < 1 || feeling > 5)
        {
            cout << "Incorrect Value: Returning Home" << endl;
            correct = false;
            return "";
        }
        if (feeling == 1)
        {
            correct = false;
            return "Head";
        }       
        else if (feeling == 2)
        {
            correct = false;
            return "Nausea";
        }
        else if (feeling == 3)
        {
            correct = false;
            return "Anxiety";
        }
        else if (feeling == 4)
        {
            correct = false;
            return "Body";
        }
        else
        {
            correct = false;
            return "Other";
        }
    }
}

int main()
{
    pas.loadPassengers();
    sym.loadSymptoms();
    pas.addPassenger();
    bool choice = true;
    int m;
    while (choice == true)
    {
        menu();
        cout << "Enter menu choice (type the number corresponding to your choice 1-5): "; cin >> m;
        cin.ignore();cout << endl;
        if (cin.fail() || m < 0 || m > 5)
        {
            cout << "Error: exiting app....." << endl;
            choice = false;
        }
        if (m == 1)
        {
            string l;
            cout << "Enter full name: "; 
            getline(cin, l); cin.ignore();
            string s = symptom_checker(*pas.searchPassengerName(l));
            sym.printSymptomByName(s);
            cout << "The airline needs to fill symptom database. Then the program will go find the symptom info and update you on what to do." << endl;
        }
        else if (m == 2)
        {
            string name;
            cout << "Edit your medical condition/history page:" << endl;
            cout << "Enter full name: "; 
            getline(cin, name); cin.ignore();
            passenger *l = pas.searchPassengerName(name);
            string t;
            int num;
            cout << "Enter new medical conditions/description: " << endl;
            getline(cin, t); cin.ignore();
            cout << "Enter the number of new medications: " << endl;
            cin >> num;
            l->setMedCondition(t, num);
            //will implement flight info details and such 
        }
        else if (m == 3)
        {
            // allows airlines to add symptoms and manage that database
            cout << "Exiting app....." << endl;
            choice = false;
        }
        else if (m == 4)
        {
            // allows airlines to add passengers and manage their data
            cout << "Exiting app....." << endl;
            choice = false;
        }
        else
        {
            cout << "Exiting app....." << endl;
            choice = false;
        }
    }

    pas.storePassengers();
    sym.storeSymptoms();
    pas.cleanup();
    sym.cleanup();
}