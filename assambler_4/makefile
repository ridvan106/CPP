all:main execute
	rm *.o exe

main:compiler
	g++ main.o CPUProgram.o myCpu.o memory.o computer.o mainTester.o -o exe -std=c++11
	


compiler:
	g++ -c main.cpp CPUProgram.cpp myCpu.cpp memory.cpp computer.cpp mainTester.cpp -std=c++11

execute:
	./exe siralama.txt 0
	
