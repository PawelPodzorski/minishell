#ifndef MINISHELL_H
#define MINISHELL_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <functional>


#define SUCCESS 0
#define ERROR 1

using Args = std::vector<std::string>;


namespace minishell {
    // builtins
    int builtin_exit(const Args& args);
    int builtin_pwd(const Args& args);
    int builtin_cd(const Args& args);

    std::vector<std::string> parse_input(const std::string& input);
}

#endif // MINISHELL_H