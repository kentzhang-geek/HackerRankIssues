#include "bits/stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'processLogs' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY logs
 *  2. INTEGER threshold
 */
bool useridComparator(std::string &a, std::string &b) {
    return std::stoi(a) < std::stoi(b);
}

vector<string> processLogs(vector<string> logs, int threshold) {
    std::map<string, int> userTransactionMap;
    for (std::string & s : logs) {
        std::string sender;
        std::string recipient;
        sender.resize(12);
        recipient.resize(12);
        std::sscanf(s.c_str(), "%s %s ", sender.c_str(), recipient.c_str());
        if (userTransactionMap.find(sender) == userTransactionMap.end()) {
            userTransactionMap[sender] = 0;
        }
        if (userTransactionMap.find(recipient) == userTransactionMap.end()) {
            userTransactionMap[recipient] = 0;
        }
        userTransactionMap[sender] += 1;
        if (sender != recipient) {
            userTransactionMap[recipient] += 1;
        }
    }
    std::vector<std::string> ret;
    for (auto kvpair : userTransactionMap) {
        if (kvpair.second >= threshold) {
            ret.push_back(kvpair.first);
        }
    }
    std::sort(ret.begin(), ret.end(), useridComparator);
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string logs_count_temp;
    getline(cin, logs_count_temp);

    int logs_count = stoi(ltrim(rtrim(logs_count_temp)));

    vector<string> logs(logs_count);

    for (int i = 0; i < logs_count; i++) {
        string logs_item;
        getline(cin, logs_item);

        logs[i] = logs_item;
    }

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    vector<string> result = processLogs(logs, threshold);

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
