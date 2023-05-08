/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:15:51 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/08 10:58:57 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = i + 1;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_nbr(int n)
{
	int	mod;
	int	len;

	len = ft_intlen(n);
	mod = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		print_nbr(-n);
	}
	else
	{
		if (n > 9)
			print_nbr(n / 10);
		mod = n % 10 + 48;
		write(1, &mod, 1);
	}
	return (len);
}

/*int print_nbr(int n)
{
    int     len;
    char    *str;

    str = ft_itoa(n);
    print_str(str);
    len = ft_strlen(str);
    free (str);
    return (len);
}*/

/*#include <stdio.h>
int	main()
{
	print_nbr(-1);
	return (0);
}*/
