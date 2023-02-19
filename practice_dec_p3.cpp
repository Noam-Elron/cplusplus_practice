#include <bits/stdc++.h>

int T; // number of Test cases

int N; // number of variables in current case

int M; // number of sequences in a test case

struct case_ting {
    std::string input;
    int output;
};

bool check(std::vector<case_ting> sequence_list) {
     
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            // If two sequences have the same input but different output, obviously a lie
            if (sequence_list[i].input == sequence_list[j].input && i != j && sequence_list[i].output != sequence_list[j].output) return false;
        }
    }
    return true;
}

int main() {

    std::cin >> T;
    for (int test_case = 0; test_case < T; test_case++) { // Loop to do stuff for each test case separately
        std::cin >> N >> M;

        std::vector<case_ting> sequences;
        case_ting sequence;
        for (int i = 0; i < M; i++) { 
            std::cin >> sequence.input >> sequence.output;
            sequences.push_back(sequence);
        }

        if(check(sequences)) {
            std::cout << "OK\n";
        }
        else {
            std::cout << "LIE\n";
        }
    }

    return 0;
}