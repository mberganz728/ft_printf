/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:16:15 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/08 11:35:06 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(size_t n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

static void	print_hex(size_t n)
{
	if (n >= 16)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else
	{
		if (n < 10)
		{
			n = n + 48;
			write (1, &n, 1);
		}
		else if (n < 16 && n > 9)
		{
			n = n - 10 + 'a';
			write (1, &n, 1);
		}
	}
}

int	print_ptr(void *ptr)
{
	int		len;
	size_t	n;

	write (1, "0x", 2);
	n = (size_t)ptr;
	len = ft_intlen(n);
	print_hex(n);
	return (len + 2);
}
/*
#include <stdio.h>
int main ()
{
  print_ptr("");
  printf("\nEl valor del puntero es %p", "");
  return(0);
}*/
