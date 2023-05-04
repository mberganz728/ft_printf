/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberganz <mberganz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:00 by mberganz          #+#    #+#             */
/*   Updated: 2023/05/04 14:33:06 by mberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(char const *str, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_nbr(int n);
int	print_uns(unsigned int n);
int	print_hexu(unsigned int n);
int	print_hexl(unsigned int n);
int	print_ptr(void *ptr);

#endif
