/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:46:57 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/10 18:19:01 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philos(t_philo *philos, char **av)
{
	int				j;
	int				i;
	int				num;
	
	i = 0;
	j = 0;
	num = insert_infos(philos->data, av);
	philos->data->starting_time = get_time();
	philos = malloc(sizeof(t_philo) * num);
	philos->data->forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!philos->data->philos || !philos->data->forks)
		return ;
	while (i < num)
	{
		philos->data->philos[i].id = i + 1;
		philos->data->philos[i].left_fork = &philos->data->forks[i];
		philos->data->philos[i].right_fork = &philos->data->forks[i + 1];
		if (i == (num - 1))
			philos->data->philos[i].right_fork = &philos->data->forks[(i + 1) % num];
		i++;
	}
	thread_creation(philos->data, num);
}

int	insert_infos(t_data *data, char** av)
{
	int i;
	int num;

	i = 0;
	data->num_of_philos = ft_atoi(av[1]);
	num = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat= ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	
	return (num);
}

void	thread_creation(t_data *data, int num)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while(i < num)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &routine, &data->philos[i]);
		i++;
	}
}