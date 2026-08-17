#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <iostream>
#include <string>
#include <vector>

namespace minishell {
    void error_print(const std::string& command,  const std::string& message);

    bool check_too_many_args(const std::vector<std::string>& args, size_t max_args);
    bool check_too_few_args(const std::vector<std::string>& args, size_t min_args);
    bool check_numeric_arg(const std::string& command, const std::string& arg);
}

#endif // ERROR_HANDLING_H