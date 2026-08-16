#include "minishell.h"

int minishell::builtin_exit(const Args& args) {
    std::cout << "Exiting minishell...\n";
    exit(SUCCESS);
}