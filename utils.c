/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:01 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/15 16:57:27 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		s++;
	if (c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

int	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}

int	ft_iputstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	if(!s)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	return (i);
}

int	ft_nbrlen(long nbr, int base)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	nbr = n;
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	return (ft_nbrlen(nbr, 10));
}

size_t	ft_uputnbr_fd(size_t n, int fd)
{
	size_t	nbr;

	nbr = n;
	if (n >= 0)
	{
		if (n > 9)
			ft_uputnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_uputnbr_fd(-n, fd);
	}
	return (ft_nbrlen(nbr, 10));
}

int	ft_hexanum(size_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_findhexa(size_t num, const char category)
{
	if (num >= 16)
	{
		ft_findhexa(num / 16, category);
		ft_findhexa(num % 16, category);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + 48), 1);
		else
		{
			if (category == 'x')
				ft_putchar_fd((num - 10 + 97), 1);
			if (category == 'X')
				ft_putchar_fd((num - 10 + 65), 1);
		}
	}
}

int	ft_hexa(size_t num, const char category)
{
	if (num != 0)
		ft_findhexa(num, category);
	else
		return (ft_putchar_fd('0', 1));
	return (ft_hexanum(num));
}

/*
MAIN

int main()
{
  int num = 11;
  char  format = 'X';
  ft_print_hex(num, format);

  return 0;
}
*/

int	ft_pointerlen(uintptr_t address)
{
	int	len;

	len = 0;
	while (address != 0)
	{
		len++;
		address = address / 16;
	}
	return (len);
}

void	ft_haxapointer(uintptr_t address)
{
	if (address >= 16)
	{
		ft_haxapointer(address / 16);
		ft_haxapointer(address % 16);
	}
	else
	{
		if (address <= 9)
			ft_putchar_fd((address + '0'), 1);
		else
			ft_putchar_fd((address - 10 + 'a'), 1);
	}
}

int	ft_pointer(uintptr_t pointer)
{
	int	output;

	output = 0;
	output += write(1, "0x", 2);
	if (pointer == 0)
		output += write(1, "0", 1);
	else
	{
		ft_haxapointer(pointer);
		output += ft_pointerlen(pointer);
	}
	return (output);
}
