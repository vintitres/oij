#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<climits>
bool cmp(long long i1, long long i2) {
  return i1 > i2;
}

using namespace std;

map<pair<long long, short>, pair<short,short>> bestM;
vector<long long> klocki,maxx;
  /*short findkunder(long long x, short b, short e) {
  int m = (b + e) / 2;
  if (x 
}
pair<short,short> findk*/
short best(long long x, short k){
  //  cout << x << " " << k << endl;
  if (x == 1) return 0;
  if (k == -1 || x > maxx[k]) return 200;
  if (klocki[k] == x) {
    //bestM[make_pair(x, k)] = 1;
    return 1;
  }
  /*{
    if (klocki[k] > x) {
      
    return best(x, findkunder(x/2, k));
  }*/
  auto it = bestM.find(make_pair(x,k));
  if (it != bestM.end()) return it->second.first;
  short b = best(x, k - 1);
  if (x % klocki[k] == 0LL) {
    short bb =  best(x / klocki[k], k -1) + 1;
    b = bb < b ? bb : b;
  }
  bestM[make_pair(x,k)] = make_pair(b, 0);
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
  long long mx = 1;
  for (int i =0 ; i < k; ++i){
    if (mx <= x) {
      long long mxx = mx * klocki[i];
      unsigned long long mxxx = (unsigned long long)mx * (unsigned long long)klocki[i];
      if (mxx / mx != klocki[i] || mxxx / (unsigned long long)mx  != (unsigned long long)klocki[i]) {
        mx = x + 1;
      } else {
        mx = mxx;
      }
    }
    maxx.push_back(mx);
  }
  short b = best(x, k - 1);
  if (b > k){
    cout << "NIE" << endl;
    return 0;
  }
  cout<< b <<endl;
  /*return 0;
  --k;
  while (x> 1){
    b = bestM[make_pair(x,k)];
    while (true) {
      long long kl = klocki[k--];
      if (x%kl==0) {
        auto it = bestM.find(make_pair(x/kl,k));
        if (it != bestM.end() && it->second + 1 == b) {
        cout << kl << " ";
        x/=kl;
        break;
        }
      }
    }
    if (b == 2) {
      cout << x << endl;
      break;
    }
  }
  */

}
