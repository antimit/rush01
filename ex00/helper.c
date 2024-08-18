/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:31 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:50:33 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

char	*my_strtok(char *str, const char *delim)
{
	static char	*next;
	char		*start;

	if (str == NULL)
		str = next;
	if (str == NULL)
		return (NULL);
	while (*str && strchr(delim, *str))
		str++;
	if (*str == '\0')
	{
		next = NULL;
		return (NULL);
	}
	start = str;
	while (*str && !strchr(delim, *str))
		str++;
	if (*str)
	{
		*str = '\0';
		next = str + 1;
	}
	else
		next = NULL;
	return (start);
}

int	my_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
