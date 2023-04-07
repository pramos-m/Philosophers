/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:37:22 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/11 17:18:11 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;
	void	*tmp;

	if (!lst)
		return (NULL);
	new_lst = 0;
	while (lst)
	{
		tmp = f(lst->content);
		elem = ft_lstnew(tmp);
		if (!elem)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, elem);
	}
	return (new_lst);
}
