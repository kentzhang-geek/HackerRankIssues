#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */
void computePrimaryNumbers(std::vector<int> &pnums, int round) {
    int current_num = 2;
    while (pnums.size() < round) {
        if (current_num > 2) {
            int sqrt_current = static_cast<int>(std::sqrt(current_num));
            bool is_primary = true;
            for (int factor = 2; factor <= sqrt_current; factor++) {
                if (current_num % factor == 0) {
                    is_primary = false;
                    break;
                }
            }
            if (is_primary) {
                pnums.push_back(current_num);
            }
        } else {
            pnums.push_back(current_num);
        }
        current_num++;
    }
}

vector<int> waiter(vector<int> number, int q) {
    std::vector<int> primary_nums;
    std::vector<int> results;
    computePrimaryNumbers(primary_nums, q);
    std::reverse(number.begin(), number.end());
    std::vector<int> StackA;
    std::vector<int> StackB;
    for (int i = 0; i < q; i++) {
        for (int & num: number) {
            if (num % primary_nums[i] == 0) {
                StackB.push_back(num);
            } else {
                StackA.push_back(num);
            }
        }
        number = StackA;
        std::reverse(number.begin(), number.end());
        StackA.clear();
        while(!StackB.empty()) {
            results.push_back(StackB.back());
            StackB.pop_back();
        }
        if (number.empty())
            break;
    }
    for (int &num:number) {
        results.push_back(num);
    }
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];

        if (i != result.size() - 1) {
            std::cout << "\n";
        }
    }

    std::cout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
