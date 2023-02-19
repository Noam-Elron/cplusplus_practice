#include <bits/stdc++.h>


int T; // number of Test cases

int N; // number of variables in current case

int K; // number of max steps


int main() {
    std::cin >> T;
    std::string cows;

    for (int test_case = 0; test_case < T; test_case++) { // Loop to do stuff for each test case separately
        std::cin >> N;
        std::cin >> K;
        std::cin >> cows;
        int num_patches = 0;
        std::string patches(N, '.');
        
        for (int i = N-1; i >= 0; i--) {
            char current_cow;
            current_cow = cows[i];

            //std::cout << "\nCurrent cow position: " << i << "\n";
            std::string patches_in_range = patches.substr (i+1, K);

            //std::cout << "Substring: " << patches_in_range << "\n";


            int position_of_patch_in_range = patches_in_range.find_last_of(current_cow);

            if (position_of_patch_in_range < 0) { // no patch in range
                //std::cout << "No patches in range\n";
                patches[i] = current_cow;
                num_patches++;
            }
            
        }
        std::cout << num_patches << "\n" << patches << "\n";
       
    }


    return 0;
}