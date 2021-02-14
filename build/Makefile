##add memory check /test / debug command
#CMake
gprof: export EXTRA_CXXFLAGS := -D TEST -pg

CXX = g++
CXXFLAGS = --std=c++17 -Wall $(EXTRA_CXXFLAGS)

#location of files
SRC = ../src
INCLUDE = ../include
FACTORY = ../Factory
UTILS = ../Utilities
SAVEFOLDER = ../saves
OBJ_DIR = objects
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(patsubst $(SRC)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
HEADERS = $(wildcard $(INCLUDE)/*.h)
HEADERS += $(wildcard $(FACTORY)/*.h)
HEADERS += $(wildcard $(UTILS)/*.h)

GAME_NAME = ../RPG_GAME

build: $(OBJECTS) $(HEADERS)
	mkdir -p ${SAVEFOLDER}
	echo $(OBJECTS)
	$(CXX) -o $(GAME_NAME) $(CXXFLAGS) $(OBJECTS)

gprof: $(OBJECTS) $(HEADERS)
	mkdir -p ${SAVEFOLDER}
	echo $(OBJECTS)
	$(CXX) -o $(GAME_NAME) $(CXXFLAGS) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf ${SAVEFOLDER}
	rm $(GAME_NAME)
