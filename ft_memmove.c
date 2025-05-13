/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:08:31 by kmonjard          #+#    #+#             */
/*   Updated: 2025/05/13 20:08:32 by kmonjard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Like memcpy: HOWEVER, copies src to another array then copies it to dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_area;
	unsigned char	*src_area;
	unsigned char	*temp;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	dest_area = (unsigned char *) dest;
	src_area = (unsigned char *) src;
	while (i < n)
	{
		temp[i] = src_area[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_area[i] = temp[i];
		i++;
	}
	return (dest);
}
