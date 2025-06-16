/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:23:31 by wooyang           #+#    #+#             */
/*   Updated: 2025/06/11 13:38:03 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	while (j < i)
	{
		newstr[j] = str[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
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


char	*get_next_line(int fd)
{
	int			fdread;
	char		*charread;
	char		*temp;
	char		*strreturn;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!charread)
		return (NULL);
	fdread = read(fd, charread, BUFFER_SIZE);
	if (fdread == -1)
		return (free(str), str = NULL, free(charread), NULL);
	while (fdread > 0)
	{
		charread[fdread] = '\0';
		temp = ft_strjoin(str, charread);
		if (!temp)
			return (free(str), free(charread), NULL);
		free(str);
		str = temp;
		if (ft_check(str, '\n') == 1)
			break ;
		fdread = read(fd, charread, BUFFER_SIZE);
		if (fdread == -1)
			return (free(str), str = NULL, free(charread), NULL);
	}
	free(charread);
	if (fdread == 0 && (str[0] == '\0' || !str))
	{
		if (str)
			return (free(str), str = NULL, NULL);
		return (NULL);
	}
	strreturn = ft_return(str);
	temp = ft_reste(str);
	free(str);
	str = temp;
	if (str && str[0] == '\0')
		return (free(str), str = NULL, strreturn);
	return (strreturn);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("texte.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("[%s]", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	str = get_next_line(fd);
// 	printf("[%s]", str);
// 	free(str);
// 	return (0);
// }
