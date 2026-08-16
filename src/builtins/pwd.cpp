#include "minishell.h"

int minishell::builtin_pwd() {
    char cwd[1024];
    
    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == nullptr) {
        std::perror("pwd");
        return ERROR;
    }

    std::cout << cwd << '\n';
    return SUCCESS;
}