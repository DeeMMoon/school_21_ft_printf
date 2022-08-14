/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsidiary_realisation_part_two.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:32:42 by gantedil          #+#    #+#             */
/*   Updated: 2021/11/10 12:32:42 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf_bonus.h"

void	ft_print_minus(t_specifier *parametr)
{
	if (parametr->minus == 1)
		ft_print_symbol(parametr, '-');
}

void	ft_print_width(t_specifier *parametr, int lenght)
{
	while (parametr->width > lenght)
	{
		if (parametr->flag == '0')
			ft_print_symbol(parametr, '0');
		else
			ft_print_symbol(parametr, ' ');
		lenght ++;
	}
}

void	ft_print_accuracy(t_specifier *parametr, int zeros)
{
	while (zeros != 0)
	{
		ft_print_symbol(parametr, '0');
		zeros --;
	}
}

int	ft_string_lenght(char *string)
{
	int	i;

	i = 0;
	while (string [i])
		i++;
	return (i);
}
