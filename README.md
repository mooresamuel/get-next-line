# Get Next Line - 42 London

**Get Next Line** is a project at **42 London** designed to implement a function that reads a line from a file descriptor, returning the line as a string. The project focuses on memory management, handling multiple file descriptors, and working with the **Unix `read()`** system call to implement a function that behaves like the standard library function `getline()`.

---

## 🔑 Project Overview

The goal of this project is to create a function that reads a line from a file descriptor, handling files that contain newlines and ensuring the efficient use of memory. The function must read the file one buffer at a time and return the content line-by-line. Key concepts covered in this project include:

- File I/O
- Memory management
- Buffer handling
- String manipulation

---

## 📝 Project Requirements

Your **get_next_line** function should:
1. **Read a line** from a file descriptor (`fd`).
2. **Return** a line of text (string) including the newline character `\n`.
3. Handle **multiple file descriptors** (if needed).
4. Handle **buffering** efficiently, using `read()` to read from the file descriptor.

---

## 🚀 How it Works

1. **File Descriptors**: The function should be capable of handling multiple file descriptors simultaneously.
2. **Buffers**: The function uses a buffer to store data read from the file descriptor. The buffer is processed to extract a full line.
3. **Line Construction**: As the function reads from the file, it adds characters to a string buffer until a newline `\n` or the end of the file (`EOF`) is reached. It then returns the line.
4. **Memory Management**: The function should handle memory allocation for each line and free it properly after use.

---

## 💡 Function Prototypes


```c
char *get_next_line(int fd);
```

## Parameters:

`fd`: The file descriptor from which data is read.

## Return Value:

A string representing the next line read from the file descriptor, or NULL if no more lines are available (e.g., EOF).

## 🛠️ Compilation
To compile the project, follow these steps:

## Clone the repository:

```bash
git clone https://github.com/mooresamuel/get_next_line.git
cd get_next_line
```
```bash
make
```
This will generate the object files and the get_next_line.a static library.

## Clean up: To remove the object files:
'''bash
make clean
'''
To remove all compiled files, including the static library:

'''bash
make fclean
'''
To recompile everything from scratch:

```bash
make re
```

## 🧪 Example Usage
To use the get_next_line function, you can include the header get_next_line.h and call the function as follows:


```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    char *line;

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the file line by line
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // Don't forget to free the memory after use
    }

    close(fd);
    return 0;
}
```

This will read the file file.txt line by line, printing each line to the console. Make sure to call free() after each line to properly manage memory.

## 📚 Files
'get_next_line.c': Contains the implementation of the get_next_line function.
'get_next_line.h': Header file with function prototypes and necessary includes.
'Makefile': Automates the build process, compiling the project into a static library libft.a.

## 💡 Key Concepts & Challenges
Memory Management: Handling memory efficiently by allocating and freeing memory as needed for each line.
Buffers: Implementing buffer management with efficient reading from the file descriptor.
Handling Multiple File Descriptors: Ensuring the function can handle multiple file descriptors at once.
Edge Case Handling: Managing cases such as reaching the end of a file, encountering an empty line, or errors during reading.

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

## 🤝 Collaboration
Feel free to contribute to this project! Fork it, submit issues, or open a pull request. If you have suggestions or feedback, don’t hesitate to reach out.

Happy coding! 🚀
