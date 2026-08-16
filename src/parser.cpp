#include "minishell.h"

using std::vector;

vector<std::string> minishell::parse_input(const std::string& input) {
    vector<std::string> args;
    std::stringstream ss(input);
    std::string token;

    while (ss >> token) {
        args.push_back(token);
    }

    return args;
}