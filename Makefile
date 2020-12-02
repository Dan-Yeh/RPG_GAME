CXX = g++ 
CXXFLAGS = --std=c++17 -Wall
DIR = .

GAME_NAME = RPG_GAME

build: 
	$(CXX) *.cpp -o $(GAME_NAME) $(CXXFLAGS)
clean:
	rm -rf *.o *.out
