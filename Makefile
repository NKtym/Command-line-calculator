all: bin/cmdcalc
test: bin/test.out

bin/cmdcalc: obj/app/cmdcalc.o obj/lib/Error.o obj/lib/stack.o obj/lib/listnode.o obj/lib/processing.o
	gcc -Wall -MMD -I src -o bin/cmdcalc obj/lib/Error.o obj/lib/listnode.o obj/lib/stack.o obj/lib/processing.o obj/app/cmdcalc.o
obj/app/cmdcalc.o: src/app/cmdcalc.c
	gcc -Wall -MMD -c -I src -o obj/app/cmdcalc.o src/app/cmdcalc.c
obj/lib/Error.o: src/lib/Error.c
	gcc -Wall -MMD -c -I src -o obj/lib/Error.o src/lib/Error.c
obj/lib/processing.o: src/lib/processing.c
	gcc -Wall -MMD -c -I src -o obj/lib/processing.o src/lib/processing.c
obj/lib/listnode.o: src/lib/listnode.c
	gcc -Wall -MMD -c -I src -o obj/lib/listnode.o src/lib/listnode.c
obj/lib/stack.o: src/lib/stack.c
	gcc -Wall -MMD -c -I src -o obj/lib/stack.o src/lib/stack.c

bin/test.out: obj/test/test_error.o test/main.c obj/lib/Error.o
	gcc -Wall -MMD -I src -I thirdparty -o $@ $^
obj/test/test_error.o: test/test_error.c obj/lib/Error.o 
	gcc -Wall -MMD -c -I src -I thirdparty -o $@ $^


clean: 
	rm obj/app/*.o
	rm obj/lib/*.o
	rm obj/test/*.o
	rm bin/*
