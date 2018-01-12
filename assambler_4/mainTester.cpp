#include "requiredIncs.h"
int covertInt(string a);

void mainTester(int argc,char **argv){
    const char *filename = argv[1];
    int option = covertInt(argv[2]);
    if (argc <= 2) {
        cerr << "invalid parameter" << endl;
    }
    CPUProgram myProg(option);//dosya adını alır
    myProg.readFile(filename);

//cout<<myProg.getLine(3)<<endl;
    CPU myCpu(option);//option durumunu alır varsayılan degeri 0 dır

    myCpu.setSize(myProg.readFile(filename));
    memory myMemory(option);

    computer computer1(myCpu, myProg, myMemory, option);
    computer computer2(option);

    computer2.setCPU(computer1.getCPU());
    computer2.setCPUProgram(computer1.getCPUProgram());
    computer2.setMemory(computer1.getMemory());

    computer2.execute();

}