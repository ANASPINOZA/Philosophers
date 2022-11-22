/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_philos_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaspinoza <anaspinoza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:46:29 by anaspinoza        #+#    #+#             */
/*   Updated: 2022/11/22 17:43:23 by anaspinoza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

	void	check_death(t_data *data)
	{
		int		i;

		i = 0;

		while (i < data->num_of_philos)
		{
			// printf("start_time : %lld predict_time : %lld \n", get_time() 
			//  , data->philos[i].predict_dying);
			if (get_time()  >= \
			data->philos[i].predict_dying)
			{
				data->died = 1;
				print_status (data->philos[i], "philo", "just died .");
				return ;
			}
			if (data->num_of_eat == data->num_of_philos)
				break ;
			i++;
			if (i == data->num_of_philos)
				i = 0;
		}
		return ;
	}