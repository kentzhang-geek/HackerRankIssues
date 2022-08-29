#include "bits/stdc++.h"
#include <vector>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */
// there are abcdefghij 10 choises of child node
class TreeNode {
public:
    TreeNode() {};
    bool isLeaf = false;
    char c = 'a';
    size_t wordIdx = -1;
    std::shared_ptr<TreeNode> children[10];

    static size_t mapIndex(char c) { return c - 'a'; };
    typedef enum {
        GOODSET = 0,
        BADSET = 1,
    } SetType;

    static SetType check(std::shared_ptr<TreeNode> root, std::string word) {
        TreeNode *ptr = root.get();
        // search the tree
        bool hasNew = false;
        for (char c: word) {
            if (ptr->isLeaf) {
                return BADSET;
            }
            if (ptr->children[mapIndex(c)]) {
                ptr = ptr->children[mapIndex(c)].get();
            } else {
                ptr->children[mapIndex(c)] = std::shared_ptr<TreeNode>(new TreeNode());
                ptr = ptr->children[mapIndex(c)].get();
                hasNew = true;
            }
        }
        if (hasNew) {
            ptr->isLeaf = true;
            return GOODSET;
        } else {
            return BADSET;
        }
    }
};

void noPrefix(vector<string> words) {
    std::shared_ptr<TreeNode> root(new TreeNode);
    for (auto w : words) {
        auto ret = TreeNode::check(root, w);
        if (ret == TreeNode::BADSET) {
            std::cout << "BAD SET" << std::endl;
            std::cout << w << std::endl;
            return;
        }
    }
    std::cout << "GOOD SET" << std::endl;
    return;
}

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
