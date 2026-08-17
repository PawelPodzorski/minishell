#include "error_handling.h"

namespace minishell {
    void error_print(const std::string& command, const std::string& message) {
        std::cerr << "minishell: " << command << ": " << message << std::endl;
    }

    bool check_too_many_args(const std::vector<std::string>& args, size_t max_args) {
        if (args.size() -1 > max_args) {
            error_print(args[0], "too many arguments");
            return true;
        }
        return false;
    }

    bool check_too_few_args(const std::vector<std::string>& args, size_t min_args) {
        if (args.size() -1 < min_args) {
            error_print(args[0], "too few arguments");
            return true;
        }
        return false;
    }

    bool check_numeric_arg(const std::string& command, const std::string& arg) {
        try {
            size_t pos = 0;
            std::stoi(arg, &pos);
            if (pos != arg.size()) {
                error_print(command, "numeric argument required");
                return false;
            }
        }
        catch (const std::invalid_argument&) {
            error_print(command, "numeric argument required");
            return false;
        }
        catch (const std::out_of_range&) {
            error_print(command, "numeric argument out of range");
            return false;
        }
        return true;
    }
}