#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  unsigned long long opts = 0;
  for (int i = 0, j = 0; i < s.size(); ++i) {
    if (i > j && s[i - 1] == s[i]) {
      j = i;
    } else if (i - 1 > j && s[i - 2] == s[i]){
      j = i - 1;
    }
    opts += i - j + 1;
  }
  cout << opts << endl;
}
