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
	free(str);
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
	n++;
	// printf("n %d |", n);
	// printf("str entier %s |\n", str);
	reststr = malloc(sizeof(char) * (i - n + 1));
	if (reststr == NULL)
		return (NULL);
	while (str[n] != '\0')
	{
		// printf("char %c |\n", str[n]);
		reststr[j] = str[n];
		j++;
		n++;
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
	char		charread[BUFFER_SIZE + 1];
	char		*temp;
	static char	*str;

	fdread = read(fd, charread, BUFFER_SIZE);
	// printf("str: %s\n", str);
	while (fdread > 0)
	{
		// if (temp)
		// {
		// 	free(temp);
		// 	temp = NULL;
		// }
		// printf("fdread (BUFFER_SIZE) %d\n", fdread);
		charread[fdread] = '\0';
		// printf("[%s]cr: %s\n",str, charread);
		// free(temp);
		if (str == NULL)
		{
			temp = ft_strdup(charread);
		}
		else
		{
			free(temp);
			temp = ft_strjoin(str, charread);
		}
		// free(temp);
		if (ft_check(temp) == 1)
		{
			if (str != NULL)
			{
				free(str);
				str = NULL;
			}
			str = ft_reste(temp);
			// printf("\nn = %s", str);
			return (ft_return(temp));
		}
		else if (ft_check(temp) == 0)
		{
			if (str != NULL)
			{
				free(str);
				str = NULL;
			}
			str = ft_strdup(temp);
			// printf("survecu\n");
		}
		fdread = read(fd, charread, BUFFER_SIZE);
		// str = ft_reste(charread);
		// printf("%s\n", str);
		// printf("sans n = %s\n", str);
	}
	free(temp);
	temp = NULL;
	return (str);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	fd = open("texte.txt", O_RDONLY);
// 	if (fd == -1)
// 		write(1, "Erreur\n", 7);
// 	str = get_next_line(fd);
// 	printf("1 %s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("2 %s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("3 %s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("4 %s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("5 %s", str);
// 	free(str);
// 	return (0);
// }
