BIN       = ./bin
INCLUDE   = ./include
LIB       = ./lib
OBJ       = ./obj
SRC       = ./src
MAIN      = ./src/main
CPP_LIBS  = ./src/cpplibs

LIBS_FILES  = $(OBJ)/namespaces.o
MAIN_FILES  = $(BIN)/namespaces

CC    = g++
FLAGS = -O3 -Wall
LIBS  = -L $(LIB) -lm -lcpplean

all: dirs libcpplean $(MAIN_FILES)

libcpplean: dirs $(LIBS_FILES)
		ar -rcs $(LIB)/libcpplearn.a $(OBJ)/*.o

clean:
		rm -rf $(BIN)
		rm -rf $(LIB)
		rm -rf $(OBJ)

dirs:
		mkdir -p $(BIN) $(LIB) $(OBJ)

$(OBJ)/%.o: $(CPP_LIBS)/%.cpp $(INCLUDE)/%.hpp
		$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(MAIN)/%.cpp
		$(CC) $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@
