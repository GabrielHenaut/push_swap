/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:28:52 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:40:29 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*ft_lstnew_2(void *content)
{
	t_list	*nw;

	nw = (t_list *)malloc(sizeof(t_list));
	if (!nw)
	{
		ft_putstr_fd("ERROR_IN_FT_LSTNEW_2\n", 1);
		return (NULL);
	}
	nw->content = content;
	nw->next = NULL;
	return (nw);
}

static void	ft_lstdelone_2(t_list **head, t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !head)
		return ;
	temp = *head;
	if (temp == lst)
		*head = temp->next;
	else
	{
		while (temp && temp->next != lst)
			temp = temp->next;
		if (!temp)
		{
			ft_putstr_fd("ERROR_IN_FT_LSTDELONE_2\n", 1);
			return ;
		}
		temp->next = lst->next;
	}
	if (del)
		del(lst->content);
	free(lst);
}

static void	*ft_calloc_2(size_t elementcount, size_t elementsize)
{
	void	*ans;

	ans = malloc(elementcount * elementsize);
	if (!ans)
	{
		ft_putstr_fd("ERROR_IN_FT_CALLOC_2\n", 1);
		return (NULL);
	}
	ft_memset(ans, 0, elementcount * elementsize);
	return (ans);
}

static void	ft_lstclear_2(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*dd;

	if (!(lst))
	{
		ft_putstr_fd("ERROR_IN_FT_LSTCLEAR_2\n", 1);
		return ;
	}
	temp = *lst;
	*lst = NULL;
	while (temp)
	{
		if (del)
			del(temp->content);
		dd = temp;
		temp = temp->next;
		free(dd);
	}
}

void	*ft_memory(size_t elem_cnt,
size_t elem_size, void *del, t_memory type)
{
	static t_list	*head;
	void			*new_mem;

	if (type == push)
	{
		new_mem = ft_calloc_2(elem_cnt, elem_size);
		if (!new_mem)
			ft_putstr_fd("ERROR_IN_FT_MEMORY_0\n", 1);
		else if (!(ft_lstadd_front(&head, ft_lstnew_2(new_mem))))
			ft_putstr_fd("ERROR_IN_FT_MEMORY_1\n", 1);
		return (new_mem);
	}
	if (type == pop)
		ft_lstdelone_2(&head, ft_lstfind(head, del), free);
	else
		ft_lstclear_2(&head, free);
	return (NULL);
}
