/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhopp <lhopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:03:23 by lhopp             #+#    #+#             */
/*   Updated: 2024/04/11 11:03:51 by lhopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;
	size_t			i;

	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		dest_c[i] = '\0';
		i++;
	}
	return (dest);
}

void	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
