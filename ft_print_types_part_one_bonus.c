#include "headers/ft_printf_bonus.h"

void	ft_print_digital(unsigned int number, int base, t_specifier *parametr)
{
	int	zeros;
	int	number_lenght;

	zeros = 0;
	number_lenght = ft_number_lenght(number, base);
	if (number == 0 && parametr->accuracy == 0)
	{
		number_lenght --;
		parametr->nul = 1;
	}
	if (parametr->accuracy >= 0 && parametr->flag == '0')
		parametr->flag = 0;
	if (parametr->accuracy > number_lenght)
	{
		zeros = parametr->accuracy - number_lenght;
		number_lenght = parametr->accuracy;
	}
	if (parametr->minus == 1)
		number_lenght ++;
	ft_print_digital_continuation(number, number_lenght, zeros, parametr);
}

void	ft_print_digital_continuation(unsigned int number, int number_lenght,
int zeros, t_specifier *parametr)
{
	int	base;

	base = 10;
	if (parametr->type == 'x' || parametr->type == 'X')
		base = 16;
	if (parametr->flag == '0')
	{
		ft_print_minus(parametr);
		ft_print_width(parametr, number_lenght);
		ft_print_a_n(number, base, zeros, parametr);
	}
	else if (parametr->flag == '-')
	{
		ft_print_minus(parametr);
		ft_print_a_n(number, base, zeros, parametr);
		ft_print_width(parametr, number_lenght);
	}
	else
	{
		ft_print_width(parametr, number_lenght);
		ft_print_minus(parametr);
		ft_print_a_n(number, base, zeros, parametr);
	}
}

void	ft_print_a_n(unsigned int number, int base,
int zeros, t_specifier *parametr)
{
	ft_print_accuracy(parametr, zeros);
	if (parametr->flag == '+' && parametr->minus == 0)
		ft_print_symbol(parametr, '+');
	if (parametr->space == ' ' && parametr->minus == 0
		&& parametr->flag != '+')
		ft_print_symbol(parametr, ' ');
	if (base == 16 && number != 0 && parametr->flag == '#')
	{
		if (parametr->type == 'x')
			ft_print_str("0x", parametr, 2);
		if (parametr->type == 'X')
			ft_print_str("0X", parametr, 2);
	}
	ft_print_number(number, base, parametr);
}

void	ft_print_char(char symbol, t_specifier *parametr)
{
	if (parametr->flag == '-')
	{
		ft_print_symbol(parametr, symbol);
		ft_print_width(parametr, 1);
	}
	else
	{
		ft_print_width(parametr, 1);
		ft_print_symbol(parametr, symbol);
	}
}

void	ft_print_string(char *string, t_specifier *parametr)
{
	int	string_lenght;

	string_lenght = ft_string_lenght(string);
	if (parametr->accuracy >= 0 && parametr->accuracy < string_lenght)
		string_lenght = parametr->accuracy;
	if (parametr->flag == '-')
	{
		ft_print_str(string, parametr, string_lenght);
		ft_print_width(parametr, string_lenght);
	}
	else
	{
		ft_print_width(parametr, string_lenght);
		ft_print_str(string, parametr, string_lenght);
	}
}
