/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:46 by aadnane           #+#    #+#             */
/*   Updated: 2022/11/20 14:30:03 by anaspinoza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time()
{
	struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return ((long long)(current_time.tv_sec*1000)+(current_time.tv_usec/1000));
}

int	ft_usleep(long long msec, t_philo *philo)
{
	long long	debut;

	debut = get_time();
	while(get_time() - debut < msec)
	{
		if (get_time() - philo->start_time >= philo->predict_dying && !philo->data->died)
		{
			philo->data->died = 1;
			// print_status (*philo, "philo", "just died .");
			philo->data->exit = 1;
		}
		if (philo->data->died == 1)
		{
			return (0);
		}
		usleep(500);
	}
	return (1);
}