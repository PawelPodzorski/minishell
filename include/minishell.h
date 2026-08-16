#ifndef MINISHELL_H
#define MINISHELL_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>


#define SUCCESS 0
#define ERROR 1


namespace minishell {
    // builtins
    int buildin_exit();
    int builtin_pwd();
    int builtin_cd(const std::string& path);

    std::vector<std::string> parse_input(const std::string& input);
}

#endif // MINISHELL_H