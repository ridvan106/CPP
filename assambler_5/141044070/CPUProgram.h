//
// Ridvan Demirci 141044070
//
#ifndef INC_5_CPUPROGRAM_H
#define INC_5_CPUPROGRAM_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include<cmath>
using namespace std;
namespace {


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


}

class CPUProgram {
public:
    CPUProgram(){option=0;}
    CPUProgram(const CPUProgram & other);
    CPUProgram(vector<string> other);
    CPUProgram(int option){ option=option;};
    const string operator[](int index)const;
   friend CPUProgram operator+(const CPUProgram& other,const string str) ;
    void operator+=(const string str);
    int size()const{return myText.size();}
    int ReadFile(const char *fileName);
    const vector<string>& getText()const {return myText;}
    void setText(const string str){ myText.push_back(str);}
    void setText(const vector<string>& other){ myText=other;}
    friend CPUProgram operator+(const CPUProgram& other1,const CPUProgram& other2) ;
    const bool operator==(const CPUProgram& other)const;
    const bool operator!=(const CPUProgram& other)const{return !(*this==other);}
    const bool operator<(const CPUProgram& other)const{return size()<other.size();}
    const bool operator>=(const CPUProgram& other)const{return !((*this)<other);}
    const bool operator>(const CPUProgram& other)const{return size()>other.size();}
    const bool operator<=(const CPUProgram& other)const{return !((*this)>other);}
    friend ostream&operator<<(ostream& out,const CPUProgram& other);
    const CPUProgram& operator--();//pre discrement
    const CPUProgram operator--(int ignore);//post discrement
    const CPUProgram operator()(int range1,int range2)const ;
private:
    vector<string> myText;
    int option;

};


#endif //INC_5_CPUPROGRAM_H
