/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:12:22 by avillar           #+#    #+#             */
/*   Updated: 2021/01/07 17:27:40 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cons;

	if (new == 0)
		return ;
	if (*alst == 0)
		*alst = new;
	else
	{
		cons = ft_lstlast(*alst);
		cons->next = new;
	}
}
