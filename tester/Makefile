PIPEX_DIR="../pipex/"
PIPEX="$(PIPEX_DIR)/pipex"
NAME=$(PIPEX)
TESTER="scripts/main"

all: $(PIPEX)
	./$(TESTER)

$(PIPEX):
	make -C $(PIPEX_DIR)

clean:
	make clean -C $(PIPEX_DIR)

fclean: clean
	make fclean -C $(PIPEX_DIR)

re: fclean all
