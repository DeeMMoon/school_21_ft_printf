CC = gcc

SOURCES = ft_printf.c ft_distribution.c ft_parser_string.c ft_print_types_part_one.c ft_print_types_part_two.c ft_subsidiary_realisation_part_one.c ft_subsidiary_realisation_part_two.c 

SOURCES_B = ft_printf_bonus.c ft_distribution_bonus.c ft_parser_string_bonus.c ft_print_types_part_one_bonus.c ft_print_types_part_two_bonus.c ft_subsidiary_realisation_part_one_bonus.c ft_subsidiary_realisation_part_two_bonus.c

OBJECTS = $(SOURCES:%.c=%.o)

OBJECTS_B = $(SOURCES_B:%.c=%.o)

HEADER = headers

HEADER_B = headers

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra -I$(HEADER)/*.h

.PHONY: all clean fclean re bonus

all	: $(NAME)

$(NAME)	: $(OBJECTS) $(HEADER)/*.h
	ar rcs $(NAME) $?

%.o	: %.c $(HEADER)/*.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: $(OBJECTS_B) $(HEADER_B)/*.h
	ar rcs $(NAME) $?

%.o	: %.c $(HEADER)/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean	: clean
	rm -f $(NAME)

re	:  fclean all
