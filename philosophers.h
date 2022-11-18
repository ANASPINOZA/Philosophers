/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:58:47 by aadnane           #+#    #+#             */
/*   Updated: 2022/11/18 20:13:46 by anaspinoza       ###   ########.fr       */
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
	long long		proce_start_time;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	// int				meals_must_eat;
	int				num_of_eat;
	int				died;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
} t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				n;
	int				meals_must_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		start_time;
	int				meals;
	long long		last_eat;
	t_data			*data;
	long long		predict_dying;
}	t_philo;

char			**check_argument(int ac, char **av);
int				is_raw_number(char *num);
int				is_integer(char *num);
int				check_is_int_range(char *num, int positive);
int				ft_strcmp(char *str1, char *str2);
int				ft_strlen(char *str);
char			*ft_strdup(char *s);
int				ft_atoi(char *s);
void			*routine(void *philos);
int				insert_infos(t_data *data, char** av);
void			create_philos(t_data *data, char **av, int ac);
void			*routine(void *philos);
long long		get_time();
void			thread_creation(t_data *data, int num);
void			*routine(void *data);
void			info_init(t_data *data);
void			philos_init(t_data *data, char **av, int ac);
void 			init_forks (t_data *data);
void 			join_threads (t_data *data);
int				ft_usleep(long long msec, t_philo *philo);
int				check_is_under_sixty(char	*num);


#endif