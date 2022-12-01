#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  int max = 0, sum = 0, val;
  vi vals;
  for (auto line : lines) {
    val = atoi(line);
    if (line == "") {
      vals.pb(sum);
      sum = 0; 
    } else {
      sum += val;
    }
  }
  vals.pb(sum);
  sort(its(vals), greater<int>());
  int sum3 = 0;
  for (int i = 0; i < 3; i++) sum3 += vals[i];
  cout << sum3 << endl;
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
