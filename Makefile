# Compiler settings
CXX := g++
CXX_FLAGS := -Wall -Wextra -g -std=c++17 

# Directories
BIN := bin
SRC := src
INCLUDE := C:\SFML\SFML_VSC\SFML-2.6.0/include
LIB := C:\SFML\SFML_VSC\SFML-2.6.0/lib

# STATICALLY COMPILATION FLAGS
SFML_FLAGS:= SFML_STATIC  

# SFML static libraries (STATICALLY COMPILATION)
SFML_STATIC_LIBRARIES := -L$(LIB) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio -lopengl32 -lfreetype -lwinmm -lgdi32 

# Source files
SRCS := $(wildcard $(SRC)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC)/%.cpp,$(BIN)/%.o,$(SRCS))

# Executable name
EXECUTABLE := app.exe

all: compile link run

run:
	cmd /c "$(BIN)\$(EXECUTABLE)"

compile: $(OBJS)

$(BIN)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -c $< -o $@ -D$(SFML_FLAGS)

link: $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(BIN)/$(EXECUTABLE) $^ $(SFML_STATIC_LIBRARIES)

clean:
	rm  $(BIN)/*.*