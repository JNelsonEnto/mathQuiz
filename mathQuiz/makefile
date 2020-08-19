mathQuiz.o: mathQuiz.c
	gcc -c mathQuiz.c -o mathQuiz.o

add.o: add.c
	gcc -c add.c -o add.o

sub.o: sub.c
	gcc -c sub.c -o sub.o

mult.o: mult.c
	gcc -c mult.c -o mult.o

idiv.o: idiv.c
	gcc -c idiv.c -o idiv.o

Quiz: mathQuiz.o add.o sub.o mult.o idiv.o
	gcc mathQuiz.o add.o sub.o mult.o idiv.o -o quiz

clean:
	rm *.o
