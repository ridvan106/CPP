main:all run
	rm exe
	
all:compile binary
	rm *.o

compile:
	g++ -c main.cpp computer.cpp CPUProgram.cpp -std=c++11
	g++ -c memory.cpp myCpu.cpp mainTester.cpp  -std=c++11
binary:
	g++ main.o computer.o CPUProgram.o memory.o myCpu.o	mainTester.o -o exe -std=c++11
run:
	./exe deneme.txt 0
