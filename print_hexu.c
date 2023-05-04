/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:16:29 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/04 17:44:16 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlenhex(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 48 && n <= 57)
		return (1);
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

int	print_hexu(unsigned int n)
{
	unsigned int	len;

	len = ft_intlenhex(n);
	if (n >= 16)
	{
		print_hexu(n / 16);
		print_hexu(n % 16);
	}
	else
	{
		if (n < 10)
		{
			n = n + 48;
			write (1, &n, 1);
		}
		else if (n >= 10 && n < 16)
		{
			n = n - 10 + 'A';
			write (1, &n, 1);
		}
	}	
	return (len);
}
