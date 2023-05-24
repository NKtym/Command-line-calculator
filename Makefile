all: bin/cmdcalc

bin/cmdcalc: obj/app/cmdcalc.o obj/lib/Error.o obj/lib/stack.o obj/lib/listnode.o obj/lib/processing.o
	gcc -Wall -I src -o bin/cmdcalc obj/lib/Error.o obj/lib/listnode.o obj/lib/stack.o obj/lib/processing.o obj/app/cmdcalc.o
obj/app/cmdcalc.o: src/app/cmdcalc.c
	gcc -Wall -c -I src -o obj/app/cmdcalc.o src/app/cmdcalc.c
obj/lib/Error.o: src/lib/Error.c
	gcc -Wall -c -I src -o obj/lib/Error.o src/lib/Error.c
obj/lib/processing.o: src/lib/processing.c
	gcc -Wall -c -I src -o obj/lib/processing.o src/lib/processing.c
obj/lib/listnode.o: src/lib/listnode.c
	gcc -Wall -c -I src -o obj/lib/listnode.o src/lib/listnode.c
obj/lib/stack.o: src/lib/stack.c
	gcc -Wall -c -I src -o obj/lib/stack.o src/lib/stack.c

clean: 
	rm obj/lib/*.o
	rm obj/app/*.o
	rm bin/*
