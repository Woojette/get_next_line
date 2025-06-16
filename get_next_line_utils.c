/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:51:12 by wooyang           #+#    #+#             */
/*   Updated: 2025/06/11 14:46:05 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*resultat;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	resultat = malloc(sizeof(char) * (len + 1));
	if (resultat == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		resultat[i] = str[i];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newlist;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newlist = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newlist)
		return (NULL);
	while (s1[i])
	{
		newlist[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newlist[i + j] = s2[j];
		j++;
	}
	newlist[i + j] = '\0';
	return (newlist);
}

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_reste(char *str)
{
	int		i;
	int		n;
	int		j;
	char	*reststr;

	i = 0;
	n = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (str[n] != '\n' && n < i)
		n++;
	if (str[n] == '\n')
		n++;
	reststr = malloc(sizeof(char) * (i - n + 1));
	if (!reststr)
		return (NULL);
	while (str[n] != '\0')
	{
		reststr[j] = str[n];
		j++;
		n++;
	}
	reststr[j] = '\0';
	return (reststr);
}
