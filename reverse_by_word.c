/*
 * Project Title: Word-by-Word Reversal
 * Description: Flips each word within a string while keeping all the spaces and tabs just where they were.
 *              It’s like doing a backflip with each word without moving from spot.

 * Author: amohame2
 * Date Created: September 12, 2024
 * Last Modified: September 16, 2024
 *

 * Notes:
 * - white spaces are ok to use.
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Reverses each word in the string 'str' in place.
 * A word is defined as a sequence of non-whitespace characters separated by whitespace.
 * Whitespace characters, as defined by isspace(), remain unchanged.
 *
 * @param str The str whose words are to be reversed.
 */


void reverse_by_word(char *str) {
    char *start = str, *end = str, temp;

    while (1) {
        // Skip leading whitespace
        while (*end && isspace((unsigned char)*end)) {
            end++;
        }
        if (!*end) break;

        // Find current word end
        start = end;
        while (*end && !isspace((unsigned char)*end)) {
            end++;
        }

        // Reverse word's char
        char *wordEnd = end - 1;
        while (start < wordEnd) {
            temp = *start;
            *start = *wordEnd;
            *wordEnd = temp;
            start++;
            wordEnd--;
        }
    }
}

/**
 * Unit test for reverse_by_word.
 * Tests reversing various strings.
 *
 * @return int Returns 1 if succeeded, 0 if failed.
 */

int test_reverse_by_word() {
    int allTestsPassed = 1;

    char testString1[] = "Carnegie Mellon";
    char expected1[] = "eigneirC nolleM";
    reverse_by_word(testString1);
    allTestsPassed &= (strcmp(testString1, expected1) == 0);

    char testString2[] = "\tCarnegie \tMellon";
    char expected2[] = "\teigneirC \tnolleM";
    reverse_by_word(testString2);
    allTestsPassed &= (strcmp(testString2, expected2) == 0);

    char testString3[] = "Four";
    char expected3[] = "ruoF";
    reverse_by_word(testString3);
    allTestsPassed &= (strcmp(testString3, expected3) == 0);

    char testString4[] = " One";
    char expected4[] = " enO";
    reverse_by_word(testString4);
    allTestsPassed &= (strcmp(testString4, expected4) == 0);

    char testString5[] = "My heart is in the work";
    char expected5[] = "yM traeh si ni eht krow";
    reverse_by_word(testString5);
    allTestsPassed &= (strcmp(testString5, expected5) == 0);

    if (allTestsPassed) {
        printf("All passed.\n");
        return 1;
    } else {
        printf("Some failed.\n");
        return 0;
    }
}

int main() {
    return test_reverse_by_word();
}
