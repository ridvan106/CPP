//
// Created by ridvan on 19.10.2016.
//

#ifndef INC_141044070_CPUPROGRAM_H
#define INC_141044070_CPUPROGRAM_H

#include <string>
using  namespace std;
    class CPUProgram{

    public:
        CPUProgram();
        CPUProgram(char * FN);//constructure paramtere olarak fileName alır
        bool check(string lineOfProg);//program hatalarını kontrol eder
        string getLine(int lineNum){return allProg[lineNum-1];};//parametrede girilen satırı return eder
        int size(){return readFile(filename);};//satir sayisini return eder read file saesinde
        int readFile(string fileName);//dosya adını okur ve tüm dosyaları depolar size return eder


    private:

        char * filename;// baska dosyalarda filename lazım oldugu icin
        string allProg[200];//tum program burda
    };
#endif //INC_141044070_CPUPROGRAM_H
