# Makefile - TPE4 Dijkstra
# Théorie des Graphes - L2 GI - ESGC VERECHAGUINE A.K.
# 2025-2026

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC_DIR = src
TEST_DIR = tests
DATA_DIR = data

# Fichiers objets
OBJS = $(SRC_DIR)/graph.o $(SRC_DIR)/bfs_weighted.o $(SRC_DIR)/dijkstra.o

# Exécutables
MAIN = main
TEST_DIJKSTRA = test_dijkstra

# Couleurs pour l'affichage
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m# No Color

.PHONY: all clean help test run

# Cible par défaut
all: $(MAIN)
	@echo "$(GREEN)✓ Compilation réussie !$(NC)"
	@echo "Utilisez 'make run' pour exécuter ou './$(MAIN)'"

# Compilation du programme principal
$(MAIN): $(OBJS) $(SRC_DIR)/main.o
	@echo "$(YELLOW)Liaison de $(MAIN)...$(NC)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des tests
$(TEST_DIJKSTRA): $(OBJS) $(TEST_DIR)/test_dijkstra.o
	@echo "$(YELLOW)Liaison de $(TEST_DIJKSTRA)...$(NC)"
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
	@echo "$(GREEN)Exécution du programme :$(NC)"
	./$(MAIN)

# Tests
test: $(TEST_DIJKSTRA)
	@echo "$(GREEN)═══════════════════════════════════════════════$(NC)"
	@echo "$(GREEN)  TESTS TPE4 - DIJKSTRA$(NC)"
	@echo "$(GREEN)═══════════════════════════════════════════════$(NC)"
	./$(TEST_DIJKSTRA)

# Nettoyage
clean:
	@echo "$(YELLOW)Nettoyage...$(NC)"
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(MAIN) $(TEST_DIJKSTRA)
	@echo "$(GREEN)✓ Nettoyage terminé$(NC)"

# Aide
help:
	@echo "Makefile - TPE4 Dijkstra"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  make          - Compile le programme principal"
	@echo "  make all      - Même chose que 'make'"
	@echo "  make run      - Compile et exécute le programme interactif"
	@echo "  make test     - Compile et lance les 18 tests automatiques"
	@echo "  make clean    - Supprime les fichiers objets et exécutables"
	@echo "  make help     - Affiche cette aide"
	@echo ""
	@echo "Exemples d'utilisation :"
	@echo "  ./main"
	@echo "  ./test_dijkstra"
