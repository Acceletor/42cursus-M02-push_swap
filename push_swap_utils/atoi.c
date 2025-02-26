#include "../include/push_swap.h"


// TRUE mean result > INT_MAX && result < INT_MIN
bool	atoi_edgecase(const char *str, int *num)
{
	char	flag;
	long	res;

	res = 0;
	flag = '+';
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		flag = *str;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (flag == '-')
		return (res * -1);
	*num = res;
	if (res < INT_MIN || res > INT_MIN)
		return (true);
	return (false);
}