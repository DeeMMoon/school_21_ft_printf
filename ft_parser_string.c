/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:25:37 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 19:47:27 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

void	ft_parametr_inition(t_specifier *parametr)
{
	parametr->minus = 0;
	parametr->accuracy = -1;
	parametr->flag = 0;
	parametr->type = 0;
	parametr->width = 0;
	parametr->nul = 0;
	parametr->space = 0;
}

void	ft_parsing_flag_and_width(const char **string, t_specifier *parametr)
{
	char	minus;

	minus = 0;
	ft_parametr_inition(parametr);
	while (**string == '-' || **string == '0' || **string == '#'
		|| **string == '+' || **string == ' ')
	{
		if (**string == '-')
			minus = '-';
		if (**string == '0')
			parametr->flag = '0';
		if (**string == '#')
			parametr->flag = '#';
		if (**string == '+')
			parametr->flag = '+';
		if (**string == ' ')
			parametr->space = ' ';
		(*string)++;
	}
	if (minus == '-')
		parametr->flag = '-';
	parametr->width = ft_atoi_in_string(string);
}

void	ft_parsing_accuracy_and_type(const char **string, t_specifier *parametr)
{
	if (**string == '.')
	{
		(*string)++;
		parametr->accuracy = 0;
		parametr->accuracy = ft_atoi_in_string(string);
	}
	if (**string == 'd' || **string == 'c' || **string == 's'
		|| **string == 'p' || **string == 'x' || **string == 'X'
		|| **string == 'i' || **string == 'u' || **string == '%')
		parametr->type = **string;
	if (**string == '\0')
		parametr->count = -1;
}

void	ft_parsing_string(const char **string, t_specifier *parametr)
{
	ft_parsing_flag_and_width(string, parametr);
	ft_parsing_accuracy_and_type(string, parametr);
}

int	ft_atoi_in_string(const char **string)
{
	int	result;

	result = 0;
	if (!**string)
		return (0);
	while (**string >= '0' && **string <= '9')
	{
		result = result * 10 + (**string - '0');
		(*string)++;
	}
	return (result);
}
