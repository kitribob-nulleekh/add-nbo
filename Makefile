all: add-hbo

add-hbo: main.o
	g++ -o add-hbo main.o

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -f sum_test *.o
