#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

char findCommon(string first, string second, string third) {
    for (auto f : first) {
      for (auto s: second) {
        for (auto t: third) {
          if (f == s && s == t) {
            return f;
          }
        }
      }
    }
    return '$';
}

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  auto input = both;
  int sum = 0;
  for (int i = 0; i < lines.size(); i += 3) {
    string first = lines[i];
    string second = lines[i + 1];
    string third = lines[i + 2];
    char common = findCommon(first, second, third);
    int val = 0;
    if (isupper(common)) val = (common - 'A') + 27;
    else if (islower(common)) val = (common - 'a') + 1;
    else val = 0;
    cout << common << ": " << val << endl;
    sum += val;
  }
  cout << "sum: " << sum << endl;
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
