/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:46:57 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/11 13:27:57 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philos(t_data *data, char **av)
{
	int				j;
	int				i;
	int				num;
	
	i = 0;
	j = 0;
	
	info_init(data);
	printf("here5\n");
	num = insert_infos(data, av);
	data->proce_start_time = get_time();
	data->philos = malloc(sizeof(t_philo) * num);
	data->forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!data->philos || !data->forks)
		return ;
	philos_init(data);
	while (i < num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].start_time = get_time();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i + 1];
		if (i == (num - 1))
			data->philos[i].right_fork = &data->forks[(i + 1) % num];
		i++;
	}
	printf("starting time for the process : %lld\n", data->proce_start_time);
	while (j < data->num_of_philos)
	{
		printf("starting time for each philo : %lld\n", data->philos[j].start_time);
		j++;
	}
	printf("starting time : %lld\n", data[j].proce_start_time);
	// thread_creation(data, num);
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
		printf("here2\n");
		pthread_create(&data->philos[i].thread_id, NULL, &routine, &data->philos[i]);
		// pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while(i < num)
	{
		printf("here3\n");
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}

void	info_init(t_data *data)
{
	data->proce_start_time = 0;
	data->num_of_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->meals_must_eat = 0;
}

void	philos_init(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = 0;
		data->philos[i].meals = 0;
		data->philos[i].start_time = 0;
		data->philos[i].last_eat = 0;
		i++;
	}
}