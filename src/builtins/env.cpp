#include "minishell.h"

extern char** environ;

int minishell::builtin_env(const Args& args){
    if (minishell::check_too_many_args(args, 0)) {
        return ERROR;
    }

    for (char** env = environ; *env != nullptr; ++env) {
        std::cout << *env << std::endl;
    }
    
    return SUCCESS;
}