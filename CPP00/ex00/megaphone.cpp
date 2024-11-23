#include <iostream>

 char ex00_toupper(char c)
{
    if (c >= 97 && c <= 122)
        c -= 32;
    if (c != ' ')
        std::cout << c;
    return (0);
}

int   ex00_skip_spaces(char *c)
{
    int i = 0;

    while(c[i] && c[i] == ' ')
        i++;
    if (!c[i])
        return (0);
    return (i);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int c;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    i = 0;
    while(++i < (ac))
    {
        j = 0;
        while (av[i][j] && av[i][j] == ' ')
            j++;
        while(av[i][j] && i < ac)
        {
            if (!av[i][j])
                break ;
            ex00_toupper(av[i][j]);
            c = ex00_skip_spaces(av[i] + j);
            if (c)
            {
                std::cout << " ";
                j += c;
            }
            else
                j += 1;
            c = 0;
        }
        if ((i + 1) != ac)
            std::cout << " ";
    }
    std::cout << "\n";
}
