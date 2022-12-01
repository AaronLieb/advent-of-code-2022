#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  int max = 0, sum = 0, val;
  for (auto line : lines) {
    val = atoi(line);
    if (line == "") {
      if (sum > max) max = sum;
      sum = 0; 
    } else {
      sum += val;
    }
  }
  if (sum > max) max = sum;
  cout << max << endl;
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
    both.pb(line_split);
    for (auto token : line_split) {
      tokens.pb(token);
    }
  }
  solve(lines, tokens, both);
}
