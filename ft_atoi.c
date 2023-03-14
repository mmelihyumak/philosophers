/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:35:06 by muyumak           #+#    #+#             */
/*   Updated: 2023/03/13 23:12:05 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	number *= sign;
	return (number);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
