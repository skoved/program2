GXX=g++
FLAGS=-std=c++11 -g

all: program2

program2: deck.o card.o heap.o player.o program2.o
	$(GXX) $(FLAGS) deck.o card.o heap.o player.o program.o -o program2

deck.o: Deck.cpp Deck.h
	$(GXX) $(FLAGS) -c Deck.cpp -o deck.o

card.o: Card.cpp Card.h
	$(GXX) $(FLAGS) -c Card.cpp -o card.o

heap.o: Heap.cpp Heap.h
	$(GXX) $(FLAGS) -c Heap.cpp -o heap.o

player.o: Player.cpp Player.h
	$(GXX) $(FLAGS) -c Player.cpp -o player.o

program2.o: program2.cpp
	$(GXX) $(FLAGS) -c program2.cpp -o program2.o

clean:
	rm *.o program2
