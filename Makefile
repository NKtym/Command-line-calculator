cmdcalc: cmdcalc.o
	gcc -Wall -O0 -g  -o cmdcalc cmdcalc.o
cmdcalc.o: cmdcalc.c
	gcc -Wall -O0 -g  -c -o cmdcalc.o cmdcalc.c

clean: 
	rm *.o
