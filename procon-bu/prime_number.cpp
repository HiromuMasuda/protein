#include <iostream>
#include <math.h>
#include<string>
using namespace std;

bool isPrime(int num)
{
  if (num < 2) return false;
  if (num == 2) return true;
  if (num % 2 == 0) return false;

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) return false;
  }
  return true;
}

int main()
{
  int in;
  while (cin >> in) {
    int result = 0;
    for (size_t i = 0; i < in+1; i++) {
      if (isPrime(i)) result += 1;
    }
    cout<< result << endl;
  }
return 0;
}
