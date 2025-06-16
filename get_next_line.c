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

int	my_read(int fd, int *fdread, char **charread, char **str)
{
	char	*temp;

	while (*fdread > 0)
	{
		(*charread)[*fdread] = '\0';
		temp = ft_strjoin(*str, *charread);
		if (!temp)
			return (free(*str), *str = NULL, free(*charread), -1);
		free(*str);
		*str = temp;
		if (ft_check(*str, '\n') == 1)
			break ;
		*fdread = read(fd, *charread, BUFFER_SIZE);
		if (*fdread == -1)
			return (free(*str), *str = NULL, free(*charread), -1);
	}
	free(*charread);
	return (0);
}

int	checks(int fd, char **str)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(*str), *str = NULL, -1);
	if (!*str)
	{
		*str = malloc(sizeof(char) * 1);
		(*str)[0] = '\0';
	}
	return (0);
}

int	ft_test_null(char **charread, int *fd, char **str)
{
	int	fdread;

	*charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*charread))
		return (-1);
	fdread = read(*fd, *charread, BUFFER_SIZE);
	if (fdread == -1)
		return (free(*str), *str = NULL, free(*charread), -1);
	if (my_read(*fd, &fdread, charread, str) == -1)
		return (-1);
	if (fdread == 0 && ((*str)[0] == '\0' || !(*str)))
	{
		if (*str)
			return (free(*str), *str = NULL, -1);
		return (-1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*charread;
	char		*temp;
	char		*strreturn;
	static char	*str;

	if (checks(fd, &str) == -1)
		return (NULL);
	if (ft_test_null(&charread, &fd, &str) == -1)
		return (NULL);
	strreturn = ft_return(str);
	if (!strreturn)
		return (NULL);
	temp = ft_reste(str);
	if (!temp)
		return (NULL);
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
