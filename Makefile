
output: 2048.o
	g++ 2048.o -o output -lncurses

main.o: 2048.cpp
	g++ -c 2048.cpp -lncurses

clean:
	rm *.o output
