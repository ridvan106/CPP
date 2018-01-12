//
// Created by ridvan on 19.10.2016.
//
#include <string>
#ifndef INC_141044070_MYCPU_H
#define INC_141044070_MYCPU_H

#include <iostream>

using namespace std;
int pow(int ground,int top);

class memory{
public:/*-pulic functions or members  */
    memory(){};//bos ise
    memory(int option);// constructure

    /* setter and getter function in memory class */
    const string getLine(const string line) const {return line;}//saytir dosyasını alır
    const void setline(const string str){ line=str; }//satırsayısını set eder
    const void setMemory(int indis,int value){ memories[indis]=value;}//set memory
    const void setMemIndis(const int index){ memory_indis=index;}
    const int  getMemIndis()const { return memory_indis;}
    const int getMemory(int indis)const {return memories[indis];}
    const string getIns()const{ return instructure;}
    const bool Isreg(const string str)const{ return str[0]=='R';}
   const void setinstruct(const string instruct){ instructure=instruct;}
    const void prn(const int ind)const{ cout<<(memories[ind])<<endl;}
    const void printAll();//option 2 ise hepsini ekrana yazar
private:
    //private members
    int covertInt(string str);//stringdeki degeri integera cevirir
    string instructure;
    string instruction;
    string line;
    int memory_indis;
    int memories[50];//50 lik memory
};
class CPU{
public:
    CPU();
    CPU(int OPT);

    const bool halted() { return(instruct=="HLT");};//if execute last insructure

    void execute(string line,memory& mem);//take line and advances PC
    const int setSize(int size){  getSize=size;}//size almamızı saglar
   const  int getPC()const {return PC;};


    void print();//function print all register and Program Counter(PC)
private:
    int option;
    string instruct;
    string getLeftOP()const{return leftOperant;};//return register1
    string getRightOP()const{return rightOperant;};//retrun register2 or constant
    string leftOperant,rightOperant;
    void setRegister(int param,int other){ registers[param]=other ;}//registera degerleri atar
    void incrementPc(){ PC++;}//execute den sonra program counter bir artar
    void initialReg();// registerları initialize eder
    int getSize;//size
    int setZero(const int  other) ;//sayiyi sifir yapar
    int getRegister(int indis){return registers[indis];}//indisi girilen registera return eder
    int apply(string other);//registerlara degerleri atar
    void getRegister(const string other);//dosyadan gelen line ayırır ve register numarasini return eder
    int covertInt(string str);//stringdeki degeri integera cevirir
    static int PC;// program satırını tutar
    int registers[5];//registerlar 5 elemanlı
    const void setIndis(const int ind){ indis=ind;}
    const int getIndis(){return indis-1;}
    string getInstruction(string &other);//gelen satirdan instrucutere ayirir
    void strToUpper(string& target);//girilen strigi buyukharf yapar
    void trash(string& line);//yorum satiri ve bosluklari siler
    void setPC(int other){ PC=other;}//pc yeni atama yapma
    int indis;
    int jmp(string other);
    const int jpn(string other);
    void prn(string const other);
    bool check(string line);//yazım ve hata konrolü yapar
    bool checkMem(string line);//memory icin kontrol yapar
    bool IsConst(string other)const{ return other[0]>='0' && other[0]<='9';}

};

#endif //INC_141044070_MYCPU_H
