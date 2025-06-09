#include "get_next_line.h"

int ft_check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *get_next_line(int fd)
{
    int     readfd;
    char    *charread;
    char    *temp;
    static char    *str;

    fd = open("texte.txt", O_RDONLY);
    if (fd == -1)
        write(1, "erreur\n", 1);
    charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    readfd = read(fd, charread, BUFFER_SIZE);
    str = "";
    temp = ft_strjoin(str, charread);
    free(temp);
    while (readfd > 0)
    {
        charread[readfd] = '\0';
        if (ft_check(str) == 1)
            break ;
    }
    return (str);
}