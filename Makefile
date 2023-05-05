cmdcalc: cmdcalc.o Error.o
	gcc -Wall -O0 -g  -o cmdcalc Error.o cmdcalc.o
cmdcalc.o: cmdcalc.c
	gcc -Wall -O0 -g  -c -o cmdcalc.o cmdcalc.c
Error.o: Error.c
	gcc -Wall -O0 -g -c -o Error.o Error.c

clean: 
	rm *.o
