#include "bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'numberOfItems' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY startIndices
 *  3. INTEGER_ARRAY endIndices
 */

struct SpliterAndNum {
    int idx = 0;
    int numInvPrev = 0;
    int numInvAfter = 0;
};

vector<int> numberOfItems(string s, vector<int> startIndices, vector<int> endIndices) {
    // construct a special list
    std::vector<SpliterAndNum> spliters;
    int total = 0;
    int idx = 0;
    for (char &c : s) {
        if (c == '|') {
            SpliterAndNum sp;
            sp.idx = idx;
            sp.numInvPrev = total;
            spliters.push_back(sp);
        } else if (c == '*') {
            total++;
        }
        idx++;
    }
    for (int i = 0; i < spliters.size(); i++) {
        spliters[i].numInvAfter = total - spliters[i].numInvPrev;
    }
    // compute by look through this list
    std::vector<int> ret;
    for (int i = 0; i < startIndices.size(); i++) {
        int startIdx = startIndices[i] - 1;
        int endIdx = endIndices[i] - 1;
        int prevNum = total;
        int afterNum = total;
        for (int j = 0; j < spliters.size(); j++) {
            SpliterAndNum &sp = spliters[j];
            if (sp.idx >= startIdx) {
                prevNum = sp.numInvPrev;
                break;
            }
        }
        for (int j = spliters.size() - 1; j >= 0; j--) {
            SpliterAndNum &sp = spliters[j];
            if (sp.idx <= endIdx) {
                afterNum = sp.numInvAfter;
                break;
            }
        }
        int num = std::max(0, total - prevNum - afterNum);
        ret.push_back(num);
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string startIndices_count_temp;
    getline(cin, startIndices_count_temp);

    int startIndices_count = stoi(ltrim(rtrim(startIndices_count_temp)));

    vector<int> startIndices(startIndices_count);

    for (int i = 0; i < startIndices_count; i++) {
        string startIndices_item_temp;
        getline(cin, startIndices_item_temp);

        int startIndices_item = stoi(ltrim(rtrim(startIndices_item_temp)));

        startIndices[i] = startIndices_item;
    }

    string endIndices_count_temp;
    getline(cin, endIndices_count_temp);

    int endIndices_count = stoi(ltrim(rtrim(endIndices_count_temp)));

    vector<int> endIndices(endIndices_count);

    for (int i = 0; i < endIndices_count; i++) {
        string endIndices_item_temp;
        getline(cin, endIndices_item_temp);

        int endIndices_item = stoi(ltrim(rtrim(endIndices_item_temp)));

        endIndices[i] = endIndices_item;
    }

    vector<int> result = numberOfItems(s, startIndices, endIndices);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
