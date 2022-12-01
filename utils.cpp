#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<string, string> ps;

#define pb push_back
#define its(it) it.begin(), it.end()
#define loop(x,n) for(int x = 0; x < n; ++x)

void IOBoilerPlate() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
}

int atoi(const string& str) {
  return atoi(str.c_str());
}

vs split(const string& line) {
  vs res;
  istringstream iss(line);
  for (string tok; iss >> tok;) {
    res.pb(tok);
  }
  return res;
}




