all: registers.o memory.o instructions.o cpu.o screen.o main.o
	gcc -o gbdmg registers.o memory.o instructions.o cpu.o screen.o main.o -lX11

registers.o: registers.c registers.h 
	gcc -g -c registers.c

memory.o: memory.c memory.h 
	gcc -g -c memory.c

instructions.o: instructions.c instructions.h
	gcc -g -c instructions.c

cpu.o: cpu.c cpu.h
	gcc -g -c cpu.c

screen.o: screen.c screen.h
	gcc -g -c screen.c

main.o: main.c
	gcc -g -c main.c

clean: 
	rm *.o
