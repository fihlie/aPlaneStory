/*
Student Name:
Student Number:
Project Number: 3
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "SeatOperations.h"

using namespace std;

SeatOperations::SeatOperations(int N, int M){
    // IMPLEMENT ME!
    Person temp{-1,-1,-1,-1};
    for(int i=0;i<N;i++){
        lines[0].push_back(temp);
    }
    for (int j = 0; j < M ; j++) {
        lines[1].push_back(temp);
    }
    this->N=N;
    this->M=M;
}

void SeatOperations::addNewPerson(int personType, const string& ticketInfo){
    // IMPLEMENT ME!
    string s=ticketInfo;
    s.erase(s.begin());
    Person p;
    p.seatNumber=stoi(s);
    if(ticketInfo[0]=='A'){
        p.line=0;
        if(p.seatNumber%N==0){
            p.index=N-1;
        }
        else{
            p.index=p.seatNumber%N-1;
        }
    }
    else if(ticketInfo[0]=='B'){
        p.line=1;
        if(p.seatNumber%M==0){
            p.index=M-1;
        }
        else{
            p.index=p.seatNumber%M-1;
        }
    }
    p.type=personType;
    p.ticket=ticketInfo;
    sitPerson(p);
}

void SeatOperations::printAllSeats(ofstream& outFile){
    // IMPLEMENT ME!
    for(int i=0;i<N;i++){
        if(lines[0][i].seatNumber==-1){
            outFile<<0<<endl;
        }
        else{
            outFile<<lines[0][i].type<<" "<<lines[0][i].ticket<<endl;
        }
    }
    for(int i=0;i<M;i++){
        if(lines[1][i].seatNumber==-1){
            outFile<<0<<endl;
        }
        else{
            outFile<<lines[1][i].type<<" "<<lines[1][i].ticket<<endl;
        }
    }
}
void SeatOperations::sitPerson(Person p) {
    if(p.line==0){
        int remainder = p.seatNumber%N;
        if(remainder==0){
            if(lines[0][N-1].seatNumber==-1){
                lines[0][N-1]=p;
            }
            else{
                Person decoy=lines[0][N-1];
                lines[0][N-1]=p;
                movePerson(decoy);

            }
        }
        else{
            if(lines[0][remainder-1].seatNumber==-1){
                lines[0][remainder-1]=p;
            }
            else{
                Person decoy=lines[0][remainder-1];
                lines[0][remainder-1]=p;
                movePerson(decoy);

            }
        }
    }
    else{
        int remainder = p.seatNumber%M;
        if(remainder==0){
            if(lines[1][M-1].seatNumber==-1){
                lines[1][M-1]=p;
            }
            else{
                Person decoy=lines[1][M-1];
                lines[1][M-1]=p;
                movePerson(decoy);

            }
        }
        else{
            if(lines[1][remainder-1].seatNumber==-1){
                lines[1][remainder-1]=p;
            }
            else{
                Person decoy=lines[1][remainder-1];
                lines[1][remainder-1]=p;
                movePerson(decoy);

            }
        }

    }
}
void SeatOperations::moveTypeOne(Person p){
    int remainder=0;
    if(p.line==0){
        remainder=p.seatNumber%M;
        if(remainder==0){
            if(lines[1][M-1].seatNumber==-1){
                p.line=1;
                lines[1][M-1]=p;
            }
            else{
                Person decoy=lines[1][M-1];
                p.line=1;
                lines[1][M-1]=p;
                movePerson(decoy);

            }
        }
        else{
            if(lines[1][remainder-1].seatNumber==-1){
                p.line=1;
                lines[1][remainder-1]=p;
            }
            else{
                Person decoy=lines[1][remainder-1];
                p.line=1;
                lines[1][remainder-1]=p;
                movePerson(decoy);

            }
        }
    }
    else if(p.line==1){
        remainder=p.seatNumber%N;
        if(remainder==0){
            if(lines[0][N-1].seatNumber==-1){
                p.line=0;
                lines[0][N-1]=p;
            }
            else{
                Person decoy=lines[0][N-1];
                p.line=0;
                lines[0][N-1]=p;
                movePerson(decoy);

            }
        }
        else{
            if(lines[0][remainder-1].seatNumber==-1){
                p.line=0;
                lines[0][remainder-1]=p;
            }
            else{
                Person decoy=lines[0][remainder-1];
                p.line=0;
                lines[0][remainder-1]=p;
                movePerson(decoy);

            }
        }
    }

}
void SeatOperations::moveTypeTwo(Person p){
    if(p.line==0){
        if(p.index==(N-1)){
            if(lines[1][0].seatNumber==-1){
                p.line=1;
                p.index=0;
                lines[1][0]=p;
            }
            else{
                Person decoy=lines[1][0];
                p.line=1;
                p.index=0;
                lines[1][0]=p;
                movePerson(decoy);

            }
        }
        else{
            p.index=p.index+1;
            if(lines[0][p.index].seatNumber==-1){
                lines[0][p.index]=p;
            }
            else{
                Person decoy=lines[0][p.index];
                lines[0][p.index]=p;
                movePerson(decoy);

            }
        }
    }
    else if(p.line==1){
        if(p.index==M-1){
            if(lines[0][0].seatNumber==-1){
                p.line=0;
                p.index=0;
                lines[0][0]=p;
            }
            else{
                Person decoy=lines[0][0];
                p.line=0;
                p.index=0;
                lines[0][0]=p;
                movePerson(decoy);

            }
        }
        else{
            p.index=p.index+1;
            if(lines[1][p.index].seatNumber==-1){
                lines[1][p.index]=p;
            }
            else{
                Person decoy=lines[1][p.index];
                lines[1][p.index]=p;
                movePerson(decoy);

            }
        }
    }
}
void SeatOperations::moveTypeThree(Person p){
    int temp;
    if(p.line==0){
        temp=(p.index+2*p.type3LastOperation+1)%(M+N);
        if(temp>=N){
            if(lines[1][temp-N].seatNumber==-1){
                p.index=temp-N;
                p.line=1;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[1][temp-N]=p;

            }
            else{
                Person decoy=lines[1][temp-N];
                p.index=temp-N;
                p.line=1;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[1][temp-N]=p;
                movePerson(decoy);
            }
        }
        else{
            if(lines[0][temp].seatNumber==-1){
                p.index=temp;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[0][temp]=p;

            }
            else{
                Person decoy=lines[0][temp];
                p.index=temp;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[0][temp]=p;
                movePerson(decoy);

            }

        }

    }
    else{
        temp=(p.index+2*p.type3LastOperation+1)%(M+N);
        if(temp>=M){
            if(lines[0][temp-M].seatNumber==-1){
                p.index=temp-M;
                p.line=0;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[0][temp-M]=p;

            }
            else{
                Person decoy=lines[0][temp-M];
                p.index=temp-M;
                p.line=0;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[0][temp-M]=p;
                movePerson(decoy);
            }
        }
        else{
            if(lines[1][temp].seatNumber==-1){
                p.index=temp;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[1][temp]=p;

            }
            else{
                Person decoy=lines[1][temp];
                p.index=temp;
                p.type3LastOperation=p.type3LastOperation+1;
                lines[1][temp]=p;
                movePerson(decoy);
            }

        }

    }

}
void SeatOperations::movePerson(Person p){
    if(p.type==1){
        moveTypeOne(p);
    }
    else if(p.type==2){
        moveTypeTwo(p);
    }
    else if(p.type==3){
        moveTypeThree(p);
    }

}



// YOU CAN ADD YOUR HELPER FUNCTIONS