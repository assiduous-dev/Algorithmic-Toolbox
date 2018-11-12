#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace::std;

bool cmp(int a, int b)
{
  return a < b;
}

int findNoOfOccurences(vector<int> &a, int left, int right, int num)
{
  int count = 0;
  for(int i=left;i<=right;i++)
  {
    if(a[i] == num)
    {
      count++;
    }
  }
  return count;
}
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
 // if ((left + 1 == right) && (a[left] == a[right]) ) return a[left];
  
  int mid = (left + right)/2;
  int get_majority_left = get_majority_element(a,left,mid);
  int get_majority_right = get_majority_element(a,mid+1,right);

  if(get_majority_left == get_majority_right)
  {
    return get_majority_left;
  }
 
  int get_majority_left_num_count = findNoOfOccurences(a, left, right, get_majority_left);
  int get_majority_right_num_count = findNoOfOccurences(a, left, right, get_majority_right);
  //cout<<"Majority left element count "<<get_majority_left_num_count<<"\n";
  //cout<<"Majority right element "<<get_majority_right_num_count<<"\n\n";

  int nu = -1;
  if(get_majority_left_num_count > (right-left+1)/2)
  {
    nu = get_majority_left;
  }
  else if(get_majority_right_num_count > (right-left+1)/2)
  {
    nu = get_majority_right;
  }
  else
  {
    nu = -1;
  }

  // cout<<"left "<<left<<"\n";
  // cout<<"mid "<<mid<<"\n";
  // cout<<"right "<<right<<"\n";
  //  cout<<"Majority left element "<<get_majority_left<<"\n";
  // cout<<"Majority right element "<<get_majority_right<<"\n";
  // cout<<"Result nu "<<nu<<"\n\n";
  return nu;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //sort(a.begin(), a.end(),cmp);
  // for(int i = 0; i<a.size();i++)
  // {
  //   cout<<a[i]<<" ";
  // }
  cout<<"\n";
 // cout<<"Size "<<a.size()/2<<"\n";
  int x = get_majority_element(a, 0, a.size()-1);
  // cout<<"x "<<x<<"\n";
  std::cout << (x != -1) << '\n';
}
