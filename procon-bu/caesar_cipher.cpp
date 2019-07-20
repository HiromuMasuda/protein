#include <iostream>
#include <string>
using namespace std;

char seather(char c, int n) {
  if (c == ' ') return ' ';
  if (c == '.') return '.';

  int nn = c + n;
  if (nn > 122) return char(nn - 122 + 97 - 1);
  return char(nn);
}

string decrypt(string str) {
  for (int i = 0; i < 26; i++) {
    string can = "";
    for (int j = 0; j < str.length(); j++) {
      can += seather(str[j], i);
    }
    if(can.find("the") != string::npos || can.find("this") != string::npos || can.find("that") != string::npos) {
      return can;
    }
  }

  return "could not decrypt" + str;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string input;
  while(getline(cin, input)) {
    if (input == "") continue;
    cout << decrypt(input) << "\n";
  }

  return 0;
}
