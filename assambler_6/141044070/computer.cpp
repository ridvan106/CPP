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

#include "computer.h"

computer::computer(CPU &myCpu, CPUProgramDyn &myProg, memory &myMemo, int option)
{

    procces=myCpu;//cpudaki islemleri procces degiskenine alir
   myProgram=myProg;// mainden gelen my program degiskenine alır
    myMemory=myMemo;//memoryden gelen fegiskeni alir
}
computer::computer(int option) {

}
void computer::execute()  {


        while (!getCPU().halted()) {//cpu halted degil ise

            /*dosyadaki tum satirlari alir
             * ve cpu da execute eder */

            getCPU().execute(getCPUProgram()[getCPU().getPC()-1], myMemory);

        }


}
