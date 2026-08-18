#include "minishell.h"
#include <dirent.h>

int minishell::builtin_ls(const Args& args) {
    if (minishell::check_too_many_args(args, 0))
        return ERROR;

    DIR* dir = opendir(".");

    if (dir == nullptr)
    {
        minishell::error_print(args[0], "can't open directory");
        return ERROR;
    }

    struct dirent* entry;

    while ((entry = readdir(dir)) != nullptr)
    {
        // Skip hidden files
        if (entry->d_name[0] == '.')
            continue;

        std::cout << entry->d_name << '\n';
    }

    closedir(dir);

    return SUCCESS;
}