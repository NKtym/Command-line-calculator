cmdcalc: cmdcalc.o Error.o stack.o listnode.o processing.o
	gcc -Wall -O0 -g  -o cmdcalc Error.o listnode.o stack.o processing.o cmdcalc.o
cmdcalc.o: cmdcalc.c
	gcc -Wall -O0 -g  -c -o cmdcalc.o cmdcalc.c
Error.o: Error.c
	gcc -Wall -O0 -g -c -o Error.o Error.c
processing.o:processing.c
	gcc -Wall -O0 -g -c -o processing.o processing.c
listnode.o: listnode.c
	gcc -Wall -O0 -g  -c -o listnode.o listnode.c
stack.o: stack.c
	gcc -Wall -O0 -g  -c -o stack.o stack.c

clean: 
	rm *.o
