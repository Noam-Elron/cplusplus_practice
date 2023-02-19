#include <bits/stdc++.h>

using namespace std;
int T; // Num of test cases

// Struct to contain each pair of variables+output
struct InputOutputStruct {
  string input;
  char output;
};


bool check(int N, int M, InputOutputStruct pairs[]) {
  for (int i = 0; i < M; i++) {
    // Check the value of each variable
    bool output = false;
    for (int j = 0; j < N; j++) {
      if (pairs[i].input[j] == '1') {
        output = true;
        break;
      }
    }

    if (output != (pairs[i].output == '1')) {
      return false;
    }
  }


  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M;
    cin >> N >> M;

    InputOutputStruct pairs[M];
    for (int i = 0; i < M; i++) {
      cin >> pairs[i].input >> pairs[i].output;
    }

    if (check(N, M, pairs)) {
      cout << "OK" << "\n";
    } else {
      cout << "LIE" << "\n";
    }
  }

  return 0;
}
