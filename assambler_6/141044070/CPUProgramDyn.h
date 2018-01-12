//
// Created by ridvan on 26.11.2016.
//

#ifndef INC_141044070_CPUPROGRAMDYN_H
#define INC_141044070_CPUPROGRAMDYN_H

#include <iostream>
#include <fstream>
#include<cstdlib>
#include <cassert>
using namespace std;
namespace memoryDyn {
    class CPUProgramDyn {
    public:
        CPUProgramDyn(){setUpMemory(0); }//no parameter constructure
        CPUProgramDyn(int option){setUpMemory(0);};//option parameters
        CPUProgramDyn(const CPUProgramDyn& other);
        const string operator[](int index)const;
        friend CPUProgramDyn operator+(const CPUProgramDyn& other,const string str) ;
        void operator+=(const string str);
        friend CPUProgramDyn operator+(const CPUProgramDyn& other1,const CPUProgramDyn& other2);
        CPUProgramDyn operator=(const CPUProgramDyn& other2);
        const bool operator==(const CPUProgramDyn& other)const;
        const bool operator!=(const CPUProgramDyn& other)const{return !(*this==other);}
        const bool operator<(const CPUProgramDyn& other)const{return size()< other.size();}
        const bool operator>=(const CPUProgramDyn& other)const{return !((*this)<other);}
        const bool operator>(const CPUProgramDyn& other)const{return size()> other.size();}
        const bool operator<=(const CPUProgramDyn& other)const{return !((*this)>other);}
        friend ostream&operator<<(ostream& out,const CPUProgramDyn& other);
        const CPUProgramDyn& operator--();//pre discrement
        const CPUProgramDyn operator--(int ignore);//post discrement
        const CPUProgramDyn operator()(int range1,int range2)const ;
        int size()const{return len;};
        int ReadFile(const char * filename);

        string getMyText(int indis)const {return myText[indis];}
        ~CPUProgramDyn(){ delete [] myText; myText= nullptr; }

    private:
        void reSize(int size);
        void setSize(const int i){len=i;}
        void setUpMemory(int size);
        void seTMyText(int indis,string str);
        string *myText;
        int len;

    };

}
#endif //INC_141044070_CPUPROGRAMDYN_H
