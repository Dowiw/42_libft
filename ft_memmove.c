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
	unsigned char	*dest_area;
	unsigned char	*src_area;

	if (dest == NULL && src == NULL)
		return (dest);
	dest_area = (unsigned char *) dest;
	src_area = (unsigned char *) src;
	if (dest_area < src_area)
	{
		while (n--)
			*dest_area++ = *src_area++;
	}
	else if (dest_area > src_area)
	{
		dest_area += n;
		src_area += n;
		while (n--)
			*dest_area-- = *src_area--;
	}
	return (dest);
}
