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
    int     fdread;
    char    *charread;
    char    *temp;
    char    **spl;
    static char *str;

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
            spl =  ft_split_n(str, '\n');
            return (spl[0]);
        }
        fdread = read(fd, charread, BUFFER_SIZE);
    }
    return (str);
}

int main(void)
{
    int     fd;
    char    *str;

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