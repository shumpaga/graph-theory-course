# Makefile - TPE2 BFS
# Théorie des Graphes - L2 GI - ESGC VERECHAGUINE A.K.
# 2025-2026

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC_DIR = src
TEST_DIR = tests
DATA_DIR = data

# Fichiers objets
OBJS = $(SRC_DIR)/graph.o $(SRC_DIR)/queue.o $(SRC_DIR)/bfs.o

# Exécutables
MAIN = main
TEST_BFS = test_bfs

# Couleurs pour l'affichage
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m# No Color

.PHONY: all clean help test run

# Cible par défaut
all: $(MAIN)
	@echo "$(GREEN)✓ Compilation réussie !$(NC)"
	@echo "Utilisez 'make run' pour exécuter ou './$(MAIN) $(DATA_DIR)/graph_simple.txt'"

# Compilation du programme principal
$(MAIN): $(OBJS) $(SRC_DIR)/main.o
	@echo "$(YELLOW)Liaison de $(MAIN)...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des tests
$(TEST_BFS): $(OBJS) $(TEST_DIR)/test_bfs.o
	@echo "$(YELLOW)Liaison de $(TEST_BFS)...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règles de compilation des fichiers objets
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "$(YELLOW)Compilation de $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo "$(YELLOW)Compilation de $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Exécution
run: $(MAIN)
	@echo "$(GREEN)Exécution avec graph_simple.txt :$(NC)"
	./$(MAIN) $(DATA_DIR)/graph_simple.txt

# Tests
test: $(TEST_BFS)
	@echo "$(GREEN)═══════════════════════════════════════$(NC)"
	@echo "$(GREEN)  TESTS TPE2 - BFS$(NC)"
	@echo "$(GREEN)═══════════════════════════════════════$(NC)"
	./$(TEST_BFS)

# Nettoyage
clean:
	@echo "$(YELLOW)Nettoyage...$(NC)"
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(MAIN) $(TEST_BFS)
	@echo "$(GREEN)✓ Nettoyage terminé$(NC)"

# Aide
help:
	@echo "Makefile - TPE2 BFS"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  make          - Compile le programme principal"
	@echo "  make all      - Même chose que 'make'"
	@echo "  make run      - Compile et exécute avec graph_simple.txt"
	@echo "  make test     - Compile et lance les tests"
	@echo "  make clean    - Supprime les fichiers objets et exécutables"
	@echo "  make help     - Affiche cette aide"
	@echo ""
	@echo "Exemples d'utilisation :"
	@echo "  ./main data/graph_simple.txt"
	@echo "  ./main data/graph_cotonou.txt"
	@echo "  ./test_bfs"
