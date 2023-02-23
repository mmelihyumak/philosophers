/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 02:26:31 by muyumak           #+#    #+#             */
/*   Updated: 2023/02/23 02:26:31 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ms_time()
{
	struct timeval	tv;
	long			millisecond;

	gettimeofday(&tv, NULL);
	millisecond = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (0);
}
