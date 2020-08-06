BIN       = ./bin
INCLUDE   = ./include
LIB       = ./lib
OBJ       = ./obj
SRC       = ./src
MAIN      = ./src/main
CPP_LIB   = ./src/cpplib

LIB_FILES  = $(OBJ)/namespaces.o $(OBJ)/polimorfismo.o $(OBJ)/regrados.o $(OBJ)/template_iterator.o $(OBJ)/strutil.o
MAIN_FILES = $(BIN)/namespaces $(BIN)/polimorfismo $(BIN)/regrados $(BIN)/template_iterator

CC    = g++
FLAGS = -O3 -Wall
LIBS  = -L $(LIB) -lm -lcpplearn

all: dirs libcpplean $(MAIN_FILES)

libcpplean: dirs $(LIB_FILES)
	ar -rcs $(LIB)/libcpplearn.a $(OBJ)/*.o

clean:
	rm -rf $(BIN)
	rm -rf $(LIB)
	rm -rf $(OBJ)

dirs:
	mkdir -p $(BIN) $(LIB) $(OBJ)

$(OBJ)/%.o: $(CPP_LIB)/%.cpp $(INCLUDE)/%.hpp
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(MAIN)/%.cpp
	$(CC) $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@
