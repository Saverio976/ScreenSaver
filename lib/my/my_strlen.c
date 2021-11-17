/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** get length of str
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
