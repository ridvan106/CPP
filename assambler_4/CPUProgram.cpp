/*
 * ----------Rıdvan Demirci
 *              141044070
 *                  CPP Homework 3--------------------
 *
 *
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "CPUProgram.h"
using namespace std;
CPUProgram::CPUProgram() {
   // cerr<<"there is no entering filename such a aprametere"<<endl;


}
CPUProgram::CPUProgram(int option) {



}
int  CPUProgram::readFile(string fileName) {

    ifstream file;

    file.open(fileName);
    if(file.is_open()) {
        int i = 0;
        while (!file.eof()) {
            getline(file, allProg[i]);//dosyayı string arraya atar
            i++;
        }
        setSize(i);
        return i;// dosysatır sayısını dondurur
    }
    else{
        cerr<<"File could not  open"<<endl;//hata hali
        exit(1);
    }


}





