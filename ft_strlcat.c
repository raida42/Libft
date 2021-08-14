/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:45:44 by raida             #+#    #+#             */
/*   Updated: 2021/04/26 15:12:41 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	result;

	len_dst = ft_strlen(dst);
	len_src =ft_strlen(src);
	result = len_dst + len_src;
	i = 0;
	if (dstsize < len_dst)
		return (dstsize + len_src);
	while (src[i] != '\0' && len_dst < dstsize - 1 && dstsize > 0)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (result);
}
