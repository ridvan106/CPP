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
#include <string>
#include "myCpu.h"
#include "CPUProgram.h"
#include <cstdlib>

int CPU::PC=1;/* set pc */
void rightTrash(string& other){// girilen satırın sag bosluklarını siler
    for (int i = 0; i < other.length(); ++i) {
        if(other[i]==' '){
            other.erase(i);
        }
        
    }
}
CPU::CPU(){
    option=0;// eger constructure baslangıc
                    // optionu almazsa otomatik sıfır alınır
    initialReg();// registerları sıfır

}
CPU::CPU(int OPTN){ //baslangıc optionu girilirse
    option=OPTN;
    initialReg(); //registerları ilklendirirs
    if(OPTN<0 && OPTN>2)
    {
        cerr<<"invalid option"<<endl;
        exit(1);
    }
}

void CPU::print() {
    cout<<"---R1--:"<<registers[0];
    cout<<"--R2--:"<<registers[1];
    cout<<"--R3--:"<<registers[2];
    cout<<"--R4--:"<<registers[3];
    cout<<"--R5--:"<<registers[4];
    cout<<"-----PC:"<<PC<<endl;

}//registerlari ekrana yazar
void CPU::execute(string line,memory& mem) {

    trash(line);//gereksiz yazilari siler
    strToUpper(line);//satır harflerini buyuk yapar

    int findMemo = line.find('#');// memory iliskisi var ise
    if (findMemo != -1) {

        instruct = getInstruction(line);//instructionu ayırır
        if (checkMem(line)){

            mem.setinstruct(instruct);

        getRegister(line);

        int camma = line.find(',');// virgul kontrolu
        if (camma == -1) {//virgul yok ise yani tek parametre ise

            if (mem.getIns() == "PRN") {//memory icin sadece prn olabilir

                int newIndis = covertInt(&line[findMemo + 1]);//prn tek parametre aldigi icin

                mem.setMemIndis(newIndis);//yeniden indisi set ediyoruz

                mem.prn(mem.getMemIndis());//ekrana yaziyoruz

            }

        } else {//eger vitgul var ise

            if (getRightOP()[0] == '#') {//virgulden sonra satirin icindeki memory ise
                mem.setMemIndis(covertInt(&getRightOP()[1]));// hangi memory oldugunu ogreniyoruz
                if (mem.Isreg(getLeftOP())) {//sol taraftaki register ise
                    setIndis(covertInt(&getLeftOP()[1]));//registerın indisini alıyoruz
                    if (mem.getIns() == "MOV")
                        /* instruction mov ise memorynin ilgili indisinaregisterdaki degeri depolar*/
                   mem.setMemory(mem.getMemIndis(),setZero(getRegister(covertInt(&getLeftOP()[1]) - 1)));
                    else if (mem.getIns() == "ADD")
                        /* add ise memorydeki degeri registerdaki degerle toplar ve registera ekler */
                        setRegister(getIndis(), getRegister(getIndis()) + mem.getMemory(mem.getMemIndis()));
                    else if (mem.getIns() == "SUB")
                        /*sub ise registerdaki degerden memorydeki degeri cikarip registera ekler */
                        setRegister(getIndis(), getRegister(getIndis()) - mem.getMemory(mem.getMemIndis()));


                } else {
                    /* eger soltaraf register ama gereken instruction veya farklı bir islem var ise
                     * hata verip programdan cikar */
                    if (getLeftOP()[0] != '#') {
                        cerr << "Invalid stuation to using memory" << endl;
                        exit(1);
                    }
                }

            } else if (getLeftOP()[0] == '#') {//eger sol tarafta memory var ise bu durum sadece mov da var
                mem.setMemIndis(covertInt(&getLeftOP()[1]));//hangi memory oldugunu alır
                if (mem.Isreg(getRightOP())) {//sagtaraf register ise
                    if (mem.getIns() == "MOV") {
                        //registera memory deki degeri atar

                        setRegister(covertInt(&getRightOP()[1]) - 1, mem.getMemory(covertInt(&getLeftOP()[1])));
                    }
                } else {// eger sagtaraf taraf sabit sayı ise
                    if (mem.getIns() == "MOV") {
                        //cout<<mem.getMemIndis()<<endl;
                        mem.setMemory(mem.getMemIndis(),setZero(covertInt(getRightOP())));
                    }
                }
            }
        }

        incrementPc();
    }
        else{

            instruct = "HLT";//check de sıkıntı var ise programdan cikar
        }
}



    else{

        instruct = getInstruction(line);//instructionu ayırır
        if (check(line)) {//program hata kontrolü yapar

            getRegister(line);//sol ve sag registerlari doldurur

            apply(line);//gerekli uygulama islemleri yapar
            if (option ==1)
                print();    //option 1 ise ekrana registerları yazar
            else if(option==2)
                mem.printAll();
            incrementPc();  //hersey normal ise pc bir artırır
        } else {

            instruct = "HLT";//check de sıkıntı var ise programdan cikar
        }

    }
}

void CPU::trash(string& line) {// satirdaki bosluk ve yorum satırını ayırır
    bool exit=true;
    int command=line.find(';');//noktalı virgul indisi
    if(command!=-1)
    line.erase(command,line.length());
 /*      ------------------------bosluk siler ve instructure ayirir----------------*/
    for (int i = 0; i <line.length() && exit==true ; ++i) {
        if(line[i]!=' '){
            line.erase(0,i);
            exit= false;
        }
        
    }
  /*--------------------------------------------*/


}
/*----------------------splitInstructure::instructure satirdan ayırır-------------------*/
string CPU::getInstruction(string &other) {
    const int sizeOfInst=3;


            return other.substr(0,sizeOfInst);//baştaki boşlukardan sonraki 3 karakteri return eder
            //ve bu da instruction olur

}
/*---------------------strToUpper girilen stringi buyuk yapar-----------------*/
void CPU::strToUpper(string &target) {
    int bCase=32;   //ascii carakterleri ile buyuk yapar
    for (int i = 0; i < target.length(); ++i) {
        if(target[i]>='a' && target[i]<='z'){// eger harf kucuk ise
            target[i]-=bCase;

        }
        else{
            target[i]=target[i];
        }
    }


}
/*------------------getRegister registerları ayırır ----------*/
void CPU::getRegister(const string other) {//registerı ayırır
    string regs=&other[3];


    trash(regs);

    int indisCamma=regs.find(',');
    if(indisCamma!=-1) {
        leftOperant = regs.substr(0, indisCamma);//soldaki registerı alır
        rightOperant = regs.substr(indisCamma + 1);//sagdaki registerı alır
        //virgulu baz alarak yapılır

        trash(rightOperant);//sol bosluku siler

        rightTrash(rightOperant);//sag tarafındaki diger boslukları siler
        rightTrash(leftOperant);//sag boslugu siler
    }


    }
/*------------ stringi int e cevirir -----------------*/
int CPU::covertInt(string str){

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
/*---------------girilen sayinin ustunu alır-----------*/
int pow(int ground,int top) {
    int mult = 1;
    for (int i = 0; i < top; ++i) {
        mult = mult * ground;
    }
    return mult;
}
/* ---------- apply() instructionlara gore işlem yapar --------------*/
int CPU::apply(string other) {

    int otherparam;
    string left=getLeftOP();//soldaki operationu alır
    bool sabit=false; //sabit sayı bilgisini tutmak icin
    int firtParam=covertInt(&getLeftOP()[1])-1;
    string right=getRightOP();

    if(getRightOP()[0]=='R') {//sagdaki register mı

        otherparam=covertInt(&getRightOP()[1])-1;
    }
    else{
        //register degil ise sabit sayidir

         otherparam=covertInt(getRightOP());

        sabit=true;
    }
    if(instruct=="MOV"){
        if(sabit==true){
            setRegister(firtParam,otherparam);//sabit sayiyi direk registera atar
        }
        else {

            setRegister(otherparam,getRegister(firtParam));//register kopyalama
        }
    }
        else if(instruct=="SUB"){

        if(sabit==true){
            int dif=getRegister(firtParam)-otherparam;//iki asamada registerdan sabit cikarma
            setRegister(firtParam,dif);//ve ilk registera kaydetme

        }
        else {

           int dif = getRegister(firtParam)-getRegister(otherparam);//ilk registerdan ikinciyi cikarma
            setRegister(firtParam,dif);// sonucu ilk registera kaydetme
        }
    }
        else if(instruct=="ADD"){
        if(sabit==true){
           int sum = getRegister(firtParam) + otherparam;//registerdaki deger ile sabiti toplama
            setRegister(firtParam,sum); //sonucu ilgili registera kaydetme

        }
        else {
//iki tane registera toplama
            int sum = getRegister(firtParam) + getRegister(otherparam);
            setRegister(firtParam,sum);
        }

    }
        else if(instruct=="JMP"){
     if(jmp(other)!=-1){    //jmp degeri -1 ise yani register degeri sifir ise
         setPC(jmp(other)-1);//-1 sebebi pc sonun da bir atırması
     }

    }
        else if(instruct=="JPN"){
        if(jpn(other)!=-1){    //jmp degeri -1 ise yani register degeri sifir ise
            setPC(jpn(other)-1);
        }

    }
        else if(instruct=="PRN"){
        prn(other);

    }
    else if(instruct=="HLT"){

        halted();//halt degerini false yapar
    }


}
int CPU::jmp(string other) {
    string line=&other[3];//instruction ı atar
    trash(line); //sol baslugu temizler
    int indis=line.find(',');
    if(indis==-1){ //virgul yok ise
        rightTrash(line); //diger boslukları da siler
        if(covertInt(line)>getSize) {
            cerr<<"stack over flow line"<<getPC()<<endl;
            exit(1); //programı sonlandırır
        }
        return covertInt(line);//gidecegi satırı return eder
    }
        //---------- Eger register kontrolu ise------------
    else{
        leftOperant = line.substr(0, indis);// registerı alır
        rightOperant = line.substr(indis + 1);// gidecegi satırı alır

        trash(rightOperant);//sabitin sol boslukşarı silinie

        rightTrash(rightOperant);//sag tarafındaki diger boslukları siler
        rightTrash(leftOperant);// registerın boslukları silinir
        int reg=covertInt(&leftOperant[1])-1;//-1 sebebi registerların indisi 0 dan baslaması

        if(getRegister(reg)==0)//register sıfır ise sabiti return eder
        {
            if(covertInt(rightOperant)>getSize){
                cerr<<"stack over flow line "<<getPC()<<endl;
                exit(1); //programı sonlandırır
            }
            return covertInt(rightOperant);
        }

        else
            return -1;//register sıfır degil ise -1 return eder

    }


}
const int CPU::jpn(string other){

    string line=&other[3];//instruction ı atar
    trash(line); //sol baslugu temizler
    int indis=line.find(',');
    leftOperant = line.substr(0, indis);// registerı alır
    rightOperant = line.substr(indis + 1);// gidecegi satırı alır
    trash(rightOperant);
    rightTrash(rightOperant);//sag tarafındaki diger boslukları siler
    rightTrash(leftOperant);// registerın boslukları silinir
    int reg=covertInt(&leftOperant[1])-1;//-1 sebebi registerların indisi 0 dan baslaması
    if(getRegister(reg)<=0)//register sıfır ise sabiti return eder
    {
        if(covertInt(rightOperant)>getSize){
            cerr<<"stack over flow line "<<getPC()<<endl;
            exit(1); //programı sonlandırır
        }
        return covertInt(rightOperant);
    }

    else
        return -1;//register sıfır degil ise -1 return eder


}
void CPU::prn(string other){
    string line=&other[3];// instruct kısmını atar
    trash(line); // sol boslukları atar
    rightTrash(line);//sag boslukları atar

    if(line[0]!='R' && line[0]>='0' && line[0]<='9' ){
        cout<<line<<endl;
    }
    else if(line[0]=='R'){

        cout<<getRegister(covertInt(&line[1])-1)<<endl;
    }
        else if(line[0]=='-')
        cout<<line<<endl;
    else {
        cerr<<"invalid stuation"<<endl;
    }


}
bool CPU::check(string line) {

    string swapLine=&line[3];
    trash(swapLine);
    string right,left;
    int indis=swapLine.find(',');
    //program counter dosya disina cikar ise
    if(getPC()>getSize){
        cerr<<"aaaStack Over Flow Lİne: "<<getPC()<<endl;

        return false;

    }
    if(indis==-1){//virgul yok ise
        if(instruct=="JMP"){//jump sayi degil ise hata verir
            if(!IsConst(swapLine)){
                cerr<<"Is not valid const  line:"<<getPC()<<endl;
                return false;
            }

        }
        else if(instruct=="PRN"){//prn sayi degil ise hata verir
            if(swapLine[0]!='-' && !swapLine[0]>='0' && !swapLine[0]<='9' &&swapLine[0]!='R')
                return false;
        }
        else if(instruct=="HLT")
            return true;

    }
    else{//virgul var ise
        left=swapLine.substr(0,indis);
        rightTrash(left);
        right=swapLine.substr(indis+1);
        trash(right),rightTrash(right);
//registerları ayırır


    if(instruct!="MOV" && instruct!="HLT" && instruct!="PRN" && instruct!="ADD"
            && instruct!="SUB" && instruct!="JMP" &&instruct!="JPN")
    {
        cerr<<"invalid instruct  line:"<<getPC()<<endl;
        return false;
    }
    else{

        if(left[0]!='R')//solda register yok ise
        {
            cerr<<"No Register  line:"<<getPC()<<endl;
            return false;
        }
        else if(right[0]!='R' && right[0]!='-' &&
                !right[0]>='0' && !right[0]<='9')
        {
            cerr<<"invalid   line:"<<getPC()<<endl;
            return false;
        }

        else if(left.length()==1)//register arasında bosluk var sa
        {
            cerr<<"stack over flow line: "<<getPC()<<endl;
            return false;
        }
        else if(covertInt(&left[1])>5 || covertInt(&left[1])<1)//register degerlei 5 den buyukse
        {
            cerr<<"stacklkk over flow line: "<<getPC()<<endl;
            return false;
        }

    }
    }

    return true;
}
bool CPU::checkMem(string line){
    string swapLine=&line[3];
    trash(swapLine);
    string right,left;
    int indis=swapLine.find(',');
    //program counter dosya disina cikar ise
    if(getPC()>getSize){
        cerr<<"Stack Over Flow Lİne: "<<getPC()<<endl;
        return false;

    }
    left=swapLine.substr(0,indis);
    rightTrash(left);
    right=swapLine.substr(indis+1);
    trash(right),rightTrash(right);
    if(indis!=-1 && left[0]=='#') {//iki parametreli ise
        if(instruct!="MOV") {//instruct mov degil ise memory lvalue olamaz
            cerr<<"invalid instruction for memory Line:"<<getPC()<<endl;
            return false;
        }
        if (left[0] == '#') {//eger sol taraf register ise
            int inds = covertInt(&left[1]);
            if (inds < 0 || inds > 49) {//memory 50 lik olmalı ve indis negative olmamalı
                cerr << "stack over flow for memory line: " <<getPC()<<endl;
                return false;
            }
        if(right[0]!='R' && right[0]!='#'){//eger sag taraf register degil ise memoriye sabit atanacak
            int sabit=covertInt(right);
            if(sabit<0)
            {
                cerr<<"Warning!!  memory is not negative outo setting zero Lİne::" <<getPC()<<endl;
            }

        }
        }
        if (right[0] == '#') {//sag taraf register ise
            int inds = covertInt(&right[1]);

            if (inds < 0 || inds > 49) {// indis konrolu
                cerr << "stack over flow for memory line: " <<getPC()<<endl;
                return false;
            }


        }

    }
    return true;
}
void CPU::initialReg()//ilklendirme yapar
{
    registers[0]=0;
    registers[1]=0;
    registers[2]=0;
    registers[3]=0;
    registers[4]=0;

}
int CPU::setZero(int const other)  {
    if(other<0)
        return 0;

    return other;


}
