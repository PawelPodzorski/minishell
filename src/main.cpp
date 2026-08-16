#include <minishell.h>

void HadnleBuildinCommands(const std::vector<std::string>& args);

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

        HadnleBuildinCommands(args);
    }
    return 0;
}

void HadnleBuildinCommands(const std::vector<std::string>& args) {
    if (args.empty()) {
        return;
    }

    if (args[0] == "exit") {
        minishell::buildin_exit();
    }
    else if (args[0] == "pwd") {
        minishell::builtin_pwd();
    }
    else if (args[0] == "cd") {
        if (args.size() < 2) {
            std::cerr << "cd: missing argument\n";
            return;
        }
        minishell::builtin_cd(args[1]);
    }
    else {
        std::cout << args[0] << ": command not found" << '\n';
    }
}