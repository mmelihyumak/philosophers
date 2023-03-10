/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 05:48:50 by melih             #+#    #+#             */
/*   Updated: 2023/03/13 23:32:11 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(int argc, char **argv)
{
	t_rules rules;

	if (!check_numbers(argc, argv) || !check_zero(argv))
		return (0);
	fill_rules(&rules, argv);
	if (launch(&rules) == 1)
		return (0);
	return (0);
}