#include "minishell.h"


int minishell::builtin_cd(const Args& args) {
    if (args.size() < 2) {
        std::cerr << "cd: missing argument\n";
        return ERROR;
    }
    const std::string& path = args[1];
    // Attempt to change the current working directory
    if (chdir(path.c_str()) == -1) {
        std::perror("cd");
        return ERROR;
    }
    
    return SUCCESS;
}