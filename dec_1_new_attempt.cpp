#include <bits/stdc++.h>

const int MAX_N = 100000;

int N;
long long tuition_array[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> tuition_array[i];
    }

    std::sort(tuition_array, tuition_array + N); // sort the tuition amounts in ascending order

    long long ans = 0;
    long long tuition = 0;
    for (long i = 0; i < N; i++) {
        if (tuition_array[i] * (N - i) > ans) { // if charging this tuition will give us more money
            ans = tuition_array[i] * (N - i); // update the maximum amount of money we can make
            tuition = tuition_array[i]; // update the optimal tuition
        }
    }

    std::cout << ans << " " << tuition << "\n";
    return 0;
}