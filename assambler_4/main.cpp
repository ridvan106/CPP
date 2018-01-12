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
#include "requiredIncs.h"
int covertInt(string str){

    int boyut =str.length();

    int sum=0,swap=0,basamak=boyut-1;
    const int ASCII=48;//sayiya cevirmek icin gereken ascii
    if(str[0]=='-'){
        basamak--; //- isaret oldugu icin basamak sayisi 1 azalir
        for (int i = 1; i < boyut; i++) {
            swap = static_cast<int>(str[i]);//string deki karakter olan sayilari ascii karsiligi
            swap = swap - ASCII;//48 cikararak sayiyi buluruz
            sum = sum + (swap * pow(10, basamak));//basamak degeri ile carpip topluyoruz
            basamak--;
        }
        return -sum;
    }
    else {

        for (int i = 0; i < boyut; i++) {

            swap = static_cast<int>(str[i]);//string deki karakter olan sayilari ascii karsiligi

            swap = swap - ASCII;//48 cikararak sayiyi buluruz

            sum = sum + (swap * pow(10, basamak));//basamak degeri ile carpip topluyoruz

            basamak--;
        }
    }

    return sum;
}
int main(int argc,char **argv) {
mainTester(argc,argv);

       //myCpu.print();
 //   myCpu.setSize(myProg.size());
  /*  while(!myCpu.halted()) {


            myCpu.execute(myProg.getLine(myCpu.getPC()),heap);

        }*/



    return 0;
}