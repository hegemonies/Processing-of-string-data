all: main

main: main.o strings/strings.o
	gcc -Wall -Werror -I strings main.o strings/strings.o -o main -g -O2

main.o: main.c
	gcc -Wall -Werror -I strings -c main.c -o main.o -g

strings/strings.o: strings/strings.c
	gcc -Wall -Werror -I strings -c strings/strings.c -o strings/strings.o -g

.PHONY: clean

clean:
	rm main *.o strings/*.o
