NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rsc

SRCS = printdigs.c \
		printchars.c \
		ft_printf.c

BONUS_SRCS = bonus/ft_printf_bonus.c \
		bonus/ft_utils_bonus.c \
		bonus/ft_print_chars_bonus.c \
		bonus/ft_print_nbr_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(NAME) .bonus
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(BONUS_OBJS)
	rm -f $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	touch .bonus

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean bonus
