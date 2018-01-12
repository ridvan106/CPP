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
#include "CPUProgram.h"
CPUProgram::CPUProgram(const CPUProgram &other) {  //copy constructure
    setText(other.getText());

}
int CPUProgram::ReadFile(const char *fileName) {
    //filename dosyayı açar ve vektoru doldurur
        ifstream file;
    file.open(fileName);
    if(!file.is_open()){
        cerr<<"file is not open"<<endl;
    }
    else{
        for (int i = 0; !file.eof(); ++i) {
            string temp;
            getline(file,temp);
            myText.push_back(temp);
//dosyadaki tüm verileri vector<string> e atar
        }

    }
    return myText.size();
    //satir sayisini return eder

}
CPUProgram::CPUProgram(vector<string> other) {
    //constructure parametre olarak string vektor alırsa
    myText=other;


}
CPUProgram operator+(const CPUProgram& other,const string str)  {
//programın son satırına stringe atar yeni cpu program dondurur
    if(str!=" ") {
        CPUProgram temp;
        temp.setText(other.getText());
        temp.setText(str);
        return temp;
    }
    cerr<<"invalid string"<<endl;
    exit(1);

}

CPUProgram operator+(const CPUProgram &other1, const CPUProgram &other2) {
    //iki tane programı birbirine ekler onu return eder
    CPUProgram temp;
    //yeni vektorun size belirlenir
    temp.myText.resize(other1.size()+other2.size());
    //tempe önce ilk programı ekler
    for (int i = 0; i < other1.size(); ++i) {
        temp.myText[i]=other1.myText[i];
        
    }
    //tempe programın devamını atar
    for (int i = 0; i < other2.size(); ++i) {
        temp.myText[i+other1.size()]=other2.myText[i];

    }
//temp obje return edilir
    return temp;
}
const bool CPUProgram::operator==(const CPUProgram &other) const {
//objelerin sizeları kontrol edilir
    return (other.size()==size());


}
ostream & operator<<(ostream& out,const CPUProgram& other){
//output stream tüm programı ekrana yazar
    for (int i = 0; i < other.size(); ++i) {
        out<<other.myText[i]<<endl;
    }
    return out;

}
const CPUProgram& CPUProgram::operator--(){
//programın son satırını siler
    myText.pop_back();

    return *this;

}
const CPUProgram CPUProgram::operator--(int ignore) {
    CPUProgram temp;
   // son satırı sile ama silinmemiş halini return eder
    temp.myText.resize(size());
    for (int i = 0; i < size(); ++i) {
        temp.myText[i]=myText[i];
    }
    myText.pop_back();

    return CPUProgram(temp.myText);
}
const CPUProgram CPUProgram::operator()(int range1,int range2)const{
    //vektorun substr sini alir
    vector<string> temp;

    if((range1<=size() && range2<=size()) && range2>range1 ) {

        int newSize = (range2 - range1) + 1;//new size range farkı +1 ise sınırlar dahil oldugu icin
        temp.resize(newSize);

        for (int i = range1; i <= range2; ++i) {

            temp[i - range1] = myText[i - 1];

        }
        return CPUProgram(temp);
    }
    else{

        cerr<<"It is not valid range"<<endl;

        return CPUProgram(temp);
    }
}
void CPUProgram::operator+=(const string str) {
    //programın sonuna stringi ekler
    if(str!=" " && str!="")
       setText(str);
    else {
        cerr << "invalid string" << endl;
        exit(1);
    }

}
const string CPUProgram::operator[](int index)const{

    //bu operetorde ise objenin indisindeki instructure return eder
    if(index<myText.size())
        return myText[index];
    else{
        cerr<<"stack over flow for CPUProgram"<<endl;
    exit(1);

    }
}
