/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:06:05 by ksuebtha          #+#    #+#             */
/*   Updated: 2025/03/01 09:11:33 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// TRUE mean result > INT_MAX && result < INT_MIN
bool	atoi_edgecase(const char *str, int *num)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if (sign == 1 && res > INT_MAX)
			return (false);
		if (sign == -1 && - res < INT_MIN)
			return (false);
		str++;
	}
	*num = (int)res * sign;
	return (true);
}
