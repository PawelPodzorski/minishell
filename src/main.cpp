#include <minishell.h>

int main() {
    std::string input;

    while(true) {
        std::cout << "\033[1mminishell$ \033[0m"; // bold
        std::getline(std::cin, input);
        
        // Skip empty input
        if (input.empty()) {
            continue;
        }

        // Exit condition
        if (input == "exit") {
            break;
        }
        
        
        // Execute the command using system()
        int status = system(input.c_str());
        if (status == -1) {
            std::cerr << "Error executing command: " << input << '\n';
        }
    }
    return 0;
}