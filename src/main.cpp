#include <minishell.h>

int main() {
    std::string input;

    while(true) {
        std::cout << "\033[1mminishell$ \033[0m"; // bold
        std::getline(std::cin, input);
        
        if (input == "exit") {
            break;
        }
        
        // Placeholder
        // process the input command
        std::cout << "You entered: " << input << '\n';
    }
    return 0;
}