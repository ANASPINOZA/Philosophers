/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:42:42 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/05 13:54:11 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int i = 0;
pthread_mutex_t mutex;

void	*ft_sbardila(void *t)
{
	int *j = (int*)t;
	int k = *j;
	int n = 0;
	printf ("t %d\n", k);
	while (n < 1000000)
	{
		pthread_mutex_lock(&mutex);
		// printf("ft_i : %d %d\n", i, k);
		i += 1;
		n++;
		pthread_mutex_unlock(&mutex);
	}
	printf("n : %d \n", n);
	return (NULL);
}


// eating sleep think

// #define NUM
// #define DIE
// #define EAT
// #define SLP

int main(int ac, char **av)
{
	// int		j;
	// pthread_t new_thread[5];
	// pthread_mutex_init(&mutex, NULL);

	// av = (char *[]){, NULL};
	if (ac != 5 && ac != 6)
		ft_error();
	check_argument(ac, av);
	// j = 0;
	// printf("i1: %d\n", i);
	// while (j < 5)
	// {
	// 	pthread_create (&new_thread[j], NULL, &ft_sbardila, &j);
	// 	j++;
	// }
	// j = 0;
	// while (j < 5)
	// {
	// 	pthread_join (new_thread[j], NULL);
	// 	j++;
	// }
	// printf("i2: %d\n", i);
	// return (0);
}