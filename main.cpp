#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue {
    std::vector<int> enqueue_vector;
    std::vector<int> dequeue_vector;
    enum {
        enqueue = 0,
        dequeue
    } state = enqueue;
public:
    Queue() {};
    void enque(int v) {
        if (state == enqueue) {
            enqueue_vector.push_back(v);
        } else {
            while (!dequeue_vector.empty()) {
                enqueue_vector.push_back(dequeue_vector.back());
                dequeue_vector.pop_back();
            }
            state = enqueue;
            enqueue_vector.push_back(v);
        }
    }
    int deque() {
        if (state == dequeue) {
            int ret = dequeue_vector.back();
            dequeue_vector.pop_back();
            return ret;
        } else {
            while (!enqueue_vector.empty()) {
                dequeue_vector.push_back(enqueue_vector.back());
                enqueue_vector.pop_back();
            }
            int ret = dequeue_vector.back();
            dequeue_vector.pop_back();
            state = dequeue;
            return ret;
        }
        return 0;
    }
    int front() {
        if (state == enqueue)
            return enqueue_vector.front();
        else
            return dequeue_vector.back();
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string buf;
    std::getline(std::cin, buf);
    int num = std::stoi(buf);
    Queue q;
    while (num--) {
        std::getline(std::cin, buf);
        int cmd, v;
        std::sscanf(buf.c_str(), "%d %d", &cmd, &v);
        switch (cmd) {
            case 1: {
                q.enque(v);
                break;
            }
            case 2: {
                q.deque();
                break;
            }
            case 3: {
                printf("%d\n", q.front());
                break;
            }
        }
    }
    return 0;
}
