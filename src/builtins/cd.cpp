#include "minishell.h"

int minishell::builtin_cd(const Args& args) {
    if (check_too_many_args(args, 1)) return ERROR;

    std::string path;

    if (args.size() == 1 || args[1] == "~") {
        const char* home = std::getenv("HOME");

        if (home == nullptr) {
            error_print(args[0], "HOME not set");
            return ERROR;
        }

        path = home;
    }
    else {
        path = args[1];
    }

    const char* old_pwd = std::getenv("PWD");
    // Attempt to change the current working directory
    if (chdir(path.c_str()) == -1) {
        minishell::error_print(args[0], "can't open this path");
        return ERROR;
    }

    // Get the new current directory
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == nullptr)
    {
        error_print(args[0], "can't get current directory");
        return ERROR;
    }

    // Update OLDPWD
    if (old_pwd != nullptr) {
        if (setenv("OLDPWD", old_pwd, 1) == -1)
        {
            error_print(args[0], "can't update OLDPWD");
            return ERROR;
        }
    }

    // Update PWD
    if (setenv("PWD", cwd, 1) == -1) {
        error_print(args[0], "can't update PWD");
        return ERROR;
    }
    
    return SUCCESS;
}