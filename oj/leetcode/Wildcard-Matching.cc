class Solution {
private:
    bool match(const char *pattern, const char * text) {
        // If we reach at the end of both strings, we are done
        if (*pattern == '\0' && *text == '\0')
            return true;

        if (*pattern == '*' && *text == '\0') 
            return match(pattern + 1, text);

        // Make sure that the characters after '*' are present in second string.
        if (*pattern == '*' && *(pattern + 1) != '\0' && *text == '\0')
            return false;

        if (*pattern == '?' && *text == '\0')
            return false;

        // If the first string contains '?', or current characters of both 
        // strings match
        if (*pattern == '?' || *pattern == *text)
            return match(pattern + 1, text + 1);

        if (*pattern == '*' && *(pattern + 1) == '*')
            return match(pattern + 1, text);

        // If there is *, then there are two possibilities
        //     a) We consider current character of second string
        //     b) We ignore current character of second string.
        if (*pattern == '*')
            return match(pattern + 1, text) || match(pattern, text + 1);

        return false;
}

public:
    bool isMatch(const char *s, const char *p) {
        return match(p, s);
    }
};
