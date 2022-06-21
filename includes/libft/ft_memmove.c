/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:03:46 by avillar           #+#    #+#             */
/*   Updated: 2021/01/06 11:49:56 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if ((unsigned char *)dst > (unsigned char *)src)
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		while (len > 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
			len -= sizeof(char);
		}
	}
	return (dst);
}
