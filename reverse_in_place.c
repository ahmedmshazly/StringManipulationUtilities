/*
 * Project Title: Scrabble Tile Reverse
 * Description: This function reverses a given null-terminated string in place, also converting
 *              all characters to lowercase. This is usually  used for case-insensitive comparisons
 *              or for creating standardized data formats as I have read online.

 * Author: AHMED MOHAMED (amohame2)
 * Date Created: September 13, 2024
 * Last Modified: September 16, 2024
 *

 * Notes:
 * - This function operates directly on the input string, modifying it.
 * - Designed to be efficient in memory usage by not allocating additional buffers.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Reverses a null-terminated str in-place and converts it to lower-case.
 * This is done directly on the passed string.
 *
 * @param str The str to be reversed and converted to lower-case.
 */

void reverse_in_place(char *str) {
    int len = strlen(str);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        temp = tolower(str[i]);
        str[i] = tolower(str[len - i - 1]);
        str[len - i - 1] = temp;
    }

    // If str has odd length, convert middle lower the char
    if (len % 2 == 1) {
        str[len / 2] = tolower(str[len / 2]);
    }
}

/**
 * Unit test for reverse_in_place.
 * Tests various input strings and validates results.
 *
 * @return int Returns 1 if succeeded, 0 if failed.
 */
int test_reverse_in_place() {
    int allTestsPassed = 1;
    char testString1[] = "Carnegie Mellon";
    char expected1[] = "nollem eigneirac";
    reverse_in_place(testString1);
    allTestsPassed &= (strcmp(testString1, expected1) == 0);

    char testString2[] = "Four";
    char expected2[] = "ruof";
    reverse_in_place(testString2);
    allTestsPassed &= (strcmp(testString2, expected2) == 0);

    char testString3[] = " One";
    char expected3[] = "eno ";
    reverse_in_place(testString3);
    allTestsPassed &= (strcmp(testString3, expected3) == 0);

    if (allTestsPassed) {
        printf("All passed.\n");
        return 1;
    } else {
        printf("Some failed.\n");
        return 0;
    }
}

int main() {
    return test_reverse_in_place();

}
