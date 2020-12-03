##add memory check /test / debug command
CXX = g++ 
CXXFLAGS = --std=c++17 -Wall

#location of files
SRC = ../src
INCLUDE = ../include
OBJ_DIR = objects
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(patsubst $(SRC)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
HEADERS = $(wildcard $(INCLUDE)/*.h)

GAME_NAME = ../RPG_GAME

build: $(OBJECTS) $(HEADERS)
	echo $(OBJECTS)
	$(CXX) -o $(GAME_NAME) $(CXXFLAGS) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ_DIR)
	rm $(GAME_NAME)
