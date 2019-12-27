CC=g++
EXE_FILE=goFish

all: $ (EXE_FILE)

$ (EXE_FILE): card.o deck.o hand.o player.o game.o card.hpp deck.hpp hand.hpp player.hpp game.hpp go_fish.cpp
	$(CC) card.o deck.o hand.o player.o game.o go_fish.cpp -std=c++11 -o $(EXE_FILE)

card.o: card.hpp card.cpp
	$(CC) -c card.cpp

deck.o: deck.hpp deck.cpp
	$(CC) -c deck.cpp

hand.o: hand.hpp hand.cpp
	$(CC) -c hand.cpp

player.o: player.hpp player.cpp
	$(CC) -c player.cpp

game.o: game.hpp game.cpp
	$(CC) -c game.cpp -std=c++11

clean:
	rm -f *.o $(EXE_FILE)
