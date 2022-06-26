/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:38:21 by kmeixner          #+#    #+#             */
/*   Updated: 2021/11/04 22:38:21 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*temp;
	int		endsize;
	char	*ctemp;

	endsize = nmemb * size;
	if (endsize / nmemb != size || nmemb < 1 || size < 1)
		return (0);
	temp = malloc(nmemb * size);
	if (temp == 0)
		return (0);
	ctemp = temp;
	while (endsize > 0)
	{
		*ctemp = 0;
		ctemp++;
		endsize--;
	}
	return (temp);
}

static unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i + j + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft2_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	if (!s1 || !s2)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	temp = ft_calloc(sizeof(char), i + j + 1);
	if (!temp)
		return ((void *)0);
	ft_strlcpy(temp, (char *)s1, i + 1);
	ft_strlcat(temp, (char *)s2, i + j + 1);
	free(s1);
	return (temp);
}
