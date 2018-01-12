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
#include "myCpu.h"
memory::memory(int option) {

}

int memory::covertInt(string str){

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
const void memory::printAll() {//option 2 ise memory i yazar
    for (int i = 0; i < 50; ++i) {
        cout<<"["<<i<<"] -> "<<getMemory(i)<<endl;
        
    }
    
}

