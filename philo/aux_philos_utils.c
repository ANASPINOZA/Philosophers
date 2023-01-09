/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_philos_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:29 by anaspinoza        #+#    #+#             */
/*   Updated: 2023/01/06 21:49:46 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_death(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (get_time() >= data->philos[i].predict_dying)
		{
			data->died = 1;
			print_status (data->philos[i], "philo", "just died .");
			return ;
		}
		if (data->num_of_eat == data->num_of_philos)
		{
			print_status (data->philos[i], NULL, NULL);
			break ;
		}
		i++;
		if (i == data->num_of_philos)
			i = 0;
	}
	return ;
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init (&(data->forks[i]), NULL);
		i++;
	}
}

void	detach_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_detach (data->philos[i].thread_id);
		i++;
	}
}
