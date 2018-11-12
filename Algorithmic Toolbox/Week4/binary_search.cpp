#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using namespace::std;

int binary_search_inner(const vector<int> &a, int left, int right, int num)
{ 
  if(num < a[left] || num > a[right] )
  {
    return -1;
  }

  int mid = (left + right) / 2;
  
  if(num == a[mid]){
    return mid;
  }
  else if(num > a[mid]){
    return binary_search_inner(a, mid + 1,right,num);
  }
  else if(num < a[mid]){
    return binary_search_inner(a,left,mid - 1,num);
  }
  else{
    return -1;
  }
}


int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //cout<<"right "<<right;
  return binary_search_inner(a,left,right-1,x);
  
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, b[i]) << ' ';
  }

  return 0;
}
