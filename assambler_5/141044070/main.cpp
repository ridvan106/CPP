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

int main(int argc,char *argv[]) {

    const char* filename = argv[1];
    int option = covertInt(argv[2]);
    Test1Function(filename,option);
    //cout<<"SIRALAMA"<<endl;
    //Test2Function("siralama.txt",option);
    /* cout<<"kalvyeden girilen iki sayıyı assamble de çarpma testi"<<endl;
    test3Function(filename,option); */

    return 0;
}
