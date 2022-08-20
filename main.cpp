#include <iostream>
#include <vector>
#include <string>
#include <map>

bool isClamp(int v, int minv, int maxv) {
    return (v >= minv) && (v <= maxv);
}

bool check(std::string &s, int posa, int posb) {
    char a = s[posa];
    char b = s[posb];

    if (!isClamp(posa, 0, s.length() - 1)
    || !isClamp(posb, 0, s.length() -1))
        return false;
    if (s[posa] == s[posb])
        return true;
    else
        return false;
}

bool checkPalidrome(std::string &s, int posa, int posb) {
    while (posa < posb) {
        if (check(s, posa, posb)) {
            posa++;
            posb--;
        }
        else {
            return false;
        }
    }
    return true;
}

int removeOneToPalindrome(std::string s) {
    int posa = 0;
    int posb = s.length() - 1;
    int pos = -1;
    while (posa < posb) {
        if (check(s, posa, posb)) {
            posa++;
            posb--;
        }else {
            bool checkleft = check(s, posa + 1, posb);
            bool checkright = check(s, posa, posb - 1);
            if (checkleft) {
                pos = posa;
                if (checkPalidrome(s, posa + 1, posb))
                    return pos;
            }
            if (checkright) {
                pos = posb;
                if (checkPalidrome(s, posa, posb - 1))
                    return pos;
            }
            return -1;
        }
    }
    return pos;
}

int main() {
    std::string s = "qerpiupiucva";
    std::string target = s;
    for (char x : s) {
        target.insert(0, 1, x);
    }
    target.insert(16, 1, 'm');
    std::cout << removeOneToPalindrome(target) << std::endl;
    std::cout << removeOneToPalindrome("") << std::endl;
    std::cout << removeOneToPalindrome("aa") << std::endl;
    std::cout << removeOneToPalindrome("ab") << std::endl;
    std::cout << removeOneToPalindrome("aba") << std::endl;
    std::cout << removeOneToPalindrome("abab") << std::endl;
    std::cout << removeOneToPalindrome("ababa") << std::endl;
    std::cout << removeOneToPalindrome("abba") << std::endl;
    std::cout << removeOneToPalindrome("hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh") << std::endl;
    std::string x = "hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh";
    std::cout << x << std::endl;
    x.erase(44, 1);
    std::cout << x << std::endl;
    std::reverse(x.begin(), x.end());
    std::cout << x << std::endl;

    return 0;
}
