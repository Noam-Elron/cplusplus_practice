#include <bits/stdc++.h>

using namespace std;
int T; // Num of test cases
// A struct to represent an input and output pair
struct InputOutputStruct {
  string input;
  char output;
};

// A function to check if a program is consistent with a given list of input and output pairs
bool check(int n, int m, InputOutputStruct pairs[]) {
  for (int i = 0; i < m; i++) {
    // Check the value of each variable
    bool output = false;
    for (int j = 0; j < n; j++) {
      if (pairs[i].input[j] == '1') {
        output = true;
        break;
      }
    }

    if (output != (pairs[i].output == '1')) {
      return false;
    }
  }

  // If the program returned the correct output for all of the input and output pairs, then Elsie is not lying
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M;
    cin >> N >> M;

    InputOutputStruct pairs[m];
    for (int i = 0; i < m; i++) {
      cin >> pairs[i].input >> pairs[i].output;
    }

    if (check(n, m, pairs)) {
      cout << "OK" << "\n";
    } else {
      cout << "LYING" << "\n";
    }
  }

  return 0;
}
