#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    std::vector<char> brackets;
    for (char c : s) {
        switch (c) {
            case '[':
            case '{':
            case '(': {
                brackets.push_back(c);
                break;
            }
            case ']':
            {
                if (brackets.empty())
                    return "NO";
                if (brackets.back() != '[') {
                    return "NO";
                }
                brackets.pop_back();
                break;
            }
            case '}':
            {
                if (brackets.empty())
                    return "NO";
                if (brackets.back() != '{') {
                    return "NO";
                }
                brackets.pop_back();
                break;
            }
            case ')':
            {
                if (brackets.empty())
                    return "NO";
                if (brackets.back() != '(') {
                    return "NO";
                }
                brackets.pop_back();
                break;
            }
        }
    }
    if (brackets.empty())
    return "YES";
    else
        return "NO";
}

int main() {
    string res = isBalanced("{[()]}");
    string buf;
    std::getline(std::cin, buf);
    int num = 0;
    std::sscanf(buf.c_str(), "%d", &num);
    std::vector<string> inputs;
    while (num--) {
        std::getline(std::cin, buf);
        inputs.push_back(buf);
    }
    int idx = 0;
    for (auto ins : inputs) {
        res = isBalanced(ins);
        std::cout << idx++ << res << " <= " << ins << std::endl;
    }
    return 0;
}