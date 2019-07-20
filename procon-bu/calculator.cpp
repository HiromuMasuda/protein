#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string s;

int conv_stoi(string str){
  stringstream ss(str);
  int n;
  ss >> n;
  return n;
}

int parse(int l, int r){
  int n = 0;
  for(int i=r-1;i>=l;i--){
    if(s[i] == ')') n++;
    if(s[i] == '(') n--;
    if(!n){
      if(s[i] == '+') return parse(l,i) + parse(i+1,r);
      if(s[i] == '-') return parse(l,i) - parse(i+1,r);
    }
  }
  for(int i=r-1;i>=l;i--){
    if(s[i] == ')') n++;
    if(s[i] == '(') n--;
    if(!n){
      if(s[i] == '*') return parse(l,i) * parse(i+1,r);
      if(s[i] == '/') return parse(l,i) / parse(i+1,r);
    }
  }

  if(s[l] == '(' && s[r-1] == ')') return parse(l+1,r-1);
  return conv_stoi(s.substr(l,r-l));
}

int main(){
  int n;
  cin >> n;
  while(n--){
    cin >> s;
    cout << parse(0,(int)s.size()-1) << endl;
  }
}
