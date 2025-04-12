APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -g

all: clean libed myapps

libed:\
	$(OBJ)/login.o\

myapps: $(BIN)/main

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.hpp
	g++ -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.cpp $(OBJ)/*.o
	g++ $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(SFMLFLAGS)

run:
	$(BIN)/main

clean:
	rm -rf $(BIN)/* $(OBJ)/* 

clean_apps:
	rm -rf $(BIN)/*