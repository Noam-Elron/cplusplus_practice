// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

int N;
std::string cows;


int main() {
    std::ios_base::sync_with_stdio(false);
    
    std::cin >> N;
    std::cin >> cows;
    
    bool found_hg_gh = false;
    bool last_is_hg = false;
    int reverses = 0;
    
    for (int i = 0; i < N; i +=2 ) {
        if (cows[i] == cows[i+1]) {
            continue;
        }
        bool same_as_last = cows[i] == 'H';
        if (!found_hg_gh) {
            found_hg_gh = true;
        }
        else {
        if ( same_as_last != last_is_hg) reverses++;
        }
        last_is_hg = same_as_last;
    }
    int ans = reverses;
    if (last_is_hg == false) {
        reverses++;
    }
    std::cout << reverses << '\n';
    return 0;
}
    
