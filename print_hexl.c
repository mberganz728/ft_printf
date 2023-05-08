/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:16:37 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/08 11:35:22 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlenhex(unsigned int n)
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

int	print_hexl(unsigned int n)
{
	unsigned int	len;

	len = ft_intlenhex(n);
	if (n >= 16)
	{
		print_hexl(n / 16);
		print_hexl(n % 16);
	}
	else
	{
		if (n < 10)
		{
			n = n + 48;
			write (1, &n, 1);
		}
		else if (n >= 10 && n <= 15)
		{	
			n = n - 10 + 'a';
			write (1, &n, 1);
		}
	}
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	print_hexl(100);
	printf("El valor hexadecimal es %x", 100);
	return (0);
}*/
