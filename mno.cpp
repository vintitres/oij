#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<climits>
using namespace std;

bool cmp(long long i1, long long i2) {
  return i1 > i2;
}

map<pair<long long, short>, short> bestM;
vector<long long> klocki;

short _best(long long x, short k);

short best(long long x, short k) {
  auto it = bestM.find(make_pair(x,k));
  if (it != bestM.end()) return it->second;
  short b = _best(x,k);
  bestM[make_pair(x,k)] = b;
  return b;
}

short _best(long long x, short k){
  if (x == 1) return 0;
  if (k == -1) return 200;
  int kk = k - 1;
  for (kk = k - 1; kk >= 0 && klocki[kk] > x / 2; --kk) if(klocki[kk] == x) return 1;
  short b = best(x, kk);
  if (x % klocki[k] == 0LL) {
    short bb =  best(x / klocki[k], kk) + 1;
    b = bb < b ? bb : b;
  }
  return b;
}

int main() {
  short k;
  long long x;
  cin>>k>>x;
  for (int i =0 ; i < k; ++i){
    long long int kl;
    cin >>kl;
    klocki.push_back(kl);
  }
  sort(klocki.begin(),klocki.end(), cmp);
  short b = best(x, k - 1);
  if (b > k){
    cout << "NIE" << endl;
    return 0;
  }
  cout<< b <<endl;
  for (--k; b > 1;) {
    long long kl = klocki[k--];
    if (kl > x/2) continue;
    if (x%kl==0 && bestM[make_pair(x/kl,k)] + 1 == b) {
      cout << kl << " ";
      x/=kl;
      --b;
    }
  }
  cout << x << endl;
  return 0;
}
