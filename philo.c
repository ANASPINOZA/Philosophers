/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:42:42 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/10 18:56:30 by aadnane          ###   ########.fr       */
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
// {
	
// }

// void	*routine(void *data)
// {
// 	// (t_data *)data;
	
	
	
	
// }

int main(int ac, char **av)
{
	int				j;
	t_philo			*philos;
	char			**arg;
	int				i;																				
	
	i = 0;
	j = 0;
	
// philos[0].id = new_thread[0];=
	// pthread_mutex_init(&mutex, NULL);

	if (ac != 5 && ac != 6)
		return(write(1,"Error\n",6), 0);
	create_philos(philos, av);
	arg = check_argument(ac, av);
	if (!arg)
		return(write(1,"Error\n",6), 0);
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