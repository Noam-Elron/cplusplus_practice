// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

long long N;
const int MAX_N = 10000;
const long MAX_PRICE = 100000;


long long counts = 0;
// Keep track of highest tuition as to avoid unnecessary looping over price_index array
long long highest_tuition = 0; 


/* 
    Each Index in the price_index array represents how many cows
    are willing to pay index or less. So at price_index[i], i would
    be the price cows would be willing to play and price[index] would 
    be how many cows are willing to pay i or less
*/
long long price_index[MAX_PRICE] = {}; 

long long max_profit = 0;
long long optimal_tuition = 0;

int main() {
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> N;

    // Read N cows tuitions
    long long tuition = 0;
        for (long i = 0; i < N; i++) {
        std::cin >> tuition;
        // Increase the count of how many cows are willing to pay c tuition. c tuition is price_index[c] 
        price_index[tuition] += 1;
        if (tuition > highest_tuition) highest_tuition = tuition;
    }
    /*
    std::cout << "Highest Tuition: " << highest_tuition << "\n";
    for (long i = 0; i < highest_tuition+1; i++) {
        std::cout << price_index[i] << " ";
    }
    */
    for (long long i = highest_tuition; i >= 0; i--) {
        if (i < highest_tuition) {
            counts = price_index[i+1];
            price_index[i] += counts;
        }

    }

    /*
    std::cout << "\n";
    for (long i = 0; i < highest_tuition+1; i++) {
        std::cout << price_index[i] << " ";
    }
    */
    
    for (long i = 0; i < highest_tuition; i++) {
        long long cur = price_index[i] * i; // Profit per index;
        if (cur > max_profit) {
            max_profit = cur;
            optimal_tuition = i;
        }
    }
    
    std::cout << max_profit << " " << optimal_tuition << "\n";

    return 0;
}
    
