/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:45:52 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/10 17:02:27 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst2;

	lst2 = *lst;
	while (*lst != NULL && lst != NULL)
	{
		*lst = lst2->next;
		del(lst2->content);
		free(lst2);
		lst2 = *lst;
	}
}
