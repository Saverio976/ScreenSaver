/*
** EPITECH PROJECT, 2021
** MYSCREENSAVER
** File description:
** put str in stdout
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}
