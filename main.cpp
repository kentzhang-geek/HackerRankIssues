#include <iostream>
#include <vector>
#include <string>
#include <map>

static inline int intMax(int a, int b) {
    return a>b?a:b;
}

static inline void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
void minimumBribes(std::vector<int> q) {
    int sumBribes = 0;
    for (int i = q.size(); i>=1;) {
        if ((q[i - 1] - i) > 2) {
            printf("Too chaotic\n");
            return;
        }
        int bribes = intMax(q[i - 1] - i, 0);
        sumBribes += bribes;
        if (bribes == 1) {
            swap(q[i - 1], q[i]);
        } else if (bribes == 2) {
            swap(q[i - 1], q[i]);
            swap(q[i], q[i + 1]);
        } else {
            i--;
        }
    }
    printf("%d\n", sumBribes);
}

int main() {
//    minimumBribes({5,1,2,3,7,8,6,4});
    minimumBribes({1,2,5,3,7,8,6,4});

    return 0;
}
