/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:16:04 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/04 11:54:16 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_uns(unsigned int n)
{
	int	mod;
	int	len;

	if (n > 9)
		print_uns(n / 10);
	mod = n % 10 + 48;
	write(1, &mod, 1);
	len = ft_intlen(n);
	return (len);
}
