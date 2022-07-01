#include <iostream>
#include <vector>

#define N 200010

using namespace std;

int pos[N], hgt[N];
unsigned long long best[N];

int main() {
  ios_base::sync_with_stdio(0);
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; ++i) {
    cin >> pos[i];
  }
  unsigned long long hgtsum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> hgt[i];
    hgtsum += hgt[i];
  }
  best[0] = hgt[0];
  for (int i = 1, j = 0; i < n; ++i) {
    while (pos[i] - d >= pos[j]) ++j; 
    best[i] = max(best[i - 1], (j == 0 ? 0ULL : best[j - 1]) + (unsigned long long)hgt[i]);
  }
  cout << hgtsum - best[n - 1] << endl;
  vector<int> chopped;
  for (int i = n - 1; i >= 0;) {
    if (i >= 0 && best[i] == best[i - 1]) {
      chopped.push_back(i);
      --i;
      continue;
    }
    int choppos = pos[i] - d;
    --i;
    while (i >= 0 && choppos < pos[i]) {
      chopped.push_back(i);
      --i;
    }
  }
  cout << chopped.size() << endl;
  for (int c : chopped) {
    cout << c + 1 << " ";
  }
}
