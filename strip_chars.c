/*
 * Project Title: Character Stripping
 * Description: This function removes all occurrences of specified chars from a string.
 *              The string is modified in place, and all chars listed in 'remove_chars'
 *              str are removed.
 * Author: AHMED MOHAMED (amohame2)
 * Date Created: September 12, 2024
 * Last Modified: September 17, 2024
 *
 * Notes:
 * - This function filters out unwanted chars from a string, which can be useful (actually it is useful, otherwise why we are doing it)
 *   for cleaning text data or preparing strings for further processing.
 */

#include <stdio.h>
#include <string.h>

/**
 * Removes all chars  present in 'remove_chars' from 'str'.
 * It is an in-place operation --> 'str' is modified directly in-place.
 *

 * @param str The main str from which chars are removed.
 * @param remove_chars a str containing all chars that should be removed from str.
 */

void strip_chars(char *str, const char *remove_chars) {
    char *src = str, *dst = str;
    while (*src) {
        const char *temp = remove_chars;
        while (*temp && *temp != *src) temp++; // Search src char in remove_chars
        if (!*temp) {
            *dst++ = *src; // If char not-found, copy-->dst
        }
        src++;
    }
    *dst = '\0'; // modified str null-terminatation
}

/**
 * Unit test for strip_chars.
 * Tests stripping various chars from strings.
 *
 * @return int 1 if all succeed, 0 if fail.
 */

int test_strip_chars() {
    int pass = 1;
    char str1[] = "Carnegie Mellon";
    strip_chars(str1, "l ");
    pass &= strcmp(str1, "CarnegieMeon") == 0;

    char str2[] = "Carnegie Mellon";
    strip_chars(str2, "el ");
    pass &= strcmp(str2, "CarngiMon") == 0;

    char str3[] = "Carnegie Mellon";
    strip_chars(str3, "");
    pass &= strcmp(str3, "Carnegie Mellon") == 0;

    char str4[] = "one two three";
    strip_chars(str4, "thre");
    pass &= strcmp(str4, "on wo ") == 0;

    char str5[] = "Bananas";
    strip_chars(str5, "a");
    pass &= strcmp(str5, "Bnns") == 0;

    char str6[] = "Bananas";
    strip_chars(str6, "Bnas");
    pass &= strcmp(str6, "") == 0;

    if (pass) {
        printf("All tests passed.\n");
        return 1; // Success
    } else {
        printf("Some tests failed.\n");
        return 0; // Failure
    }
}

int main() {
    return test_strip_chars();
}
