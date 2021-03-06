/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_amount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:52:16 by cjettie           #+#    #+#             */
/*   Updated: 2021/08/15 12:52:34 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num_amount(int n)
{
	int		num_amount;

	num_amount = 1;
	n = n / 10;
	while (n != 0)
	{
		n = n / 10;
		++num_amount;
	}
	return (num_amount);
}
