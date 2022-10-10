/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:58:47 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/10 18:16:24 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>


typedef struct s_data
{
	long long		starting_time;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_must_eat;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
} t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				n;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				start_time;
	int				meals;
	int				last_eat;
	t_data			*data;
}	t_philo;

char	**check_argument(int ac, char **av);
int		is_raw_number(char *num);
int		is_integer(char *num);
int		check_is_int_range(char *num, int positive);
int		ft_strcmp(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_atoi(char *s);
void	*routine(void *philos);
int		insert_infos(t_data *data, char** av);
void	create_philos(t_philo *philos, char **av);
void	*routine(void *philos);
long long		get_time();
void	thread_creation(t_data *data, int num);

#endif