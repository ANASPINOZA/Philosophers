/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:58:47 by aadnane           #+#    #+#             */
/*   Updated: 2022/10/05 12:37:45 by aadnane          ###   ########.fr       */
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

void	ft_error(void);
char	**check_argument(int ac, char **av);
void	is_raw_number(char *num);
void	is_integer(char *num);
void	check_is_int_range(char *num, int positive);
int		ft_strcmp(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);

#endif