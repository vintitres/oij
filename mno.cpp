#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;

map<pair<long long, short>, short> bestM;
vector<long long> klocki;
short best(long long x, short k){
  //  cout << x << " " << k << endl;
  if (x == 1) return 0;
  if (k == -1) return 200;
  auto it = bestM.find(make_pair(x,k));
  if (it != bestM.end()) return it->second;
  short b = best(x, k - 1);
  if (x % klocki[k] == 0LL) {
    short bb =  best(x / klocki[k], k -1) + 1;
    b = bb < b ? bb : b;
  }
  bestM[make_pair(x,k)] = b;
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
  short b = best(x, k - 1);
  if (b > k){
    cout << "NIE" << endl;
    return 0;
  }
  cout<< b <<endl;
  --k;
  while (x> 1){
    b = bestM[make_pair(x,k)];
    while (true) {
      long long kl = klocki[k--];
      if (x%kl==0 && bestM[make_pair(x/kl,k)] + 1 == b) {
        cout << kl << " ";
        x/=kl;
        break;
      }
    }
  }

}
