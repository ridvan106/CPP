/*          CSE HW02
 *              RIDVAN DEMİRCİ 141044070
 *
 *
 *
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string upperCase(string instruct);//this function make uppercase all line
bool controledOfMemory(string instruct,string data);/*
 *  bu fonksyon memorini unsigned olup olmadigina bakar
 *      ve memory asimi olup olmadigina bakar*
 *
 */
int controllerLine(char *fName);//250 satir olup olmadigini kontrol eder...
int JPN(string line,int *registers);//new instruct less than zero jump line
void printMemory(uint8_t *memory,int size);//option 2 ise memoryi ekrana yazar
void MOV(string r1,string r2,int *regs,uint8_t *memory);//it moves registers or constant
void ADD(string r1,string r2,int *regs,uint8_t  *memory);//it adds registers or register and constant
void SUB(string r1,string r2,int *regs,uint8_t  *memory);//it substructs registers or register to constat
int JPM(string line,int *registers);//this function goes to another line
void PRN(string line,int *registers,uint8_t  *memory);//print to distlay register or constant
int covertInt(string str);//convert string to integer
string deleteOfSpace(string line);//remove all whitespace
string instructur(string line);//this function splits instructs
int convertchar(char ch);//convert char to integer
int pow(int ground,int top);//taban ve ustu girilen sayinin ustunu alir
int stackOverflow(string parameter);
int main(int argc,char **argv){
        const int parameters=3;//enter the command line parametrs
    uint8_t memory[50];//signed unsigned meomory 0-255
    const int sizeOfRegister=5;
    const string option1="1";//enter registers and instructs on the screen
    const char commendPoinder=';';//started of th commend line
    const int noResult=-1;//functions return nothing
    const int fileName=1;//
    const string option=argv[2];//options can be two results
    int registers[sizeOfRegister]={0,0,0,0,0};//define register only five
    int hlt=1;

    ifstream txt;//file
    if(argc==parameters)//should enter three parameters on comment line
    {
        string instruct;//take an instruct
        txt.open(argv[fileName]);//open th file on command line filename
        if(txt.is_open()==false){
            cerr<<"file is not opend"<<endl;
            return -1;

        }

        int line=controllerLine(argv[1]);//satir sayisi controlu
        if(line>200)
        {
            cerr<<"Over Line "<<endl;
            return 1;
        }
        if(txt.is_open()) {//is file open??
            string satir;//take an line ,all characters
            for (int i = 0; txt.eof() != 1 && hlt==1; ++i) {
                txt>>instruct;//read instruction first
                getline(txt, satir);//the read other line
                int commandOfindis = satir.find(commendPoinder);
                // ';' işaretinin hangi indiste olduğunu bulur
                if(commandOfindis!=noResult)//there is  comment line
                    satir.erase(commandOfindis);//delete comment line
                satir=deleteOfSpace(satir);//remove all space and assign itself
                instruct=upperCase(instruct);//all words make uppercase

                if(controledOfMemory(instruct,satir)==true) {
                    if (instruct == "MOV") {
                        int camma = satir.find(',');//virgulu bulur
                        string sayi1 = satir.substr(0, camma);//ilk registeri ayirir
                        if (sayi1[0] != 'R' && sayi1[0] != '#') {
                            cerr << "there is no such a register!..." << endl;
                            hlt = 0;
                        } else {
                            string sayi2 = satir.substr(camma + 1, satir.length());//ikinci registeri ayirir
                            MOV(sayi1, sayi2, registers, memory);//send the mov function
                        }

                    } else if (instruct == "ADD") {
                        int camma = satir.find(',');//virgulun hangi indiste oldugunu bulur
                        string sayi1 = satir.substr(0, camma);//ilk registeri ayirir

                        if (sayi1[0] != 'R' && sayi1[0] != '#') {
                            cerr << "there is no such a register!..." << endl;
                            hlt = 0;
                        } else {
                            string sayi2 = satir.substr(camma + 1, satir.length());//ikinci registeri ayirir

                            ADD(sayi1, sayi2, registers, memory);
                        }

                    } else if (instruct == "SUB") {


                        int camma = satir.find(',');
                        string sayi1 = satir.substr(0, camma);
                        if (sayi1[0] != 'R' && sayi1[0] != '#') {
                            cerr << "there is no such a register!..." << endl;
                            hlt = 0;
                        } else {
                            string sayi2 = satir.substr(camma + 1, satir.length());
                            SUB(sayi1, sayi2, registers, memory);
                        }
                    } else if (instruct == "JMP") {

                        int gotoLine = JPM(satir, registers);//gidecegi satiri belirler
                        if (gotoLine != -1) {
                            txt.close();
                            txt.open(argv[fileName]);
                            for (int j = 0; j < gotoLine - 1; ++j)
                                getline(txt, satir);
                            /*eger gidicegi satir varsa dosyayı kapatır
                             * gidecegi satira kadar dosyadan satir satir veri okur ve
                             * gidecegi satir geldi mi durur */
                        }

                    } else if (instruct == "JPN") {


                        int goLine = JPN(satir, registers);//jpn dogru olupolmadigi kontrol edilir
                        string swapLine;
                        if (goLine != -1) {//eger goLine - ise işlem yapmaz
                            txt.close();
                            txt.open(argv[fileName]);
                            for (int j = 0; j < goLine - 1; ++j) {
                                getline(txt, swapLine);//satir sayisi gidecegi line kadar ilerler
                            }

                        }


                    } else if (instruct == "PRN")
                       PRN(satir, registers, memory);//send the parameters PRN function

                    else if (instruct == "HLT") {
                        hlt = 0;//if instruct is halt then loop is finished
                    } else {//there is no instruct
                        cerr << "There is no such an Instruct" << endl;
                        txt.close();
                    }

                    if (option == "1")//option 1 ise registerlari ekrana yazar
                        cout << "    --reg1:" << registers[0] << "---reg2:" << registers[1] << "--reg3:" << registers[2]
                             << "---reg4:" << registers[3] << "--reg5:" << registers[4] << endl;
                    else if (option == "2")//option 2 ise memoryleri yazar
                        printMemory(memory, 50);
                }
                else {//controlledOfmemory 'nin elsesi
                    hlt=0;//memory de hata var ise çkiis yapar
                }


            }
        }
        else
            cerr<<"file can not open"<<endl;
    }
    else
        cerr<<"no maching parameters"<<endl;



    return 0;
}
string upperCase(string instruct){
    int size=instruct.length();//gelen satirin uzunlugunu bulur
    const int bCase=32;//buyuk harfin ascii kodu
    for (int i = 0; i <size ; ++i) {

        if(instruct[i]>='a' && instruct[i]<='z'){// eger harf kucuk ise
            instruct[i]-=bCase;

        }
        else{
            instruct[i]=instruct[i];
        }


    }
    return instruct;

}
int covertInt(string str)
{
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
void MOV(string r1,string r2,int *regs,uint8_t  *memory){
    if(r2[0]=='#'){ /*ikinci degisken memory ise
 *
 * memory degerlerini bulup atamalarını yapar */
        int memoryNumber=covertInt(&r2[1]);
        int registerNum=convertchar(r1[1]);
        memory[memoryNumber-1]=regs[registerNum-1];


    }
        else if(r1[0]=='#'){
        int memoryNumber=covertInt(&r1[1]);
        if(r2[0]=='R')
        {
            int registerNum=convertchar(r2[1]);
            regs[registerNum-1]=memory[memoryNumber-1];
        }

        else{
                memory[memoryNumber-1]=covertInt(r2);

        }

    }
    else {
        if (r2[0] != 'R') {//ikinci parametrenin register olup olmadigini bulur

            int reg1 = convertchar(r1[1]);//kacinci register oldugunu buluruz

            regs[reg1 - 1] = covertInt(r2);
            /* kacinci registir oldugunu buldugunuzda
             * indisine erismek icin 1 cikarmaliyiz
             * ikinci parametre constant oldugu icin direk
             * atiyoruz!....*/
        } else {//eger ikinci parametrede register ise


            int reg1 = convertchar(r1[1]);//birinci parametrenin hangi register oldugunu bulur
            int reg2 = convertchar(r2[1]);//ikinci parametrenin hangi register oldugunu bulur
            regs[reg2 - 1] = regs[reg1 - 1];//sonra dizideki degerleri atiyoruz

        }
    }
}
int convertchar(char ch){
    /* bu fonksyonda registerin numarasini integera cevirip return eder */
    int num= static_cast<int>(ch);
    return num-48;// 48 ascii karakterie donusturmek icin
}
void ADD(string r1,string r2,int *regs,uint8_t  *memory){
/* add islemi memory icin sadece memory ile adress arasinda olur */
    if(r2[0]=='#'){
        int memoryNumber=covertInt(&r2[1]);//hangi memory oldugunu bulur
        int registerNum=convertchar(r1[1]);//hangi register oldugunu bulur
        regs[registerNum-1]+=memory[memoryNumber-1];//toplar ve atamasını yapar


    }
    else if(r1[0]=='#'){//aynı işlemin tersi
        int memoryNumber=covertInt(&r1[1]);
        int registerNum=convertchar(r2[1]);
        memory[memoryNumber-1] +=regs[registerNum-1];
    }

    else{
        if (r2[0] != 'R') {//register olup olmadigini kontol edilir
            int reg1 = convertchar(r1[1]);//hangi register oldugunu bulur

            regs[reg1 - 1] += covertInt(r2);//direk constantla toplar
        } else {
            int reg1 = convertchar(r1[1]);
            int reg2 = convertchar(r2[1]);
            regs[reg1 - 1] += regs[reg2 - 1];//bu seferde registerlarin degerlerini toplar

        }
    }
}
void SUB(string r1,string r2,int *regs,uint8_t  *memory){
/* sub da add ile aynı şekilde memory için memory ve register arasında olur */
    if(r2[0]=='#'){
        int memoryNumber=covertInt(&r2[1]);
        int registerNum=convertchar(r1[1]);
        regs[registerNum-1]-=memory[memoryNumber-1];


    }
    else if(r1[0]=='#'){
        int memoryNumber=covertInt(&r1[1]);
        int registerNum=convertchar(r2[1]);
        memory[memoryNumber-1] -=regs[registerNum-1];
    }

    else{
        if (r2[0] != 'R') {//constant sayi olduguna bakr
            int reg1 = convertchar(r1[1]);//hangi register old bulur

            regs[reg1 - 1] -= covertInt(r2);//registerdan constanti cikarir
        } else {//eger ikinci parametre constant degil ise
            int reg1 = convertchar(r1[1]);
            int reg2 = convertchar(r2[1]);
            regs[reg1 - 1] -= regs[reg2 - 1];//registerin degerlerinden cikarir

        }
    }


}
int JPM(string line,int *registers){
        if(line.find(',')==-1){//virgül olup olmadigini bulur

            return covertInt(line);//virgulyok ise direk constant return eder
        }
        else{
            int camma=line.find(',');//virgulun indisi bulunur
            int numberOfregister;
            string reg=line.substr(0,camma);//registerı ayırır
            numberOfregister=convertchar(reg[1]);//hangi register oldugunu bulur
            if(registers[numberOfregister-1]==0)//eger o register sifir ise
            {
                string goLine = line.erase(0,camma+1);//jump ta gelen ikinci satiri return eder
                return covertInt(goLine);
            }

        }
    return -1;//eger register sifir degil ise -1 return eder

}
void PRN(string line,int *registers,uint8_t  *memory){

    if(line[0]=='R'){//register ise o registerin degerini return eder
        int indis=convertchar(line[1]);

        cout<<registers[indis-1]<<endl;
    }
    else if(line[0]=='#'){ //memory adresi yazılcak ise
        int numberOfMemory=covertInt(&line[1]);
        cout<<unsigned(memory[numberOfMemory-1])<<endl;

    }
    else
        cout<<line<<endl;//eger constant ise direk constantı ekrana yazar


}
string deleteOfSpace(string line)
{
    char space=' ';
    int i,k=0;
    string newLine;
    int size=line.length();
    for (i = 0; i < size; ++i) {
        if(line[i]!=space){
            newLine[k]=line[i];
        k++;
            /* eger dizide bosluk yok ise direk newline stringine atar
             * eger bosluk var ise onu atmaz...
             */
        }


    }

    newLine[k]='\0';//null karakter
    newLine=upperCase(&newLine[0]);//diziyi butultur
    return &newLine[0];//yeni stringi return eder


}
string instructur(string line){

    string instruct=line.substr(0,3);
    /* instructler uc satir oldugu icin ilk uc satiri alıp
     * return eder */
    return instruct;

}
int pow(int ground,int top){
    int mult=1;
    for (int i = 0; i < top; ++i) {
        mult=mult*ground;
    }

    return  mult;
}//zemin ve ustu girilen degerlerin carpimini verir
int stackOverflow(string parameter){
    int reg=convertchar(parameter[1]);
    if(reg>=1 && reg<=5)
        return 1;
    return -1;

}
int controllerLine(char* fName){
    /* yüm satırları okur ve return eder */
    int i;
    ifstream ffile;
    ffile.open(fName);
    string junk;
    for (i = 0; ffile.eof()!=true; ++i) {
        getline(ffile,junk);

    }

    return i;
    
}
void printMemory(uint8_t  *memory,int size){
    for (int i = 0; i < size; ++i) {
        cout<<"--mem"<<i<<": "<<unsigned(memory[i])<<endl;

    }

    
}
int JPN(string line,int *registers){
    /* registerin <=0 olma durumuna bakıp ona gore -1
     * veya gidecegi satir sayisini return eder
     * */
    int indis=line.find(',');
    string reg=line.substr(0,indis);
    string goLine=line.substr(indis+1,line.length());

    int numReg=covertInt(&reg[1]);
    if(registers[numReg-1]<=0){
        return covertInt(goLine);
    }
return -1;



}
bool controledOfMemory(string instruct,string data){
    const int finishInstruct=3;
    int indisOfCamma=data.find(',');
    string r1=data.substr(0,indisOfCamma);//gelen degerleri ayrı ayrı degiskenler alır
    string r2=data.substr(indisOfCamma+1,instruct.length());

    if(instruct=="MOV") {
        if (r1[0] == '#' && covertInt(r2) < 0) {/* adress degiskenine negative sayi atanmak isteniyorsa
 *                              warnin verir ve otomatik bit kaydırır ve pozitif yapar*/

            cerr << "Warning!!,Memory should be unsigned,auto-fixed..." << endl;
            return true;

        }

        else if (r1[0] == '#' && covertInt(&r1[1]) > 50 || covertInt(&r1[1]) < 0) {
            cerr << "memory stackoverflowaa" << endl;
            /* girilen memory indisinin 50 den buyuk
 *          olup olmamasına bakar */
            return false;
        }
        else if(r1[0]=='R'){
            /*registeren negative veya 5 den buyuk
             * olup olmamasına bakılır */
            if(covertInt(&r1[1])<1 || covertInt(&r1[1])>5){
                cerr << "register stackoverflow" << endl;
                return false;
            }
            else if(covertInt(&r2[1]) < 0 || covertInt(&r2[1]) > 50){
                cerr << "memory stackoverflowss" << endl;
                return false;
            }

        }
    }
        /* aynı durumları sub add icin de kontrol eder */
    else if(instruct=="ADD" || instruct=="SUB") {
        if (r1[0] == '#') {
            cerr << "Invalid Instruction,valid one should be register" << endl;
            return false;
        } else if (covertInt(&r2[1]) > 50 || covertInt(&r2[1]) < 0) {
            cerr << "memory stackoverflow" << endl;
            return false;
        }
    }
    else if(instruct=="PRN"){
        /* print icin girilen degerlerin negative veya 50 den buyuk olmasını
         * kontrol eder */
        if (covertInt(&r1[1]) > 50 || covertInt(&r1[1]) < 0) {
            cerr << "memory stackoverflow" << endl;
            return false;
        }

    }
    return true;
}
