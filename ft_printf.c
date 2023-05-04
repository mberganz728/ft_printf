/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:13:46 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/04 18:11:18 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkprc(char const *str, int i, va_list arg, ...)
{
	int	len;

	len = 0;
	if (str[i] == 'c')
		len += print_char(va_arg(arg, int));
	else if (str[i] == 's')
		len += print_str(va_arg(arg, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		len += print_nbr(va_arg(arg, int));
	else if (str[i] == 'u')
		len += print_uns(va_arg(arg, unsigned int));
	else if (str[i] == 'p')
		len += print_ptr(va_arg(arg, void *));
	else if (str[i] == 'x')
		len += print_hexl(va_arg(arg, unsigned int));
	else if (str[i] == 'X')
		len += print_hexu(va_arg(arg, unsigned int));
	else if (str[i] == '%')
		len += print_char(str[i]);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			len += ft_checkprc(str, i, arg);
			i++;
		}
		else
		{
			len += print_char(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (len);
}
/*#include <stdio.h>
int main()
{
    char    c = 'w';
    char    *s = "PATATA";
    int     g = 32;
    int     h = 98;
	void	*p = "Vriña";
    unsigned int m = 257;
	unsigned int hex = 876;
	unsigned int hexu = 52;

    printf("El string es %s, el caracter %c, los enteros %i%d, el unsigned %u, el número hexadecimal %x, el porcentaje: %%, el puntero es %p y otro %% y la hexadecimal mayúscula %X\n", s, c, h, g, m, hex, p, hexu);
    ft_printf("El string es %s, el caracter %c, los enteros %i%d, el unsigned %u, el número hexadecimal %x, el porcentaje: %%, el puntero es %p, y otro %% y la hexadecimal mayúscula %X", s, c, h, g, m, hex, p, hexu);
    return (0);
}*/
