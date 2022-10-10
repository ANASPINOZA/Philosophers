/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:46 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/10 16:21:14 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time()
{
	struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return ((long long)(current_time.tv_sec*1000)+(current_time.tv_usec/1000));
}
