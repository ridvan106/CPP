//
// Created by ridvan on 19.10.2016.
//
#include <string>
#ifndef INC_141044070_MYCPU_H
#define INC_141044070_MYCPU_H

#include <iostream>
using namespace std;
int pow(int ground,int top);
class CPU{
public:
    CPU();
    CPU(string OPT);

    bool halted() const{ return(instruct=="HLT");};//if execute last insructure
    bool halted(bool a){ instruct="HLT";}
    void execute(string line);//take line and advances PC
    int setSize(int size){  getSize=size;}//size almamızı saglar
    int getPC(){return PC;};


    void print();//function print all register and Program Counter(PC)
private:
    string option;
    string instruct;
    string getLeftOP()const{return leftOperant;};//return register1
    string getRightOP()const{return rightOperant;};//retrun register2 or constant
    string leftOperant,rightOperant;
    void setRegister(int param,int other){ registers[param]=other ;}//registera degerleri atar
    void incrementPc(){ PC++;}//execute den sonra program counter bir artar
    void initialReg();// registerları initialize eder
    int getSize;//size
    int getRegister(int indis){return registers[indis];}//indisi girilen registera return eder
    int apply(string other);//registerlara degerleri atar
    void getRegister(const string other);//dosyadan gelen line ayırır ve register numarasini return eder
    int covertInt(string str);//stringdeki degeri integera cevirir
    static int PC;// program satırını tutar
    int registers[5];//registerlar 5 elemanlı
    string getInstruction(string &other);//gelen satirdan instrucutere ayirir
    void strToUpper(string& target);//girilen strigi buyukharf yapar
    void trash(string& line);//yorum satiri ve bosluklari siler
    void setPC(int other){ PC=other;}//pc yeni atama yapma
    int jmp(string other);
    void prn(string const other);
    bool check(string line);//yazım ve hata konrolü yapar
    bool IsConst(string other)const{ return other[0]>='0' && other[0]<='9';}

};

#endif //INC_141044070_MYCPU_H
