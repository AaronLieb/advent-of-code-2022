#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  vector<pair<int, int>> ranges;
  int count = 0;
  for (auto x : lines) {
    vs vals = {"", "", "", ""};
    int i = 0;
    string one = "";
    string two = "";
    for (auto c : x) {
      if (isdigit(c)) vals[i] += c;
      else {
        cout << vals[i] << endl;
        i++;
      }
    }
    pair<int, int> p1 = {atoi(vals[0]), atoi(vals[1])};
    pair<int, int> p2 = {atoi(vals[2]), atoi(vals[3])};
    if (p1.first <= p2.first && p1.second >= p2.second) {
      cout << "(" << p1.first << "," << p1.second << ")(" << p2.first << "," << p2.second << ")" << endl;
      count++;
    } else if (p2.first <= p1.first && p2.second >= p1.second) {
      count++;
    }
  }
  cout << count << endl;
}

int main() {
  IOBoilerPlate();
  ifstream file("input.txt");
  string line;
  vs lines, tokens, line_split;
  vvs both;
  while(!file.eof()) {
    getline(file, line);
    lines.pb(line);
    line_split = split(line);
    if (!line_split.size()) continue;
    both.pb(line_split);
    for (auto token : line_split) {
      tokens.pb(token);
    }
  }
  solve(lines, tokens, both);
}
