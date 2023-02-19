#include <bits/stdc++.h>
using namespace std;

struct InputOutputStruct {
    string input;
    int output;
};

int T, N, M;
vector<InputOutputStruct> test_cases;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        test_cases.clear();
        for (int i = 0; i < M; i++) {
            string input;
            int output;
            cin >> input >> output;
            test_cases.push_back({input, output}); // append to vector
        }

        bool is_lie = false;
        for (int i = 0; i < (1 << N); i++) { // try all possible combos
            bool valid = true;
            for (InputOutputStruct tc : test_cases) {
                int output = 0;
                for (int j = 0; j < N; j++) {
                    if ((i & (1 << j)) && tc.input[j] == '1') { 
                        output = 1;
                        break;
                    }
                }
                if (output != tc.output) { // if the output doesn't match what Elsie said
                    valid = false;
                    break;
                }
            }
            if (valid) { 
                is_lie = false;
                break;
            } else {
                is_lie = true;
            }
        }

        if (is_lie) {
            cout << "LIE" << "\n";
        } else {
            cout << "OK" << "\n";
        }
    }

    return 0;
}
