#include "minishell.h"

int minishell::buildin_exit() {
    std::cout << "Exiting minishell...\n";
    exit(SUCCESS);
}