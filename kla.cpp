#include <iostream>
#include <algorithm>
#define N 200010
#define M 200010
using namespace std;

int hgt[N], kla[M], minhgt;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> hgt[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> kla[i];
  }
  cin >> minhgt;
  int happy = 0;
  sort(hgt, hgt + n);
  sort(kla, kla + m);
  for (int i = 0, j = m - 1; i < n; ++i) {
    if (hgt[i] + (j < 0 ? 0 : kla[j]) >= minhgt) {
      --j;
      ++happy;
    }
  }
  cout << happy << endl;
}
