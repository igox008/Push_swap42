RESET=\033[0m
BOLD=\033[1m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m

BG_RED=\033[41m
BG_GREEN=\033[42m
BG_YELLOW=\033[43m
BG_BLUE=\033[44m
BG_MAGENTA=\033[45m
BG_CYAN=\033[46m
BG_WHITE=\033[47m

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
BNAME = checker

HEADER = push_swap.h ft_printf/ft_printf.h libft/libft.h

BTHEADER = push_swap_bonus.h ft_printf/ft_printf.h libft/libft.h get_next_line/get_next_line.h

PRINTF = ft_printf/ft_printf.c ft_printf/ft_putchar_prnt.c ft_printf/ft_putnbr_base.c ft_printf/ft_putstr_prnt.c ft_printf/ft_strlen_prnt.c ft_printf/print_addr.c

LIBFT = libft/ft_atoi.c libft/ft_isdigit.c libft/ft_lstdelone_bonus.c libft/ft_memchr.c libft/ft_putendl_fd.c libft/ft_striteri.c libft/ft_strncmp.c libft/ft_toupper.c \
	libft/ft_bzero.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_putnbr_fd.c libft/ft_strjoin.c libft/ft_strnstr.c \
	libft/ft_calloc.c libft/ft_itoa.c libft/ft_lstlast_bonus.c libft/ft_memcpy.c libft/ft_putstr_fd.c libft/ft_strlcat.c libft/ft_strrchr.c \
	libft/ft_isalnum.c libft/ft_lstadd_back_bonus.c libft/ft_memmove.c libft/ft_split.c libft/ft_strlcpy.c libft/ft_strtrim.c \
	libft/ft_isalpha.c libft/ft_lstadd_front_bonus.c libft/ft_lstnew_bonus.c libft/ft_memset.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_substr.c \
	libft/ft_isascii.c libft/ft_lstclear_bonus.c libft/ft_lstsize_bonus.c libft/ft_putchar_fd.c libft/ft_strdup.c libft/ft_strmapi.c libft/ft_tolower.c

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC = push_swap.c utils/init.c utils/utils1.c utils/parse.c moves/pushes.c moves/shiftes.c \
	moves/swap_moves.c utils/utils2.c utils/sort1.c utils/sort2.c $(PRINTF) $(LIBFT)

BSRC = " utils_bonus/checker.c utils_bonus/init.c utils_bonus/parse.c utils_bonus/utils1.c utils_bonus/utils2.c moves/shiftes.c \
	moves/swap_moves.c moves/pushes.c utils_bonus/list_man.c $(PRINTF) $(LIBFT) $(GNL)"

OBJ = $(SRC:.c=.o)

BTOBJ = $(shell echo "$(BSRC)" | sed 's/ / bonus\//g')

BHEADER = $(shell echo "$(BTHEADER)" | sed 's/ / bonus\//g')
BOBJ = $(BTOBJ:.c=_b.o)

all : $(NAME)
bonus : $(BNAME)

$(NAME) : $(OBJ) $(HEADER)
	@echo "$(BG_YELLOW)building $@...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(BG_GREEN)$@ is ready to use!!$(RESET)"

$(BNAME) : $(BOBJ) $(BHEADER)
	@echo "$(BG_YELLOW)building $@...$(RESET)"
	@$(CC) $(CFLAGS) $(BOBJ) -o $@
	@echo "$(BG_GREEN)$@ is ready to use!!$(RESET)"

%_b.o : %_b.c $(BHEADER)
	@echo "$(BG_BLUE)$(BOLD)compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

push_%.o : push_%.c $(HEADER)
	@echo "$(BG_BLUE)$(BOLD)compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

utils/%.o : utils/%.c $(HEADER)
	@echo "$(BG_BLUE)$(BOLD)compiling utils$<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

moves/%.o : moves/%.c $(HEADER)
	@echo "$(BG_BLUE)$(BOLD)compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

libft/%.o : libft/%.c $(HEADER)
	@echo "$(BG_BLUE)$(BOLD)compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

ft_printf/%.o : ft_printf/%.c $(HEADER)
	@echo "$(BG_BLUE)$(BOLD)compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "$(BOLD)$(BG_RED)deleting object files...$(RESET)"
	@$(RM) $(OBJ) $(BOBJ)
	@echo "$(RED)object files deleted successfully$(RESET)"

fclean : clean
	@echo "$(BOLD)$(BG_RED)deleting executables...$(RESET)"
	@$(RM) $(NAME) $(BNAME)
	@echo "$(RED)executables deleted successfully$(RESET)"

re : fclean all
.PHONY: clean