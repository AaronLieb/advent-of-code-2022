#include <bits/stdc++.h>
#include "../utils.cpp"

using namespace std;

void solve(const vs& lines, const vs& tokens, const vvs& both) {
  int sum = 0;
  for (auto thing : both) {
    string you = thing[0];
    string me = thing[1];

    if (me == "X") sum += 1;
    if (me == "Y") sum += 2;
    if (me == "Z") sum += 3;

    if (you == "A" && me == "X") sum += 3;
    if (you == "A" && me == "Y") sum += 6;
    if (you == "A" && me == "Z") sum += 0;
    if (you == "B" && me == "X") sum += 0;
    if (you == "B" && me == "Y") sum += 3;
    if (you == "B" && me == "Z") sum += 6;
    if (you == "C" && me == "X") sum += 6;
    if (you == "C" && me == "Y") sum += 0;
    if (you == "C" && me == "Z") sum += 3;
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
    both.pb(line_split);
    if (!line_split.size()) continue;
    for (auto token : line_split) {
      tokens.pb(token);
    }
  }
  file.close();
  solve(lines, tokens, both);
}
