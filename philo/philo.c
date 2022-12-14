/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:42:42 by aadnane           #+#    #+#             */
/*   Updated: 2023/01/06 15:09:56 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_tools(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_lock);
	free(data->forks);
	free(data->philos);
}

void	philos_take_forks(t_philo *phils)
{
	pthread_mutex_lock (phils->left_fork);
	print_status(*phils, "philo", "has taken fork");
	pthread_mutex_lock (phils->right_fork);
	print_status(*phils, "philo", "has taken fork");
}

void	philos_put_forks(t_philo *phils)
{
	pthread_mutex_unlock (phils->left_fork);
	pthread_mutex_unlock (phils->right_fork);
}

void	*routine(void *philos)
{
	t_philo	*phils;
	int		philo_eat;

	philo_eat = 0;
	phils = (t_philo *)philos;
	if (phils->id % 2 == 0)
		ft_usleep(phils->data->time_to_eat, phils);
	while (1 && !phils->data->died)
	{
		if (phils->meals_must_eat && philo_eat == phils->meals_must_eat)
			phils->data->num_of_eat++;
		philos_take_forks(phils);
		print_status(*phils, "philo", "is eating");
		phils->predict_dying = get_time() + phils->data->time_to_die;
		if (!ft_usleep (phils->data->time_to_eat, phils))
			return (0);
		philo_eat++;
		philos_put_forks(phils);
		print_status (*phils, "philo", "is sleeping");
		if (!ft_usleep (phils->data->time_to_sleep, phils))
			return (0);
		print_status (*phils, "philo", "is thinking");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data			data;
	char			**arg;		

	if (ac != 5 && ac != 6)
		return (write(2, "Error\n", 6), 0);
	arg = check_argument(ac, av);
	if (!arg)
		return (write(2, "Error\n", 6), 0);
	create_philos(&data, av, ac);
	check_death(&data);
	clean_tools(&data);
	return (0);
}
