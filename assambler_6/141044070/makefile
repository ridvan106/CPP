all: compile	

	g++ main.o mainTester.o CPUProgramDyn.o computer.o myCpu.o memory.o -o exe -std=c++11 
compile:
	g++ -c main.cpp mainTester.cpp CPUProgramDyn.cpp computer.cpp myCpu.cpp memory.cpp -std=c++11	

clean:
	rm *.o exe	
run:
	./exe siralama.txt 0
run2:
	./exe deneme.txt 0			
