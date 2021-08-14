/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:46:04 by raida             #+#    #+#             */
/*   Updated: 2021/07/16 17:07:59 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	len_find;

	if (*find == '\0')
		return ((char *)str);
	len_find = ft_strlen(find);
	while (*str != '\0' && len_find <= len)
	{
		if (ft_strncmp(str, find, len_find) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
