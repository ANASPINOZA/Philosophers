/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:46 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/16 18:17:20 by aadnane          ###   ########.fr       */
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
			printf ("| %lld | philo %d just died . \n", get_time ()\
			- philo->start_time, philo->id);
		}
		if (philo->data->died == 1)
			return (0);
		usleep(500);
	}
	return (1);
}