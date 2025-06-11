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
	int	i;
	char	*newstr;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\n';
	i++;
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_reste(char *str)
{
	int	i;
	int	n;
	int	j;
	char	*reststr;

	i = 0;
	n = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (str[n] != '\n')
		n++;
	reststr = malloc(sizeof(char) * (i - j + 1));
	while (j < (i - j + 1))
	{
		reststr[j] = str[i];
		j++;
		i++;
	}
	reststr[j] = '\0';
	return (reststr);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
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
	static char	*str;

	printf("bf %d\n\n", BUFFER_SIZE);
	charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (charread == NULL)
		return (NULL);
	fdread = read(fd, charread, BUFFER_SIZE);
	str = "";
	temp = str;
	while (fdread > 0)
	{
		charread[fdread] = '\0';
		temp = ft_strjoin(str, charread);
		str = temp;
		if (ft_check(str) == 1)
		{
			// printf("\nn = %s", str);
			return (ft_return(temp));
		}
		fdread = read(fd, charread, BUFFER_SIZE);
		// printf("sans n = %s\n", str);
	}
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		write(1, "Erreur\n", 7);
	str = get_next_line(fd);
	printf("1 %s", str);
	str = get_next_line(fd);
	printf("2 %s", str);
	str = get_next_line(fd);
	printf("3 %s", str);
	str = get_next_line(fd);
	printf("4 %s", str);
	str = get_next_line(fd);
	printf("5 %s", str);
	free(str);
	return (0);
}
