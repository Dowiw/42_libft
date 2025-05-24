/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:37:43 by kmonjard          #+#    #+#             */
/*   Updated: 2025/05/24 22:37:43 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while ((*lst)->next != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}

int main(void)
{
	#include <stdio.h>
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = ft_strdup("Hello");

	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = ft_strdup("Hi");

	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	node3->content = ft_strdup("Hallo");

	t_list *node4 = (t_list *)malloc(sizeof(t_list));
	node4->content = ft_strdup("Bonjour");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	t_list *cursor = node1;
	while (cursor->next != NULL) {
		printf("Before: %s\n", (char *)cursor->content);
		cursor = cursor->next;
	}

	t_list **lst = &node3;
	ft_lstclear(lst, del);

	cursor = node1;
	while (cursor->next != NULL) {
		printf("After: %s\n", (char *)cursor->content);
		cursor = cursor->next;
	}
	return (0);
}
