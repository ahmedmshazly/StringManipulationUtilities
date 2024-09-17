# StringManipulationUtilities

This repository contains several C programs designed to manipulate strings and substrings. These utilities include functions for reversing strings, removing specific characters, stripping unwanted characters, and more.

## Programs Included

1. **reverse_in_place** - Reverses a string in place and converts it to lowercase.
2. **reverse_by_word** - Reverses each word in a string while maintaining whitespace.
3. **remove_last_substr** - Removes the last occurrence of a specified substring from a string.
4. **strip_chars** - Removes all occurrences of specified characters from a string.
5. **is_prefix** - Checks if a string begins with the sequence of chars in a prefix

Each utility is accompanied by its own unit test to ensure functionality.

## Building the Code

### Prerequisites

Make sure you have a C compiler installed on your system. GCC is recommended. You can check if GCC is installed and its version by running:

```bash
gcc --version
```

### Compilation
To compile any of the programs, use the following GCC command:

```bash
gcc -o program_name program_name.c
```

Replace `program_name` with the name of the program you wish to compile. For example, to compile the `reverse_in_place` utility, you would use:

```bash
gcc -o reverse_in_place reverse_in_place.c
```

### Running the Programs

After compilation, you can run the program using:

```bash
./program_name
```

For example:

```bash
./reverse_in_place
```
This will execute the program and show any output, including the results of unit tests.


## Testing
Each program has a corresponding unit test function that is called when you run the program. The tests will automatically run, and you will see the test results in the console output.

## Contributions
Feel free to fork this repository and submit pull requests with improvements or corrections to the utilities. Please make sure all changes are accompanied by corresponding unit tests.

License
This project is licensed under the MIT License - see the LICENSE.md file for details.

Contact
Author: AHMED MOHAMED (ahmdmshazly@cmu.edu)
Date Created: September 14, 2024
Last Modified: September 17, 2024

For any additional questions or feedback, please contact (email)[mailto:ahmdmshazly@cmu.edu].












