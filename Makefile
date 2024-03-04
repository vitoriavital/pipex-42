# Colors
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

# Target and Compiler Settings
NAME        := pipex
CC          := cc
CFLAGS      := -Wextra -Wall -Werror

# Source Files
SRCS        := srcs/main.c srcs/evaluate.c srcs/utils.c srcs/execute.c srcs/errors.c srcs/validation.c
SRCS_BONUS  := srcs_bonus/main.c srcs_bonus/evaluate.c srcs_bonus/utils.c srcs_bonus/execute.c srcs_bonus/errors.c srcs_bonus/validation.c srcs_bonus/evaluate_multiple.c srcs_bonus/here_doc.c
OBJS_PATH   := ./objs
OBJS_PATH_BONUS := ./objs_bonus
OBJS        := $(patsubst srcs/%.c,$(OBJS_PATH)/%.o,$(SRCS))
OBJS_BONUS  := $(patsubst srcs_bonus/%.c,$(OBJS_PATH_BONUS)/%.o,$(SRCS_BONUS))
INCLUDE := include

# libs #
INCLUDES = -I$(INCLUDE)/ -Ilib/libft/include/
LINCLUDES = -L$(LIBFT_PATH) -lft

LIBFT = lib/libft/libft.a
LIBFT_PATH = lib/libft

# Targets
all: $(OBJS_PATH) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINCLUDES) -o $@
	@echo "${GREEN}Compilation completed.${NC}"

$(OBJS_PATH)/%.o: ./srcs/%.c $(INCLUDE)/pipex.h | $(OBJS_PATH)
	@echo "${YELLOW}Compiling $<.${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_PATH_BONUS)/%.o: ./srcs_bonus/%.c $(INCLUDE)/pipex_bonus.h | $(OBJS_PATH_BONUS)
	@echo "${YELLOW}Compiling bonus $<.${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH_BONUS):
	@mkdir -p $(OBJS_PATH_BONUS)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_PATH)
	@echo "${YELLOW}Libft Compiled.${NC}"

clean:
	@rm -rf $(OBJS_PATH) $(OBJS_PATH_BONUS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@echo "${YELLOW}Cleaning objects.${NC}"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME)_bonus
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "${YELLOW}Cleaning executables.${NC}"

bonus: $(OBJS_PATH_BONUS) $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BONUS) $(LINCLUDES) -o $(NAME)_bonus
	@echo "${GREEN}Compilation bonus completed.${NC}"

re: fclean all

.PHONY: all clean fclean re
