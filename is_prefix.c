/*
 * Project Title: Prefix Checker
 * Description: This function checks if a given string starts with the specified prefix.
 *              It's maybe used in games like Scrabble to validate tile sequences, as it becomes
 *              handy when you're trying to figure if a particular move starts with a bonus tile.
 * Author: AHMED MOHAMED (amohame2)
 * Date Created: September 12, 2024
 * Last Modified: September 15, 2024
 *
 * Notes:
 * - The function treats all characters equally and is case-sensitive. Ensure that
 *   your inputs match the expected cases to avoid mismatches.
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * Checks if the string 'str' begins with the sequence of chars in 'prefix'.
 * Returns true if 'str' begins with 'prefix' and false otherwise.
 *
 * Note the empty string "" is a valid prefix for all strings.
 *
 * @param prefix The prefix to check.
 * @param str The string to check against the prefix.
 * @return true if str starts with prefix, false otherwise.
 */
bool is_prefix(const char *prefix, const char *str) {
    // Iterate over chars
    while (*prefix) {
        if (*prefix != *str) return false;
        // Move to next char
        prefix++;
        str++;
    }
    // If all chars matched, return true
    return true;
}

/**
 * Unit test for is_prefix
 * This function tests various scenarios to ensure the is_prefix function works as expected and well.
 *
 * @return int Returns 1 if all tests succeed, 0 if any fail.
 */
int test_is_prefix() {
    bool result = true;
    result &= is_prefix("C", "Carnegie Mellon") == true;
    result &= is_prefix("Carnegie", "Carnegie Mellon") == true;
    result &= is_prefix("Carnegie Mellon", "Carnegie Mellon") == true;
    result &= is_prefix("Cab", "Carnegie Mellon") == false;
    result &= is_prefix("car", "Carnegie Mellon") == false; //case test
    result &= is_prefix("", "Carnegie Mellon") == true; // empty test
    result &= is_prefix("Carnegie Mellon University", "Carnegie Mellon") == false; // test prefx longer than str
    result &= is_prefix("Carnegie", "") == false; // test empty str

    if (result) {
        printf("All passed.\n");
        return 1;
    } else {
        printf("Some failed.\n");
        return 0;
    }
}

int main() {
    return test_is_prefix();
}
