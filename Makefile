RED						= \033[0;31m
GREEN					= \033[0;32m
YELLOW					= \033[0;33m
NO_COLOR				= \033[0m

NAME					= fdf

LIBFT_DIR 				= lib/libft
GET_NEXT_LINE_DIR		= lib/get_next_line
PRINTF_DIR 				= lib/printf

LIBFT 					= $(LIBFT_DIR)/libft.a
GET_NEXT_LINE			= $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF 					= $(PRINTF_DIR)/printf.a

CC						= gcc
CFLAGS 					= -Wall -Werror -Wextra -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GET_NEXT_LINE_DIR)

SOURCE_FILES   			= $(wildcard src/*.c) # Change this eventually
OBJECT_FILES			= $(SOURCE_FILES:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(OBJECT_FILES) includes/fdf.h
	@echo "${YELLOW}Linking $(NAME)...${NC}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o bin/$(NAME) $(OBJECT_FILES) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE)

$(LIBFT):
	@echo "${GREEN}Making libft...${NC}"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "${GREEN}Making printf...${NC}"
	@$(MAKE) -C $(PRINTF_DIR)

$(GET_NEXT_LINE):
	@echo "${GREEN}Making get_next_line...${NC}"
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

obj/%.o: src/%.c
	@echo "${YELLOW}Compiling $<...${NC}"
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${NC}"
	@rm -rf obj
	@echo "${RED}Cleaning libraries...${NC}"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	
fclean: clean
	@echo "${RED}Removing binaries...${NC}"
	@rm -rf bin
	@echo "${RED}Fcleaning libraries...${NC}"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re