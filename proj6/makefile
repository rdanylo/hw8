# builds proj6
CC = g++
CFLAGS = -Wall

main.o: main.cc othello.h
	$(CC) $(CFLAGS) -c main.cc

game.o: game.cc game.h
	$(CC) $(CFLAGS) -c game.cc
    
othello.o: othello.cc othello.h colors.h game.h space.h
	$(CC) $(CFLAGS) -c othello.cc

proj6: main.o game.o othello.o
	$(CC) $(CFLAGS) -o proj6 main.o game.o othello.o
    
clean:
	rm -f proj6 *.o