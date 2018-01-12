//
// Created by ridvan on 30.10.2016.
//

#ifndef INC_141044070_COMPUTER_H
#define INC_141044070_COMPUTER_H

#include "myCpu.h"
#include "CPUProgram.h"

class computer {
public:
    /* constructure */
    computer(CPU &myCpu,CPUProgram &myProg,memory &myMemo,int option);
    computer(int option);
    /* fuction of setter and getter */
 const void setCPU(const CPU myCPU){procces=myCPU;}
    CPU &getCPU(){return procces;}
 const   void setCPUProgram(const  CPUProgram myprog){myProgram=myprog;}
    CPUProgram& getCPUProgram(){return myProgram;}
 const    void setMemory(const memory myMemo){ myMemory=myMemo; }
    memory& getMemory(){ return myMemory;}
    void execute();

private:
    CPU procces;
    CPUProgram myProgram;
    memory myMemory;

};


#endif //INC_141044070_COMPUTER_H
