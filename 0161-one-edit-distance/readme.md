Problem Description
This problem asks you to determine if two strings are exactly one edit distance apart. Two strings are considered one edit distance apart if you can transform one string into the other by performing exactly one of these operations:

Insert one character: Add exactly one character at any position in string s to make it equal to string t. For example, "ab" → "adb" (insert 'd').

Delete one character: Remove exactly one character from string s to make it equal to string t. For example, "abc" → "ac" (delete 'b').

Replace one character: Change exactly one character in string s to a different character to make it equal to string t. For example, "abc" → "adc" (replace 'b' with 'd').

The key requirements are:

Exactly one edit operation must be performed (not zero, not more than one)
For replacement, the character must be changed to a different character (not the same)
Return true if the strings are one edit distance apart, false otherwise
Examples of strings that are one edit distance apart:

"ab" and "acb" (insert 'c')
"cab" and "ab" (delete 'c')
"1203" and "1213" (replace '0' with '1')
Examples of strings that are NOT one edit distance apart:

"ab" and "ab" (zero edits needed - they're already equal)
"ab" and "adb" (this would be one edit, so it IS one edit distance apart)
"ab" and "adcb" (requires two insertions)
