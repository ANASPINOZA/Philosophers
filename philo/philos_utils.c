/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:46:57 by aadnane           #+#    #+#             */
/*   Updated: 2023/01/06 18:35:33 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philos(t_data *data, char **av, int ac)
{
	int				i;
	int				num;

	i = 0;
	info_init(data);
	num = insert_infos(data, av);
	data->proce_start_time = get_time();
	data->philos = malloc(sizeof(t_philo) * num);
	data->forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!data->philos || !data->forks)
		return ;
	philos_init(data, av, ac);
	while (i < num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].start_time = get_time();
		data->philos[i].predict_dying = get_time() + data->time_to_die;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % num];
		data->philos[i].data = data;
		i++;
	}
	init_forks (data);
	pthread_mutex_init(&data->print_lock, NULL);
	thread_creation (data, num);
}

int	insert_infos(t_data *data, char **av)
{
	int	num;

	data->num_of_philos = ft_atoi(av[1]);
	num = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	return (num);
}

void	thread_creation(t_data *data, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_create(&data->philos[i].thread_id, NULL, \
			&routine, &data->philos[i]);
		i++;
	}
	detach_threads (data);
}

void	info_init(t_data *data)
{
	data->proce_start_time = 0;
	data->num_of_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->num_of_eat = 0;
	data->died = 0;
}

void	philos_init(t_data *data, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = 0;
		data->philos[i].meals = 0;
		data->philos[i].last_eat = 0;
		if (ac == 6)
			data->philos[i].meals_must_eat = ft_atoi(av[5]);
		else
			data->philos[i].meals_must_eat = 0;
		i++;
	}
}
