#include <iostream>
#include <vector>

#define N 100

using namespace std;

class Puzzle {
private:
  vector<vector<bool>> puzzle;
  int imin, imax, jmin, jmax;
  pair<int,int> _firstdot;
  Puzzle() { _firstdot = make_pair(-1,-1);}
public:
  static Puzzle read() {
    Puzzle puz;
    int n,m;
    cin >> n >> m;
    int imin = N, imax = 0, jmin = N, jmax = 0;
    for (int i = 0; i < n; ++i){
      vector<bool> puzrow;
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        puzrow.push_back(c == 'X');
        if (c == 'X') {
          imin = min(imin, i);
          imax = max(imax, i);
          jmin = min(jmin, j);
          jmax = max(jmax, j);
        }
      }
      puz.puzzle.push_back(puzrow);
    }
    puz.imin = imin;
    puz.imax = imax;
    puz.jmin = jmin;
    puz.jmax = jmax;
    return puz;
  }
  int length() {
    return imax - imin;
  }
  int width() {
    return jmax - jmin;
  }
  bool full() {
    for (int i = imin; i <= imax; ++i) {
      for (int j = jmin; j <= jmax; ++j) {
        if (!puzzle[i][j]) return false;
      }
    }
    return true;
  }
  bool get(int i, int j) {
    //if (!rot && i >= imin && i <= imax && j >= jmin && j <= jmax) return puzzle[i][j];
    //if (rot && j >= imin && j <= imax && i >= jmin && i <= jmax) return puzzle[j][i];
    return false;
  }
  int fulltop() {
    for (int i = imin; i <= imax; ++i) {
      for (int j = jmin; j <= jmax; ++j) {
        if (!puzzle[i][j]) return i - imin;
      }
    }
  }
  pair<int,int> firstdot() {
    if (_firstdot.first != -1) return _firstdot;
    for (int i = imin; i <= imax; ++i) {
      for (int j = jmin; j <= jmax; ++j) {
        if (!puzzle[i][j]) {
          _firstdot.first = i;
          _firstdot.second = j;
          return _firstdot;
        }
      }
    }
  }
  bool trymatch(const Puzzle& puz2, int puz2topskip) {
    return false;

  }

};

bool match() {
    Puzzle puz1 = Puzzle::read();
    Puzzle puz2 = Puzzle::read();
    if (puz1.full()) {
      return (puz1.width() == puz2.length() || puz1.width() == puz2.width() || puz1.length() == puz2.length() || puz1.length() == puz2.width()) && puz2.full();
    }
    // TODO for each rot
    int puz2fulltop = puz2.fulltop();
    if (puz2fulltop > 0) {
      if (puz1.trymatch(puz2, puz2fulltop)) return true;
    }
    if (puz1.trymatch(puz2, 0)) return true;
    return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    if (match()) cout << "TAK" << endl;
    else cout << "NIE" << endl;
  }
}
