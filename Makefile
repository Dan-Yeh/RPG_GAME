CC = g++ 
CFLAGS = --std=c++17
DIR = .

GAME_NAME = RPG_GAME

build: 
	$(CC) *.cpp -o $(GAME_NAME) $(CFLAGS)
clean:
	rm -rf *.o *.out
