#ifndef CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#define CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Person{
    int type=0;
    int line=0, seatNumber=0;
    int type3LastOperation=0;
    string ticket;
    int index;
};

class SeatOperations{

private:
    vector<Person> lines[2];
    int N, M;


public:
    SeatOperations(int N, int M);
    void addNewPerson(int personType, const string& ticketInfo);
    void printAllSeats(ofstream& outFile);
    void sitPerson(Person p);
    // YOU CAN ADD YOUR HELPER FUNCTIONS

    void movePerson(Person p);

    void moveTypeOne(Person p);

    void moveTypeTwo(Person p);

    void moveTypeThree(Person p);
};

#endif //CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
