#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

bool cmp(int a, int b)
{
  if(a > b)
     return true;
     else
     return false;
}
long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  
  std::sort(a.begin(),a.end(),cmp);
  std::sort(b.begin(),b.end(),cmp);
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
