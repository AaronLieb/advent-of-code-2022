#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  auto input = both;
  for (auto x : both) {
    
  }
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
