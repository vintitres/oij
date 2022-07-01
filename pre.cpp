
#include <iostream>
#include <algorithm>
#define N 200010
#define M 200010
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (n + 1) / 2 << endl;
  if (n % 2) cout << "1 " << n-- << endl;
  for (int i = 1; i <= n / 2; ++i) {
    cout << "2 " << i << " " << n - i << endl; 
  }
}
