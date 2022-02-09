output: 2048.o
	info-111 g++ 2048.o -o 2048 -lncurses

main.o: 2048.cpp
	info-111 g++ -c 2048.cpp -lncurses

clean:
	rm *.o 
	rm 2048
