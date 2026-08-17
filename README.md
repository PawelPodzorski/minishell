# Minishell

A small Unix shell written in C++.

The goal of this project is to learn how shells work internally, including command parsing, built-in commands, process creation, external command execution, pipes, redirections, and environment handling.

## Build and Run

Clone the repository:

```bash
git clone <repository-url>
cd minishell
```
Build the project and clean build files:

```bash
make
```
Run:

```
./minishell
```


## Current Features

### Shell loop

* Interactive prompt: `minishell$`
* Reads commands from standard input
* Handles EOF (`Ctrl+D`)
* Ignores empty input

### Parser

* Parses user input into command arguments
* Stores the command and its arguments in `std::vector<std::string>`

For example:

```text
cd /home/user
```

becomes:

```text
args[0] = "cd"
args[1] = "/home/user"
```
### Environment

* Reads environment variables through `environ`
* Displays environment variables with `env`
* Uses `getenv()` to access environment variables
* Updates `PWD` and `OLDPWD` when using `cd`

### Built-in commands

Currently implemented:

* `exit`
  * Exit status
  * Invalid numeric arguments
  * Multiple arguments handling
* `pwd`
  * Print current working directory
  * Error handling
* `cd`
  * Absolute paths
  * Relative paths
  * `cd` → `$HOME`
  * `cd ~`
  * `cd -`
  * Updates `PWD`
  * Updates `OLDPWD`
* `env`
  * Display environment variables

Built-ins are stored in an `std::unordered_map` and dispatched based on the command name.

Conceptually:

```text
command
   ↓
args[0]
   ↓
builtins.find(args[0])
   ↓
builtin function
```

## Planned Features

The shell will eventually support:

* More built-in commands
* Flags
* External command execution
* `fork()`
* `execvp()`
* `waitpid()`
* Pipes
* Input/output redirection
* Environment variables
* Signals
* Command history
