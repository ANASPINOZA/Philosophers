/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:46 by aadnane           #+#    #+#             */
/*   Updated: 2023/01/06 23:02:39 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((long long)(current_time.tv_sec * 1000) + \
		(current_time.tv_usec / 1000));
}

int	ft_usleep(long long msec, t_philo *philo)
{
	long long	debut;

	debut = get_time();
	while (get_time() - debut < msec)
	{
		if (get_time() - philo->start_time >= \
			philo->predict_dying && !philo->data->died)
		{
			philo->data->died = 1;
		}
		if (philo->data->died == 1)
		{
			return (0);
		}
		usleep(500);
	}
	return (1);
}
