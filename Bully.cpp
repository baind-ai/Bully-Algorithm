//
// Created by majorslain on 20.06.18.
//

#include "bully.h"



struct proc{
    int nr;                         //process number
    bool active = true;             //process state
    bool coord = false;
};

const int NO_OF_PROC = 10;

proc processes[NO_OF_PROC];


void initProcesses(){

    srand(1);

    for(auto &p: processes){
        p.nr = rand();

    }

    processes[rand()%NO_OF_PROC].coord = true;


}

void printState(){

    int index = 0;
    for(auto p: processes){
        std::cout << index++ <<" Prozess ID: " << p.nr << " Status: " << p.active << " Koordinator: " << p.coord << "\n";
    }
    std::cout <<"\n";
}

void setProcInactive(struct proc &process){
    process.active = false;
    process.coord = false;
}

void coord(){

    for(auto c: processes){
        if(c.coord && c.active){
            for(auto p: processes){
                if(c.nr != p.nr){
                    std::cout <<"COORD-Nachricht von Prozess " << c.nr <<" an Prozess " << p.nr << " gesendet" <<"\n";
                }
            }
        }

    }

    std::cout <<"\n";

}

void elect(struct proc &process){

    process.coord = true;

    for(auto &p: processes){


        if(process.nr < p.nr ){
            std::cout << "Elect-Nachricht von Prozess " << process.nr <<" an Prozess " << p.nr << " gesendet" << "\n";

            if(p.active){
                process.coord = false;
                p.coord = true;
                std::cout <<"OK-Nachricht von Prozess " << p.nr <<" an Prozess " << process.nr << " gesendet"<< "\n";

                elect(p);
            }
        }

    }

}