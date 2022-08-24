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
#include <queue>
#include <map>
using namespace std;



/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */
int formula(int _1st, int _2nd) {
    return _1st + 2 * _2nd;
}

int cookies(int k, vector<int> A) {
    if (A.size() == 1)
        return A[0] >= k ? 0 : -1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue;
    for (auto v : A) {
        pqueue.push(v);
    }
    int loop_count = 0;
    bool ans = true;
    while (1) {
        if (pqueue.empty()) {
            ans = false;
            break;
        }
        int v1 = pqueue.top();
        pqueue.pop();
        if (v1 >= k) {
            break;
        }
        if (pqueue.empty()) {
            ans = false;
            break;
        }
        int v2 = pqueue.top();
        pqueue.pop();
//        if (v2 >= k) {
//            break;
//        }
        int res = formula(v1, v2);
        pqueue.push(res);
        loop_count++;
    }
    if (ans)
        return loop_count;
    return -1;
}

int main() {
    printf("%d\n", cookies(7,{1,2,3,9,10,12}));
    printf("%d\n", cookies(90,{13,47,74,12,89,74,18,38}));
    printf("%d\n", cookies(10,{1,1,1}));
    return 0;
}