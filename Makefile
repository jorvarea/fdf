RED						= \033[0;31m
GREEN					= \033[0;32m
YELLOW					= \033[0;33m
NO_COLOR				= \033[0m

NAME					= bin/fdf

LIBFT_DIR 				= lib/libft
GET_NEXT_LINE_DIR		= lib/get_next_line
PRINTF_DIR 				= lib/printf
MLX42_DIR				= lib/MLX42/build

LIBFT 					= $(LIBFT_DIR)/libft.a
GET_NEXT_LINE			= $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF 					= $(PRINTF_DIR)/printf.a
MLX42					= $(MLX42_DIR)/build/libmlx42.a
LIBRARIES               = $(LIBFT) $(PRINTF) $(GET_NEXT_LINE)

CC						= gcc
CFLAGS 					= -Wall -Werror -Wextra -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -I$(MLX42_DIR)
LDFLAGS 				= -L$(MLX42_DIR) -lmlx42 -framework OpenGL -framework AppKit

SOURCE_FILES   			= $(wildcard src/*.c) # Change this eventually
OBJECT_FILES			= $(SOURCE_FILES:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(LIBRARIES) $(OBJECT_FILES) includes/fdf.h
	@echo "${YELLOW}Linking $(NAME)...${NO_COLOR}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILES) $(LIBRARIES) $(LDFLAGS)

$(LIBFT):
	@echo "${GREEN}Making libft...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "${GREEN}Making printf...${NO_COLOR}"
	@$(MAKE) -C $(PRINTF_DIR)

$(GET_NEXT_LINE):
	@echo "${GREEN}Making get_next_line...${NO_COLOR}"
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

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
	@$(MAKE) -C $(MLX42_DIR) clean
	
fclean: clean
	@echo "${RED}Removing binaries...${NO_COLOR}"
	@rm -rf bin
	@echo "${RED}Fcleaning libraries...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	@$(MAKE) -C $(MLX42_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re