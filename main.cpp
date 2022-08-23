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
#define MOD 1000000007
std::vector<long long int> patternAcc;

long long int sum(std::vector<long long int> & arr, long long int s, long long int n) {
    long long int ret = 0;
    for (long long int i = 0; i < n;i++) {
        ret += arr[s + i];
    }
    return ret;
}

long long int tetranacci(long long int n) {
    std::vector<long long int> arr = {1,2,4,8};
    if (n <= 4) {
        long long int sum = 1;
        for (long long int i = 0; i < n; i++) {
            sum *= arr[i];
        }
        return sum;
    }

    for (long long int i = 4; i <= n; i++) {
        arr.push_back(sum(arr, i - 4, 4));
    }
    long long int ret = 0;
    return arr.back();
}

long long int patternsOf(long long int m) {
    if (patternAcc.size() > m) {
        return patternAcc[m];
    }
    long long int ret = 0;
    if (m > 0)
    {
        ret = patternsOf(m - 1) + patternsOf(m - 2) + patternsOf(m - 3) + patternsOf(m - 4);
        patternAcc.push_back(ret);
    }
    else if (m == 0) {
        ret = 1;
        patternAcc.push_back(1);
    }
    else
        ret = 0;
    return ret;
}

std::map<std::pair<long long int,long long int>, long long int> allblockMap;

long long int allBlocks(long long int n, long long int m) {
    if (allblockMap.find({n,m})!=allblockMap.end()) {
        return allblockMap.at({n,m});
    }
    long long int ret = 1;
    long long int p = patternsOf(m);
    for (long long int i = 0; i < n; i++) {
        ret *= p;
    }
    allblockMap[{n,m}] = ret;
    return ret;
}

std::map<std::pair<long long int,long long int>, long long int> blockMap;
long long int legoBlocks(long long int n, long long int m) {
    if (blockMap.find({n,m})!=blockMap.end()) {
        return blockMap.at({n,m});
    }
    long long int result = 0;
    result = allBlocks(n, m);
    for (long long int i = 1; i <= m - 1; i++) {
        result -= legoBlocks(n, i) * allBlocks(n, m - i);
    }
    blockMap[{n,m}] = result;
    return result;
}

int main() {
    printf("%d\n", legoBlocks(8,6) % MOD);
    printf("%d\n", legoBlocks(10,8));
    printf("%d\n", legoBlocks(7,3));
    printf("%d\n", legoBlocks(529, 190));
    printf("%d\n", legoBlocks(4,4));
    printf("%d\n", legoBlocks(4,5));
    printf("%d\n", legoBlocks(4,6));
    return 0;
}