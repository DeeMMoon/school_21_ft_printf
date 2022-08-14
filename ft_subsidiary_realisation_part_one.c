/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsidiary_realisation_part_one.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:29:44 by gantedil          #+#    #+#             */
/*   Updated: 2021/11/10 12:29:44 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

void	ft_print_symbol(t_specifier *parametr, char symbol)
{
	parametr->count ++;
	write(1, &symbol, 1);
}

int	ft_number_lenght(unsigned int number, int base)
{
	int	lenght;

	lenght = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number = number / base;
		lenght ++;
	}
	return (lenght);
}

void	ft_print_str(char *string, t_specifier *parametr, int string_lenght)
{
	if (string)
	{
		while (string_lenght && *string)
		{
			ft_print_symbol(parametr, *string++);
			string_lenght--;
		}
	}
}

void	ft_print_number(unsigned int number, int base, t_specifier *parametr)
{
	int	result;
	int	upper_symbol;

	if (parametr->nul == 1)
		return ;
	upper_symbol = 0;
	if (parametr->type == 'X')
		upper_symbol = 'a' - 'A';
	if (number < (unsigned int) base)
	{
		if (number >= 10)
			result = number - 10 + 'a' - upper_symbol;
		else
			result = number + '0';
		ft_print_symbol (parametr, result);
	}
	if (number >= (unsigned int) base)
	{
		ft_print_number(number / base, base, parametr);
		ft_print_number(number % base, base, parametr);
	}
}
