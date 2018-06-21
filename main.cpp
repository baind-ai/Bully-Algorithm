#include "bully.h"

int main() {

    int procIndex = 0;

    initProcesses();

    while(true){

        printState();

        std::cout << "Geben Sie ein Prozess Index ein um Ihn zu deaktiviern: ";
        std::cin >> procIndex;
        setProcInactive(processes[procIndex % NO_OF_PROC]);
        std::cout << "Geben Sie ein Prozess Index ein, der den Ausfall entdeckt: ";
        std::cin >> procIndex;
        elect(processes[procIndex % NO_OF_PROC]);
        coord();
    }



    return 0;

}