#include <iostream>
#include <vector>

using namespace std;

int oczko(string cards, int pos = 0, int score = 0) {
  if (score > 21) return -1;
  if (cards.size() == pos) return score;
  char c = cards[pos];
  if (c >= '1' && c <= '9') return oczko(cards, pos + 1, score + c - '0');
  if (c == 'T' || c == 'J' || c == 'Q' || c == 'K') return oczko(cards, pos + 1, score + 10);
  if (c == 'A') return max(oczko(cards, pos + 1, score + 1), oczko(cards, pos + 1, score + 11));
}

int main() {
  int n;
  cin >> n;
  vector<int> winners;
  int max_score = 1;
  for (int i = 0; i < n; ++i) {
    string cards;
    cin >> cards;
    int score = oczko(cards);
    if (score >= max_score) {
      if (score > max_score) {
        winners.clear();
        max_score = score;
      }
      winners.push_back(i + 1);
    }
  }
  cout << winners.size() << endl;
  for (int w : winners) {
    cout << w << " ";
  }
}
