/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:32:41 by avillar           #+#    #+#             */
/*   Updated: 2021/01/07 18:47:45 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cons;
	t_list	*todel;

	if (lst == 0)
		return ;
	cons = *lst;
	while (cons)
	{
		todel = cons->next;
		(*del)(cons->content);
		free(cons);
		cons = todel;
	}
	*lst = 0;
}
