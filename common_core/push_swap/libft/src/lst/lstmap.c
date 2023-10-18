/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:45:00 by sdabland          #+#    #+#             */
/*   Updated: 2023/05/29 12:45:00 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_del(void *content, void (*del)(void *))
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		del(content);
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew_del(f(lst->content), del);
	if (new == NULL)
		return (NULL);
	tmp = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = ft_lstnew_del(f(lst->content), del);
		if (tmp->next == NULL)
			return (ft_lstclear(&new, del), NULL);
		tmp = tmp->next;
	}
	return (new);
}
