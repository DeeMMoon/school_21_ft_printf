/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types_part_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:23:10 by gantedil          #+#    #+#             */
/*   Updated: 2021/11/10 12:23:10 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf_bonus.h"

int	ft_pointer_lenght(unsigned long long pointer)
{
	int	lenght;

	lenght = 0;
	if (pointer == 0)
		return (3);
	while (pointer > 0)
	{
		pointer = pointer / 16;
		lenght ++;
	}
	return (2 + lenght);
}

void	ft_convert_to_hex(unsigned long long number, t_specifier *parametr)
{
	int	result;

	if (parametr->nul == 1)
		return ;
	if (number < 16)
	{
		if (number >= 10)
			result = number - 10 + 'a';
		else
			result = number + '0';
		ft_print_symbol(parametr, result);
	}
	else
	{
		ft_convert_to_hex (number / 16, parametr);
		ft_convert_to_hex (number % 16, parametr);
	}
}

void	ft_print_pointer(void *pointer, t_specifier *paramet)
{
	unsigned long long	number;
	int					pointer_lenght;

	number = (unsigned long long) pointer;
	if (pointer == NULL)
		number = 0;
	pointer_lenght = ft_pointer_lenght(number);
	if (pointer == NULL && paramet->accuracy == 0)
	{
		paramet->nul = 1;
		pointer_lenght = 2;
	}
	ft_print_pointer_continue (number, pointer_lenght, paramet);
}

void	ft_print_pointer_continue(unsigned long long number,
	int pointer_lenght, t_specifier *parametr)
{
	if (parametr->flag == '0')
	{
		ft_print_str("0x", parametr, pointer_lenght);
		ft_print_width(parametr, pointer_lenght);
		ft_convert_to_hex(number, parametr);
	}
	else if (parametr->flag == '-')
	{
		ft_print_str("0x", parametr, pointer_lenght);
		ft_convert_to_hex(number, parametr);
		ft_print_width(parametr, pointer_lenght);
	}
	else
	{
		ft_print_width(parametr, pointer_lenght);
		ft_print_str("0x", parametr, pointer_lenght);
		ft_convert_to_hex(number, parametr);
	}
}
