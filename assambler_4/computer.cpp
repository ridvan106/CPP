//
// Created by ridvan on 30.10.2016.
//

#include "computer.h"

computer::computer(CPU &myCpu, CPUProgram &myProg, memory &myMemo, int option)
{

    procces=myCpu;//cpudaki islemleri procces degiskenine alir
   myProgram=myProg;// mainden gelen my program degiskenine alır
    myMemory=myMemo;//memoryden gelen fegiskeni alir
}
computer::computer(int option) {

}
void computer::execute()  {
    if(myProgram.size()>200)
        cerr<<"over Line"<<endl;
    else {
        while (!getCPU().halted()) {//cpu halted degil ise

            /*dosyadaki tum satirlari alir
             * ve cpu da execute eder */
            getCPU().execute(getCPUProgram().getLine(getCPU().getPC()), myMemory);
        }
    }

}