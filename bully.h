//
// Created by majorslain on 20.06.18.
//



// numbers of processes


#ifndef BULLY_ALGORITHM_BULLY_H
#define BULLY_ALGORITHM_BULLY_H

#include <cstdlib>
#include <iostream>
#include "Bully.cpp"



extern const int NO_OF_PROC;

// struct for one process
struct proc;

//process array
extern proc processes[NO_OF_PROC];


// fills random values in the processes var
void initProcesses();

// cout the actual state of all processes
void printState();

// set the active value of the process to false
void setProcInactive(struct proc &process);

// starts sending elections
void elect(struct proc &process);

// sends message with new coord
void coord();

#endif //BULLY_ALGORITHM_BULLY_H
