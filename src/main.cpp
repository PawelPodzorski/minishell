#include <minishell.h>

using BuiltinFunction = std::function<void(const Args&)>;

std::unordered_map<std::string, BuiltinFunction> builtins = {
    {"exit", minishell::builtin_exit},
    {"pwd", minishell::builtin_pwd},
    {"cd", minishell::builtin_cd},
    {"env", minishell::builtin_env}
};

void HandleBuiltinCommands(const Args& args, const std::unordered_map<std::string, BuiltinFunction>& builtins);

int main() {
    std::string input;
    std::vector<std::string> args;

    while(true) {
        std::cout << "\033[1mminishell$ \033[0m"; // bold

        // Read user input
        if (!std::getline(std::cin, input)) {
            std::cout << '\n';
            break;
        }
        
        if (input.empty()) {
            continue;
        }
        
        args = minishell::parse_input(input);

        HandleBuiltinCommands(args, builtins);
    }
    return 0;
}

void HandleBuiltinCommands(const Args& args, const std::unordered_map<std::string, BuiltinFunction>& builtins) {
    if (args.empty()) {
        return;
    }

    auto it = builtins.find(args[0]);

    if (it != builtins.end()) {
        it->second(args);
        return;
    } else {
        std::cout << args[0] << ": command not found" << '\n';
    }
}