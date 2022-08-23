#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CMD {
public:
    int command_id = -1;
    virtual void Do(std::string &buf) = 0;
    virtual void Undo(std::string &buf) = 0;
};

class Append : public CMD{
public:
    Append(std::string _s) : s(_s) {

    }
    void Do(string &buf) override {
        buf.append(this->s);
    }

    void Undo(string &buf) override {
        buf.erase(buf.size() - s.size(), s.size());
    }
    std::string s;
};

class RemoveLast : public CMD {
public:
    RemoveLast(int _n) : n(_n) {}

    void Do(string &buf) override {
        this->n = std::min(this->n, (int)buf.size());
        this->backup = buf.substr(buf.size() - this->n, this->n);
        buf.erase(buf.size() - this->n, this->n);
    }

    void Undo(string &buf) override {
        buf.append(this->backup);
    }

    int n;
    std::string backup;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string result;
    std::string buf;
    std::getline(std::cin, buf);
    int num = 0;
    std::sscanf(buf.c_str(), "%d", &num);
    std::vector<std::shared_ptr<CMD>> cmds;
    while(num-->0) {
        std::getline(std::cin, buf);
        switch (buf[0]) {
            case '1': {
                buf.erase(0,2);
                cmds.push_back(std::shared_ptr<CMD>(new Append(buf)));
                cmds.back()->Do(result);
                break;
            }
            case '2': {
                buf.erase(0,2);
                int n = 0;
                std::sscanf(buf.c_str(), "%d", &n);
                cmds.push_back(std::shared_ptr<CMD>(new RemoveLast(n)));
                cmds.back()->Do(result);
                break;
            }
            case '3': {
                buf.erase(0,2);
                int n = 0;
                std::sscanf(buf.c_str(), "%d", &n);
                std::cout << result[std::min(n - 1, (int)result.size() - 1)] << std::endl;
                break;
            }
            case '4': {
                cmds.back()->Undo(result);
                cmds.pop_back();
                break;
            }
        }
    }

    return 0;
}
