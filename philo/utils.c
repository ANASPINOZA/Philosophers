/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:31:01 by aadnane           #+#    #+#             */
/*   Updated: 2022/11/20 12:33:45 by anaspinoza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

int		ft_atoi(char *s)
{
	int		sign;
	long	r;

	r = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (sign * (int)r);
}

void	print_status(t_philo philos, const char *philo , const char *msg)
{
	long long	action_time;
	
	action_time = get_time() - philos.start_time;
	pthread_mutex_lock(&philos.data->print_lock);
	printf ("| %lld | %s %d %s\n", action_time, philo , philos.id, msg);
	if (philos.data->died == 0 \
		|| philos.data->num_of_eat != philos.data->num_of_philos)
		pthread_mutex_unlock(&philos.data->print_lock);
}