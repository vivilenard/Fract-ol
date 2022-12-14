/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:22:03 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/10 16:30:09 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_punktraus(char *str)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_split(str, '.');
	str = ft_strjoin(s[0], s[1]);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	return (free(s), str);
}

int	ft_findletter(char *str, char letter)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

double	ft_createdouble(char *str, int s, int strlen)
{
	double	res;
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = res * s;
	while (strlen >= 1 && strlen-- != 1)
		res = res / 10;
	return (res);
}

double	ft_atodouble(char *str)
{
	int		i;
	int		s;
	int		strlen;
	double	res;

	i = 0;
	s = 1;
	strlen = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (ft_findletter(str + i, '.'))
	{
		str = ft_punktraus(str + i);
		strlen = ft_strlen(str);
	}
	res = ft_createdouble(str, s, strlen);
	if (strlen != 0)
		free (str);
	return (res);
}
