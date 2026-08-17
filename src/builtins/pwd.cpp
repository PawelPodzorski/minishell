#include "minishell.h"

int minishell::builtin_pwd(const Args& args) {
    char cwd[1024];
    
    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == nullptr) {
        minishell::error_print(args[0], "cannot get current directory");
        return ERROR;
    }

    std::cout << cwd << '\n';
    return SUCCESS;
}