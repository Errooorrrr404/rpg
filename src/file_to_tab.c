/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "my.h"
#include "rpg.h"

char **file_to_tab(char *path)
{
    int fd = open(path, O_RDONLY);
    int stop = 0;
    char *str = NULL;
    char **file = define_strtab(sizeof(char *) * 5);

    if (!file || fd == -1)
        return NULL;
    while (stop != 1) {
        str = get_next_line(fd);
        if (str != NULL) {
            to_strtab_char(file, str);
            file = re_malloc_strtab(file);
            if (!file)
                return NULL;
            free(str);
        } else
            stop = 1;
    }
    close(fd);
    return file;
}