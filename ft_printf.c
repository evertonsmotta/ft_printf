/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:24:08 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/15 18:40:52 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_category(va_list ap, const char category)
{
	int	output;

	output = 0;
	if (category == 'c')
		output = (ft_putchar_fd(va_arg(ap, int), 1));
	else if (category == 's')
		output = ft_iputstr_fd(va_arg(ap, char *), 1);
	else if (category == 'p')
		output = ft_pointer(va_arg(ap, unsigned long));
	else if (category == 'd' || category == 'i')
		output = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (category == 'u')
		output = ft_uputnbr_fd(va_arg(ap, unsigned int), 1);
	else if (category == 'x' || category == 'X')
		output = ft_hexa(va_arg(ap, unsigned int), category);
	else if (category == '%')
		output = ft_putchar_fd('%', 1);
	return (output);
}

int	ft_printf(const char *fstarg, ...)
{
	size_t		i;
	va_list	ap;
	int		output;

	i = 0;
	output = 0;
	va_start(ap, fstarg);
	while (fstarg[i])
	{
		if (fstarg[i] == '%')
		{
			output += ft_category(ap, fstarg[i + 1]);
			i++;
		}
		else
			output += ft_putchar_fd(fstarg[i], 1);
		i++;
	}
	va_end(ap);
	return (output);
}































/*
int	ft_printf(const char *fstarg, ...)
{
	va_list	args;
	size_t		i;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, fstarg);
	while (*fstarg)
	{
		if (*fstarg == '%')
		{
			fstarg++;
			if(ft_strchr("cspdiuxX", *fstarg))
				i = i + ft_formats(args, fstarg[i + 1]);
//			print_length += ft_formats(args, fstarg[i + 1]);
			i++;//
		}
		else
			i += ft_putchar(*fstarg);
		i++;
	}
	va_end(args);
	return (i);
}
*/
/*

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar(va_arg(args, int));


int	ftype(char *form, va_list ap, int i)
{
	if (!form)
		return (0);
	if (form[i + 1] == '%')
		(ft_putchar('%'));
	if (form[i + 1] == 'c')
		(ft_putchar(va_arg(ap, int)));
	else
		return (0);
	return (0);
}

int ft_printf(const char *lstarg, ...)
{
	va_list	ap;
	int	i;
	int	result;
	
	va_start (ap, lstarg);
	if (!lstarg)
		return (0);
	i = 0;
	while (lstarg[i])
	{
		if (lstarg[i] == '%' && lstarg[i + 1] == 'c')
		{
			result = ftype(lstarg[i + 1], ap, i);
			i++;
		}
	}
	va_end(ap);
	return (result);
}*/

























/*
KODPE
static int	print_ptr(unsigned long ptr, int fd)
{
	if (!ptr)
	{
		ft_putstr_fd(OS_PTR_NULL, fd);
		return (OS_PTR_NULL_SIZE);
	}
	ft_putstr_fd("0x", fd);
	return (2 + ft_putnbase(ptr, "0123456789abcdef", fd));
}

static int	print_str(char *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return ((int)ft_strlen(s));
}

static int	what_conv(char c, va_list *p, int fd)
{
	if (c == 's')
		return (print_str(va_arg(*p, char *), fd));
	else if (c == 'p')
		return (print_ptr(va_arg(*p, unsigned long), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*p, int), fd));
	else if (c == 'u')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789", fd));
	else if (c == 'x')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789abcdef", fd));
	else if (c == 'X')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789ABCDEF", fd));
	else if (c == 'c')
		ft_putchar_fd(va_arg(*p, int), fd);
	else
		ft_putchar_fd(c, fd);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		nbytes;
	int		fd;

	fd = 1;
	i = 0;
	nbytes = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			nbytes += what_conv(format[i + 1], &params, 1);
			i++;
		}
		else
		{
			write(fd, &format[i], 1);
			nbytes++;
		}
		i++;
	}
	va_end(params);
	return (nbytes);
}*/