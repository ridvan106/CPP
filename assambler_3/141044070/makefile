all:compile
compile:myCpu CPUProgram main binary
	./exe tam_karaler.txt 0
	rm *.o exe

myCpu:
	g++ -c myCpu.cpp -std=c++11
	
CPUProgram:
	g++ -c CPUProgram.cpp -std=c++11
main:
	g++ -c main.cpp -std=c++11
binary:
	g++ myCpu.o CPUProgram.o main.o -o exe -std=c++11
