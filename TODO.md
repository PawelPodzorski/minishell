# Minishell TODO

## Shell

* [x] Interactive prompt
* [x] Read input with `std::getline`
* [x] Handle EOF
* [x] Ignore empty input
* [ ] Improve prompt
* [ ] Handle Ctrl+C correctly

## Parser

* [x] Split input into arguments
* [x] Store command in `args[0]`
* [x] Store arguments in `args[1...]`
* [ ] Handle multiple spaces
* [ ] Handle single quotes `'...'`
* [ ] Handle double quotes `"..."`
* [ ] Handle escaped characters
* [ ] Handle special characters
* [ ] Parse pipes `|`
* [ ] Parse redirections
* [ ] Parse background operator `&`

## Built-ins

### `exit`

* [x] Basic `exit`
* [x] Handle exit status
* [x] Handle invalid arguments
* [x] Handle multiple arguments

### `pwd`

* [x] Basic `pwd`
* [x] Error handling
* [ ] `pwd` arguments/options

### `cd`

* [x] Basic `cd <path>`
* [x] Absolute paths
* [x] Relative paths
* [x] Proper error handling
* [ ] `cd` without arguments → `$HOME`
* [ ] `cd ~`
* [ ] `cd -`
* [ ] Update `PWD`
* [ ] Update `OLDPWD`
* [ ] Too many arguments

### `echo`

* [ ] Basic `echo`
* [ ] `echo -n`
* [ ] Handle arguments

### `export`

* [ ] Basic `export`
* [ ] Set environment variables
* [ ] Validate variable names
* [ ] Display exported variables

### `unset`

* [ ] Remove environment variables
* [ ] Validate variable names

### `env`

* [x] Display environment
* [ ] Handle arguments/options

### `ls`

* [ ] Basic directory listing
* [ ] `-a`
* [ ] `-l`
* [ ] `-la` / `-al`
* [ ] Directory argument
* [ ] Error handling

## External Commands

* [ ] Detect non-built-in commands
* [ ] `fork()`
* [ ] `execvp()`
* [ ] `waitpid()`
* [ ] Handle command-not-found
* [ ] Handle exit status
* [ ] Search `$PATH`

Example target:

```text
minishell$ cat file.txt
```

```text
shell
  ↓
fork()
  ↓
child
  ↓
execvp()
  ↓
cat
```

## Redirections

* [ ] `>`
* [ ] `>>`
* [ ] `<`
* [ ] `2>`
* [ ] `2>>`
* [ ] `dup2()`
* [ ] Proper file opening/closing
* [ ] Error handling

Examples:

```text
echo hello > file.txt
echo hello >> file.txt
cat < file.txt
```

## Pipes

* [ ] Basic `|`
* [ ] `pipe()`
* [ ] Connect stdout to stdin with `dup2()`
* [ ] Multiple pipes
* [ ] Properly close pipe file descriptors
* [ ] Wait for all child processes

Example:

```text
ls | grep cpp
```

## Environment

* [ ] Read environment variables
* [ ] `$VAR` expansion
* [ ] `$HOME`
* [ ] `$PATH`
* [ ] `$PWD`
* [ ] `$OLDPWD`
* [ ] `$?` last exit status

## Processes

* [ ] Understand parent/child relationship
* [ ] Background processes
* [ ] `&`
* [ ] Process exit status

## Signals

* [ ] `SIGINT`
* [ ] `SIGQUIT`
* [ ] Ctrl+C
* [ ] Ctrl+\
* [ ] Correct signal behaviour for child processes

## History

* [ ] Store commands
* [ ] `history`
* [ ] Up/down arrow navigation
* [ ] Save history
* [ ] Load history
