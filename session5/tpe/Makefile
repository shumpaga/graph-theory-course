# Makefile - TPE5 Kruskal & Union-Find
# Théorie des Graphes - L2 GI - ESGC VERECHAGUINE A.K.
# 2025-2026

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Iinclude
SRC_DIR = src
TEST_DIR = tests

# Fichiers objets
OBJS = $(SRC_DIR)/graph.o $(SRC_DIR)/union_find.o $(SRC_DIR)/mst.o

# Exécutables
MAIN = main
TEST_MST = test_mst

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
$(TEST_MST): $(OBJS) $(TEST_DIR)/test_mst.o
	@echo "$(YELLOW)Liaison de $(TEST_MST)...$(NC)"
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
test: $(TEST_MST)
	@echo "$(GREEN)═══════════════════════════════════════════════$(NC)"
	@echo "$(GREEN)  TESTS TPE5 - KRUSKAL$(NC)"
	@echo "$(GREEN)═══════════════════════════════════════════════$(NC)"
	./$(TEST_MST)

# Nettoyage
clean:
	@echo "$(YELLOW)Nettoyage...$(NC)"
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(MAIN) $(TEST_MST)
	@echo "$(GREEN)✓ Nettoyage terminé$(NC)"

# Aide
help:
	@echo "Makefile - TPE5 Kruskal & Union-Find"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  make          - Compile le programme principal"
	@echo "  make all      - Même chose que 'make'"
	@echo "  make run      - Compile et exécute le programme interactif"
	@echo "  make test     - Compile et lance les 20 tests automatiques"
	@echo "  make clean    - Supprime les fichiers objets et exécutables"
	@echo "  make help     - Affiche cette aide"
	@echo ""
	@echo "Exemples d'utilisation :"
	@echo "  ./main"
	@echo "  ./test_mst"
