# Pipex

## Introduction

Pipex is a 42 school project that aims to recreate the functionality of the shell pipe operator (|) in C. This project helps students understand how processes, file descriptors, and pipes work in Unix-like operating systems.

## Features

-   Simulates the behavior of the shell command: `< file1 cmd1 | cmd2 > file2`
-   Handles input and output redirection
-   Executes commands with their full path
-   Implements error handling and memory management
-   Bonus part: Handles multiple pipes (not implemented in this version)

## Installation

1. Clone the repository:
   `git clone https://github.com/Dang-Hai-Tran/pipex_42.git`
2. Navigate to the cloned repository:
   `cd pipex_42`
3. Compile the project:
   `make`

## Usage

-   Run the executable:
    `./pipex file1 cmd1 cmd2 file2`
-   This is equivalent to the shell command:
    `< file1 cmd1 | cmd2 > file2`

## Project Structure

-   `srcs/`: Contains the main source files
-   `srcs_bonus/`: Contains the bonus part source files (not implemented in this version)
-   `includes/`: Contains the header files
-   `libft/`: Contains the libft library

## Key Components

1. **Main Function**: Initializes the pipex structure, creates pipes, and manages child processes.
2. **Child Processes**: Two child processes are created to execute the commands.
3. **Command Execution**: Searches for the full path of the command and executes it using `execve`.
4. **File Handling**: Opens input and output files and redirects standard input/output accordingly.
5. **Error Handling**: Implements custom error functions for better error reporting.

## Compilation

-   Use `make` to compile the mandatory part
-   Use `make bonus` to compile the bonus part (not implemented in this version)
-   Use `make clean` to remove object files
-   Use `make fclean` to remove object files and the executable
-   Use `make re` to recompile the project

## Notes

-   This project is part of the 42 school curriculum and follows the school's coding standards.
-   The bonus part for handling multiple pipes is not implemented in this version.

## Author

[Dang-Hai Tran](https://github.com/Dang-Hai-Tran)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
