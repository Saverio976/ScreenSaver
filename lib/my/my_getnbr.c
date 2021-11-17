/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** get nbr from str
*/

static int my_is_char_in(char const *str, char c)
{
    int ok = 0;

    for (int i = 0; ok == 0 && str[i] != '\0'; i++)
        if (str[i] == c)
            ok = 1;
    return (ok);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb_minus = 0;
    int result = 0;

    if (!*str)
        return (0);
    while (my_is_char_in("\b\t\n\v\f\r ", str[i]))
        i++;
    while (my_is_char_in("+-", str[i])) {
        i++;
        if (str[i] == '-')
            nb_minus++;
    }
    while (my_is_char_in("0123456789", str[i])) {
        result = result * 10;
        result = result + (str[i] - '0');
        i++;
    }
    return (result);
}
