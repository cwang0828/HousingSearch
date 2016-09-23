HW4:  ClientADT.o HouseADT.o listADTgen.o hw4.o
	gcc -o HW4 ClientADT.o HouseADT.o listADTgen.o hw4.o

hw4.o: hw4.c
	gcc -c hw4.c

listADTgen.o: listADTgen.c listADTgen.h
	gcc -c listADTgen.c

HouseADT.o: HouseADT.c HouseADT.h
	gcc -c HouseADT.c

ClientADT.o: ClientADT.c ClientADT.h
	gcc -c ClientADT.c
