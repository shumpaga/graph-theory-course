CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I include
SRC = src
BIN = bin

SRCS_MAIN = $(SRC)/graph.cpp $(SRC)/bfs.cpp $(SRC)/dfs.cpp $(SRC)/main.cpp
SRCS_TEST = $(SRC)/graph.cpp $(SRC)/bfs.cpp $(SRC)/dfs.cpp tests/test_tp1.cpp

.PHONY: all test clean run help

all: $(BIN)/main

$(BIN)/main: $(SRCS_MAIN) | $(BIN)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS_MAIN)

test: $(BIN)/test_tp1
	./$(BIN)/test_tp1

$(BIN)/test_tp1: $(SRCS_TEST) | $(BIN)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS_TEST)

$(BIN):
	mkdir -p $(BIN)

run: $(BIN)/main
	./$(BIN)/main

clean:
	rm -rf $(BIN)

help:
	@echo "Makefile — TP1 Bonus RéseauVAK"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  make          - Compile le programme principal"
	@echo "  make test     - Compile et lance les 20 tests"
	@echo "  make run      - Compile et exécute le programme"
	@echo "  make clean    - Supprime le dossier bin/"
	@echo "  make help     - Affiche cette aide"
