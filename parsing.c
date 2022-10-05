/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:30:08 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/05 13:47:02 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	**check_argument(int ac, char **av)
{
	int		i;
	(void)ac;
	
	i = 1;
	while (av[i])
	{
		is_raw_number(av[i]);
		is_integer(av[i]);
		i++;
	}
	return (av);
}

// check if the element is a number
void	is_raw_number(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if ( num[i] == '-')
			ft_error();
		if ((num[i] == '+') && (ft_strlen(&num[i]) >= 2))
			i++;
		if (num[i] < '0' || num[i] > '9')
			ft_error();
		i++;
	}
}

// check if the element is a number in an int range
// (-2147483648 < number < 2147483647)
void	is_integer(char *num)
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
		ft_error();
	if ((num_len - sign) == 10)
		check_is_int_range(num, positive);
}

void	check_is_int_range(char *num, int positive)
{
	if ((ft_strcmp(&num[positive], INT_MAX)) > 0)
		ft_error();
}