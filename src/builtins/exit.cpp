#include "minishell.h"

int minishell::builtin_exit(const Args& args) {
    std::cout << "Exiting minishell...\n";

    if (minishell::check_too_many_args(args, 1)) {
        return ERROR;
    }

    if (args.size() > 1 && !minishell::check_numeric_arg(args[0], args[1])) {
        return ERROR;
    }
    exit(args.size() > 1 ? std::stoi(args[1]) : 0);
}