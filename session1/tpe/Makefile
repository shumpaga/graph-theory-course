# Makefile pour TPE1 - Théorie des Graphes
# ESGC VERECHAGUINE A.K. - GI2

# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I src

# Fichiers
TARGET = test_graph
SRCS = src/graph.cpp src/main.cpp
TEST_SRCS = src/graph.cpp tests/test_graph.cpp
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Lien
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Exécution des tests
test: test_runner
	./test_runner

test_runner: $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_SRCS)

# Nettoyage
clean:
	rm -f $(TARGET) test_runner src/*.o tests/*.o

# Aide
help:
	@echo "Commandes disponibles:"
	@echo "  make       - Compile le projet"
	@echo "  make test  - Compile et exécute les tests"
	@echo "  make clean - Supprime les fichiers générés"
	@echo "  make help  - Affiche cette aide"

.PHONY: all test clean help
