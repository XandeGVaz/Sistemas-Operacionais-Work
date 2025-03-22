APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: clean libed myapps

libed:\
	$(OBJ)/source.o\

myapps: $(BIN)/main

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	g++ -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.cpp $(OBJ)/*.o
	g++ $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
	$(BIN)/main

clean:
	rm -rf $(BIN)/* $(OBJ)/* 

clean_apps:
	rm -rf $(BIN)/*