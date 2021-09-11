/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:25:03 by cjettie           #+#    #+#             */
/*   Updated: 2020/11/15 15:39:43 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s1)
{
	size_t	mem_size;
	void	*result;

	mem_size = 0;
	while (s1[mem_size++] != '\0')
		(void)mem_size;
	result = malloc(sizeof(char) * (mem_size));
	if (result != NULL)
		memcpy(result, s1, mem_size);
	return ((char *)result);
}
