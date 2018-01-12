/*
 * ----------Rıdvan Demirci
 *              141044070
 *                  CPP Homework 3--------------------
 *
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include "myCpu.h"
#include "CPUProgram.h"

int main(int argc,char **argv) {
    if(argc<=2){
        cerr<<"invalid parameter"<<endl;
        return 0;
    }

    CPUProgram myProg(argv[1]);//dosya adını alır
    CPU myCpu(argv[2]);//option durumunu alır varsayılan degeri 0 dır
   //myCpu.print();
    myCpu.setSize(myProg.size());
    while(!myCpu.halted()) {


            myCpu.execute(myProg.getLine(myCpu.getPC()));

        }



    return 0;
}