CXX = g++
CXXFLAGS = -std=c++11 -g -Wall `sdl2-config --cflags` -Iinclude
LDFLAGS = `sdl2-config --libs` -lGL -lGLEW
SRC_DIR = source
OBJ_DIR = obj
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = $(BUILD_DIR)/out
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Compilation terminée avec succès ! L'exécutable est disponible dans $(BUILD_DIR)/out."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)
