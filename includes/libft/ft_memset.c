/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:03:59 by avillar           #+#    #+#             */
/*   Updated: 2021/01/06 11:15:31 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	int		i;
	int		id;

	id = 0;
	i = sizeof(char);
	while (len > 0)
	{
		((char *)ptr)[id] = c;
		id++;
		len -= i;
	}
	return (ptr);
}
