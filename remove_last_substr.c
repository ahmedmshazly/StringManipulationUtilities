/*
 * Project Title: Substring Removal
 * Description: This function removes the last occurrence of a specified substring from a string.
 *              The main string is modified in place, and returns the index from where
 *              the substring was removed, or -1 if the substring not found.

 * Author: AHMED MOHAMED (amohame2)
 * Date Created: September 12, 2024
 * Last Modified: September 14, 2024
 *

 * Notes:
 * - Handles cases where the substring is empty by returning end of the main str.
 * - Can be useful in text processing applications where substrings need to be dynamically removed.
 */

#include <stdio.h>
#include <string.h>

/**
 * Removes the last occurrence of 'substr' from 'str', modifying 'str' in place.
 * Returns index of the start of the last occurrence, or -1 if 'substr' is not-found.
 *
 * @param str The main str from which the substring will be removed.
 * @param substr Substring to remove.
 * @return The index from where the substring was removed, or -1 if not-found.
 */

int remove_last_substr(char *str, const char *substr) {
    int lastPos = -1;
    int substrLen = strlen(substr);
    int strLen = strlen(str);

    if (substrLen == 0) return strLen;  // Return str len if empty substring

    for (int i = 0; i <= strLen - substrLen; i++) {
        if (strncmp(str + i, substr, substrLen) == 0) {
            lastPos = i;
        }
    }

    if (lastPos != -1) {
        // Shift to overwrite
        memmove(str + lastPos, str + lastPos + substrLen, strLen - lastPos - substrLen + 1);
    }

    return lastPos;
}

/**
 * Unit test for remove_last_substr.
 * testing removinb the last occurrence of the substrings  .
 *
 * @return int Returns 1 if succeed, 0 if failed.
 */

int test_remove_last_substr() {
    char str1[] = "Carnegie Mellon";
    char str2[] = "Carnegie Mellon";
    char str3[] = "Carnegie Mellon";
    char str4[] = "one two one three";
    char str5[] = "one two one three";
    char str6[] = "Bananas";
    int pass = 1;

    pass &= (remove_last_substr(str1, "Carnegie ") == 0 && strcmp(str1, "Mellon") == 0);
    pass &= (remove_last_substr(str2, "Kiltie") == -1 && strcmp(str2, "Carnegie Mellon") == 0);
    pass &= (remove_last_substr(str3, "") == 15 && strcmp(str3, "Carnegie Mellon") == 0);
    pass &= (remove_last_substr(str4, "one ") == 8 && strcmp(str4, "one two three") == 0);
    pass &= (remove_last_substr(str5, "hr") == 13 && strcmp(str5, "one two one tee") == 0);
    pass &= (remove_last_substr(str6, "a") == 5 && strcmp(str6, "Banans") == 0);

    if (pass) {
        printf("All passed.\n");
        return 1;
    } else {
        printf("Some failed.\n");
        return 0;
    }
}

int main() {
    return test_remove_last_substr();
}
