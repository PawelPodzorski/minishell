#include "minishell.h"


int minishell::builtin_cd(const std::string& path) {
    if (path.empty()) {
        std::cerr << "cd: missing argument\n";
        return ERROR;
    }
    // Attempt to change the current working directory
    if (chdir(path.c_str()) == -1) {
        std::perror("cd");
        return ERROR;
    }
    
    return SUCCESS;
}