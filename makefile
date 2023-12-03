mainmat: mainmat.o mat.o parser.o matparser.o misc.o
	gcc -ansi -pedantic -Wall -o mainmat mainmat.o mat.o matparser.o misc.o parser.o

mainmat.o: mainmat.c mat.h parser.h matparser.h misc.h
	gcc -ansi -pedantic -Wall -c mainmat.c

mat.o: mat.c mat.h 
	gcc -ansi -pedantic -Wall -c mat.c 

matparser.o: matparser.c matparser.h parser.h misc.h
	gcc -ansi -pedantic -Wall -c matparser.c

misc.o: misc.c misc.h
	gcc -ansi -pedantic -Wall -c misc.c

parser.o: parser.c parser.h misc.h
	gcc -ansi -pedantic -Wall -c parser.c 
