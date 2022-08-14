/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gantedil <gantedil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:39:07 by gantedil          #+#    #+#             */
/*   Updated: 2021/11/13 14:53:02 by gantedil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_specifier
{
	char	flag;
	int		width;
	int		accuracy;
	char	type;
	int		minus;
	int		nul;
	int		count;
	int		space;
}				t_specifier;

int		ft_printf(const char *string, ...);
void	ft_digital_distribution(t_specifier *parametr, va_list *args);
void	ft_distribution(t_specifier *parametr, va_list *args);
void	ft_parametr_inition(t_specifier *parametr);
void	ft_parsing_flag_and_width(const char **string,
			t_specifier *parametr);
void	ft_parsing_accuracy_and_type(const char **string,
			t_specifier *parametr);
void	ft_parsing_string(const char **string, t_specifier *parametr);
void	ft_print_str(char *string, t_specifier *parametr, int string_lenght);
int		ft_atoi_in_string(const char **string);
void	ft_print_digital(unsigned int number, int base, t_specifier *parametr);
void	ft_print_digital_continuation(unsigned int number, int number_lenght,
			int zeros, t_specifier *parametr);
void	ft_print_symbol(t_specifier *parametr, char symbol);
int		ft_number_lenght(unsigned int number, int base);
void	ft_print_string(char *string, t_specifier *parametr);
void	ft_print_number(unsigned int number, int base, t_specifier *parametr);
void	ft_print_minus(t_specifier *parametr);
void	ft_print_width(t_specifier *parametr, int lenght);
void	ft_print_accuracy(t_specifier *parametr, int zeros);
int		ft_string_lenght(char *string);
void	ft_print_char(char symbol, t_specifier *parametr);
int		ft_pointer_lenght(unsigned long long pointer);
void	ft_convert_to_hex(unsigned long long number, t_specifier *parametr);
void	ft_print_pointer(void *pointer, t_specifier *paramet);
void	ft_print_pointer_continue(unsigned long long number, int pointer_lenght,
			t_specifier *parametr);
void	ft_print_a_n(unsigned int number, int base,
			int zeros, t_specifier *parametr);

#endif