#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  int sum{};
  for (vs thing : both) {
    string you = thing[0];
    string me = thing[1];

    if (you == "A" && me == "X") sum += 3;
    if (you == "A" && me == "Y") sum += 1 + 3;
    if (you == "A" && me == "Z") sum += 2 + 6;
    if (you == "B" && me == "X") sum += 1;
    if (you == "B" && me == "Y") sum += 2 + 3;
    if (you == "B" && me == "Z") sum += 3 + 6;
    if (you == "C" && me == "X") sum += 2;
    if (you == "C" && me == "Y") sum += 3 + 3;
    if (you == "C" && me == "Z") sum += 1 + 6;
  }
  cout << sum << endl;
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
  file.close();
  solve(lines, tokens, both);
}
