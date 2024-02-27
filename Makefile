RED						= \033[0;31m
GREEN					= \033[0;32m
YELLOW					= \033[0;33m
NO_COLOR				= \033[0m

NAME					= bin/fdf

LIBFT_DIR 				= lib/libft
GET_NEXT_LINE_DIR		= lib/get_next_line
PRINTF_DIR 				= lib/printf
MLX42_DIR				= lib/MLX42

LIBFT 					= $(LIBFT_DIR)/libft.a
GET_NEXT_LINE			= $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF 					= $(PRINTF_DIR)/printf.a
MLX42					= $(MLX42_DIR)/build/libmlx42.a
LIBRARIES               = $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX42)

CC						= gcc
INCLUDE_HEADERS			= -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -I$(MLX42_DIR)
CFLAGS 					= -Wall -Werror -Wextra $(INCLUDE_HEADERS)

SOURCE_FILES   			= $(wildcard src/*.c) # Change this eventually
OBJECT_FILES			= $(SOURCE_FILES:src/%.c=obj/%.o)

all: submodules $(NAME)

submodules:
	@if [ -z "$(shell ls lib)" ]; then \
		echo "${YELLOW}Initializing and updating submodules...${NO_COLOR}"; \
		git submodule init; \
		git submodule update; \
	fi

$(NAME): $(LIBRARIES) $(OBJECT_FILES) includes/fdf.h
	@echo "${YELLOW}Linking $(NAME)...${NO_COLOR}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILES) $(LIBRARIES)

$(LIBFT):
	@echo "${GREEN}Making libft...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "${GREEN}Making printf...${NO_COLOR}"
	@$(MAKE) -C $(PRINTF_DIR)

$(GET_NEXT_LINE):
	@echo "${GREEN}Making get_next_line...${NO_COLOR}"
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MLX42):
	@echo "${GREEN}Making MLX42...${NO_COLOR}"
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@$(MAKE) -C $(MLX42_DIR)/build -j4

obj/%.o: src/%.c
	@echo "${YELLOW}Compiling $<...${NO_COLOR}"
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${NO_COLOR}"
	@rm -rf obj
	@echo "${RED}Cleaning libraries...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	@rm -rf $(MLX42_DIR)/build
	
fclean: clean
	@echo "${RED}Removing binaries...${NO_COLOR}"
	@rm -rf bin
	@echo "${RED}Fcleaning libraries...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	
re: fclean all

.PHONY: all submodules clean fclean re