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
	// newstr[i] = '\n';
	// i++;
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
	// if (i - n <= 0)
	// 	return (NULL);
	// printf("n:%d,i:%d\n", n, i);
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
/*
char    *ft_reste(char *str)
{
    int     i;
    int     j;
    char    *newstr;

    i = 0;
    j = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    while (str[i + j] != '\0')
        j++;
    newstr = malloc(sizeof(char) * (j + 1));
    if (!newstr)
        return (NULL);
    j = 0;
    while (str[i + j])
    {
        newstr[j] = str[i + j];
        j++;
    }
    newstr[j] = '\0';
    return (newstr);
}*/

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
	// char		charread[BUFFER_SIZE + 1];
	char	 *charread;
	char		*temp;
	char		*strreturn;
	static char	*str;

	if (fd  < 0 || BUFFER_SIZE < 0)
		return (NULL);
    if (!str)
    {
        str = malloc(sizeof(char) * 1);
        if (!str)
            return (NULL);
        str[0] = '\0';
    }
	charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!charread)
		return (NULL);
	fdread = read(fd, charread, BUFFER_SIZE);
	if (fdread == -1)
		return (free(charread), NULL);
	// printf("fdread = %d\n", fdread);
	while (fdread > 0)
	{
		charread[fdread] = '\0';
		// if (str == NULL)
		// 	str = ft_strdup(charread);
		// else
		// {
			temp = ft_strjoin(str, charread);
			if (!temp)
				return (NULL);
			free(str);
			str = temp;
		// }
		// if (ft_check(temp) == 1)
		// {
		// 	if (str)
		// 		free(str);
		// 	str = ft_reste(temp);
		// 	// printf("str = %s(fini)\n", str);
		// 	strreturn = ft_return(temp);
		// 	free(temp);
		// 	return (strreturn);
		// }
		// else if (ft_check(temp) == 0)
		// {
		// 	free(str);
		// 	str = ft_strdup(temp);
		// 	free(temp);
		// }
		if (ft_check(str, '\n') == 1)
			break ;
		fdread = read(fd, charread, BUFFER_SIZE);
		if (fdread == -1)
			return (free(charread), NULL);
	}
	free(charread);
	// if (fdread == 0)
	// 	return (NULL);
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
	
	// printf("str = %s(fini)\n", str);
	 if (str && str[0] == '\0')
        return (free(str), str = NULL, strreturn);
	return (strreturn);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	// fd = open("/home/wooyang/francinette/temp/get_next_line/fsoares/multiple_nl.txt", O_RDONLY);
// 	fd = open("texte2.txt", O_RDONLY);
// 	if (fd == -1)
// 		write(1, "Erreur\n", 7);
// 	str = get_next_line(fd);
// 	printf("1 ='%s'", str);
// 	printf("(fini)\n#################\n");
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("2 ='%s'", str);
// 	printf("(fini)\n#################\n");
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("3 ='%s'", str);
// 	printf("(fini)\n#################\n");
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("4 '%s'", str);
// 	free(str);

// 	// str = get_next_line(fd);
// 	// printf("5 %s", str);
// 	// free(str);
// 	return (0);
// }

int	main(void)
{
	int		fd;
	char	*str;

	// fd = open("/home/wooyang/francinette/temp/get_next_line/fsoares/multiple_nl.txt", O_RDONLY);
	fd = open("texte2.txt", O_RDONLY);
	if (fd == -1)
		write(1, "Erreur\n", 7);
	str = get_next_line(fd);
	while (str)
	{
		printf("'%s'\n", str);
		free(str);
		str = get_next_line(fd);
	}
	str = get_next_line(fd);
	printf("'%s'\n", str);
	free(str);
	return (0);
}

