/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:30:08 by aadnane           #+#    #+#             */
/*   Updated: 2022/11/18 20:15:29 by anaspinoza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	**check_argument(int ac, char **av)
{
	int		i;
	int		j;
	(void)ac;
	
	i = 1;
	j = 2;
	while (av[i])
	{
		if (is_raw_number(av[i]))
			return(NULL);
		if (is_integer(av[i]))
			return(NULL);
		if (check_is_under_sixty(av[j]))
			return(NULL);
		i++;
	}
	return (av);
}

// check if the element is a number
int	is_raw_number(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if ( num[i] == '-')
			return(1);
		if ((num[i] == '+') && (ft_strlen(&num[i]) >= 2))
			i++;
		if (num[i] < '0' || num[i] > '9')
			return(1);
		i++;
	}
	return(0);
}

// check if the element is a number in an int range
// (-2147483648 < number < 2147483647)
int	is_integer(char *num)
{
	int	num_len;
	int	positive;
	int	sign;

	positive = 0;
	sign = 0;
	num_len = ft_strlen(num);
	if (num[0] == '+')
	{
		if (num[0] == '+')
			positive = 1;
		sign = 1;
	}
	if ((num_len - sign) > 10)
		return(1);
	if ((num_len - sign) == 10)
	{
		if(check_is_int_range(num, positive))
			return(1);
	}
		return(0);
}

int	check_is_int_range(char *num, int positive)
{
	if ((ft_strcmp(&num[positive], INT_MAX)) > 0)
		return(1);
	return(0);
}

int	check_is_under_sixty(char	*num)
{
	if (num[0] < '6')
	{
		return (1);
	}
	return(0);
}