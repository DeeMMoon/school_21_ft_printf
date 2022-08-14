#include "headers/ft_printf.h"

void	ft_digital_distribution(t_specifier *parametr, va_list *args)
{
	int				number;
	unsigned int	result;

	number = va_arg (*args, int);
	if (number < 0)
	{
		result = -number;
		parametr->minus = 1;
	}
	else
		result = number;
	ft_print_digital(result, 10, parametr);
}

void	ft_distribution(t_specifier *parametr, va_list *args)
{
	char	*string;

	if (parametr->type == 'd' || parametr->type == 'i')
		ft_digital_distribution(parametr, args);
	if (parametr->type == 'c')
		ft_print_char(va_arg(*args, int), parametr);
	if (parametr->type == '%')
		ft_print_char('%', parametr);
	if (parametr->type == 'p')
		ft_print_pointer(va_arg(*args, void *), parametr);
	if (parametr->type == 'u')
		ft_print_digital(va_arg(*args, unsigned int), 10, parametr);
	if (parametr->type == 'X' || parametr->type == 'x')
		ft_print_digital(va_arg(*args, unsigned int), 16, parametr);
	if (parametr->type == 's')
	{
		string = va_arg(*args, char *);
		if (!string)
			string = "(null)";
		ft_print_string(string, parametr);
	}
}
