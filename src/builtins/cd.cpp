#include "minishell.h"


int minishell::builtin_cd(const Args& args) {
    if (check_too_many_args(args, 1)) return ERROR;
    
    const std::string& path = args[1];
    // Attempt to change the current working directory
    if (chdir(path.c_str()) == -1) {
        minishell::error_print(args[0], "can't oppen this path");
        return ERROR;
    }
    
    return SUCCESS;
}