/*---------------------------------------------------------------------------------------------------
-																									-
-																									-
-					Rıdvan Demirci 141044070														-	
-				HomeWork 5 																		 	-
-			opertor overloading kullanarak 	cpu programını yendiden yapmak							-
-																									-
-																									-	
-																									-	
-																									-
-----------------------------------------------------------------------------------------------------*/
#include "requiredIncs.h"
void Test1Function(const char* fileName,int option){
    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(fileName);
    //--------------------testing op+= and op[]-------------------------------//
    cout << "--------------------testing op+= and op[]-------------------------------" << endl;
    cout << myCPUProgram[0]<<endl;
    myCPUProgram += "hlt";
    cout << myCPUProgram[myCPUProgram.size()-1]<<endl;
    //-------------------------------------------------------------------------//
    //---------------testin operator+ and operator[]----------------------------
    cout << "---------------testin operator+ and operator[]----------------------------" << endl;
    cout << (myCPUProgram + "MOV R1, #45")<< endl;
    cout <<  (myCPUProgram + "MOV R1, #45")[myCPUProgram.size() - 1]<< endl;
    //-----------------testing operator+= and operator[]------------------------------
    cout<<"------------------testing operator+= and operator[]-------------------------" << endl;
    myCPUProgram += "MOV R2, #50";
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;
    //-------------operator<<-------------------------------------------------
    cout<<"//------------- operator << and + for two program  ---------------------------" << endl;
    CPUProgram myOtherCPUProgram(option);
    myOtherCPUProgram.ReadFile(fileName);
    cout << (myCPUProgram + myOtherCPUProgram) << endl;
    //----------------------------operator compare and -------------------------------
    cout<<"//----------------------------operator compare and -------------------------------" << endl;
    myCPUProgram.ReadFile(fileName);
    myOtherCPUProgram.ReadFile(fileName);
    cout << (myCPUProgram == myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram <= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram > myOtherCPUProgram ? "FAIL" : "DONE") << endl;
    --myOtherCPUProgram;
    cout << (myCPUProgram != myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram >= myOtherCPUProgram ? "DONE" : "FAIL") << endl;
    cout << (myCPUProgram < myOtherCPUProgram ? "FAIL" : "DONE") << endl;
//---------------------------operator()--------------------------------------
    cout<<"//---------------------------operator()--------------------------------------" << endl;
    // cout<<myCPUProgram<<endl;
    myCPUProgram += "mov r5,2";
    myCPUProgram += "mov r4,2";
    myCPUProgram += "hlt";
    cout << myCPUProgram<<endl;
    cout << myCPUProgram(1,3) << endl;
//---------------------------------------------------------------------------------------

    cout << "-----------------------------------------------------------" << endl;
}
void Test2Function(const char *fileName,int option){

    CPUProgram myCPUProgram(option);
    myCPUProgram.ReadFile(fileName);
    CPU myCpu(option);//option durumunu alır varsayılan degeri 0 dır

    myCpu.setSize(myCPUProgram.size());
    memory myMemory(option);

    computer computer1(myCpu, myCPUProgram, myMemory, option);
    computer computer2(option);

    computer2.setCPU(computer1.getCPU());
    computer2.setCPUProgram(computer1.getCPUProgram());
    computer2.setMemory(computer1.getMemory());

    computer2.execute();

}
void test3Function(const char*fileName,int option){
string str1,str2;
    cout << "ikitane sayi giriniz:";
    cin >> str1 >> str2;

    CPUProgram myCPUProgram(option);

    myCPUProgram += ("mov r1,"+str1);
    myCPUProgram += ("mov r2,"+str2);
    myCPUProgram += ("add r3,r1");
    myCPUProgram += "sub r2,1";
    myCPUProgram += "jmp r2,7";
    myCPUProgram += "jmp 3";
    myCPUProgram += "prn r3";
    myCPUProgram += "hlt";



    CPU myCPU(option);
    memory memory1;
    myCPU.setSize(myCPUProgram.size());
    computer computer1(myCPU, myCPUProgram, memory1, option);
cout << "-------------Calişan Program-----------" <<endl;
cout << myCPUProgram<<endl;
cout << "-----------programın çıktısı------------" << endl;

    computer1.execute();


}

