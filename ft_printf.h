/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:24:12 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/15 18:08:23 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define    FT_PRINTF_H

/* O cabeçalho stdarg.h define um tipo de variável va_list e três macros que 
podem ser usadas para obter os argumentos em uma função quando o número de 
argumentos não é conhecido, ou seja, número variável de argumentos.
Uma função de argumentos variáveis ​​é definida com as reticências (,...) no 
final da lista de parâmetros.
 */
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <inttypes.h>

int		ft_printf(const char *, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);

int 	ft_pointer(uintptr_t pointer);

int		ft_iputstr_fd(char *s, int fd);


int		ft_putnbr_fd(int n, int fd);
size_t	ft_uputnbr_fd(size_t n, int fd);

int		ft_putnbase(unsigned long nbr, const char *base, int fd);

int 	ft_hexa(size_t num, const char format);


#endif