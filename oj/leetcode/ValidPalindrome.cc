class Solution {
public:
    bool isPalindrome(string s) {
        
        if (s.empty()) return true;
        if (s.length() == 1) return true;
        
        std::string aux;
        for (int i = 0; i < s.length(); i++) {
            if ((20 <= s[i] && s[i] <= 47) // ascii from SPACE to '/'
            || (58 <= s[i] && s[i] <= 64) // ascii from ':' to '@'
            || (91 <= s[i] && s[i] <= 96) // ascii from '[' to '`'
            || (123 <= s[i] && s[i] <= 126)) // ascii from '{' to '~'
            continue;
            else aux.append(1, s[i]);
        }
            
        int front = 0, back = aux.length() - 1;
        while (front < back) {
            if (tolower(aux[front]) != tolower(aux[back])) return false;
            front++, back--;
        }
        return true;
    }
};
