/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:42:42 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/14 15:50:18 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// void	*ft_sbardila(void *t)
// {
// 	int n = 0;
// 	t_philo	*philo;

// 	philo = (t_philo *)t;
// 	printf ("t %d\n", philo->id);
// 	while (n < 1000000)
// 	{
// 		pthread_mutex_lock(&philo->mutex);
// 		// printf("ft_i : %d %d\n", i, k);
// 		philo->i += 1;
// 		n++;
// 		pthread_mutex_unlock(&philo->mutex);
// 	}
// 	printf("n : %d \n", n);
// 	return (NULL);
// }


// eating sleep think
// void	*ft_thinking(void *arg)
// // {
	
// // }

void	*routine(void *philos)
{
	t_philo	*phils;

	int		i;
	
	i = 0;
	phils = (t_philo *)philos;
	if (phils->id % 2 == 0)
		usleep(phils->data->time_to_eat * 1000);
	while (1)
	{
		pthread_mutex_lock (phils->left_fork);
		pthread_mutex_lock (phils->right_fork);
		printf ("| %lld | philo %d has taken left fork\n", get_time () - phils->start_time, phils->id);
		printf ("| %lld | philo %d has taken right fork\n", get_time () - phils->start_time, phils->id);
		printf ("| %lld | philo %d is eating\n", get_time () - phils->start_time, phils->id);
		usleep (phils->data->time_to_eat * 1000);
		pthread_mutex_unlock (phils->left_fork);
		pthread_mutex_unlock (phils->right_fork);
		printf ("| %lld | philo %d is sleeping\n", get_time () - phils->start_time, phils->id);
		usleep (phils->data->time_to_sleep * 1000);
		// printf ("| %lld | philo %d is thinking\n", get_time () - phils->start_time, phils->id);
	}
	return(NULL);
}

int main(int ac, char **av)
{
	int				j;
	// t_philo			*philos;
	t_data			data;
	char			**arg;
	int				i;																				
	
	i = 0;
	j = 0;
// philos[0].id = new_thread[0];=
	// pthread_mutex_init(&mutex, NULL);

	if (ac != 5 && ac != 6)
		return(write(1,"Error\n",6), 0);
	arg = check_argument(ac, av);
	if (!arg)
		return(write(1,"Error\n",6), 0);
	create_philos(&data, av);
	// create_philos(philos->data, av);
	// j = 0;
	// printf("i1: %d\n", i);
	// while (j < 5)
	// {
	// 	philos[i].id = id + 1;
	// 	pthread_create (&new_thread[j], NULL, &ft_sbardila, &philos[j]);
	// 	j++;
	// }
	// j = 1;
	// while (j < 5)
	// {
	// 	pthread_join (new_thread[j], NULL);
	// 	j++;
	// }
	// printf("i2: %d\n", i);
	return (0);
}