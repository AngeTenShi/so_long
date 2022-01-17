/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:12:11 by anggonza          #+#    #+#             */
/*   Updated: 2021/11/02 16:43:01 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((int)len > ft_strlen((s + start)))
		len = ft_strlen((s + start));
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= (int)start && j < (int)len)
			sub[j++] = s[i];
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
