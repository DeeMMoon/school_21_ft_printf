/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:59:21 by gantedil          #+#    #+#             */
/*   Updated: 2022/08/14 19:47:37 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list		args;
	t_specifier	parametr;

	if (!string)
		return (-1);
	parametr.count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%' && *(++string))
		{
			ft_parsing_string(&string, &parametr);
			if (parametr.count == -1)
			{
				va_end(args);
				return (-1);
			}
			ft_distribution(&parametr, &args);
		}
		else
			ft_print_symbol(&parametr, *string);
		string ++;
	}
	va_end(args);
	return (parametr.count);
}
