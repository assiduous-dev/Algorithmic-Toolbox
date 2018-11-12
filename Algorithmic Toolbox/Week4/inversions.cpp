#include <iostream>
#include <vector>

using std::vector;
using namespace::std;

long long MergeAndCombine (vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  int mid = left + (right - left) / 2;
  int i = left;
  int j = mid + 1;
  int x = i;
  int count=0;
  while(i <= mid && j <= right )
  {
    if(a[i] <= a[j] )
    {
      b[x++] = a[i++];
    }
    else
    {
      //Refer to this for inversion logic https://www.youtube.com/watch?v=k9RQh21KrH8
      //Also there are multiple applications of counting inversion problem find that
      count += (mid+1 - i);
      b[x++] = a[j++];
      
    }
  }

  //Now copy any remainig values to the array b
  while(i <= mid)
  {
    b[x++] = a[i++];
  }

  while(j <= right)
  {
    b[x++] = a[j++];
  }

  for(int i=left;i<=right;i++)
  {
    a[i] = b[i];
   // cout<<a[i]<<" ";
  }
  //cout<<"\n";
 
  return count;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) {
    //Handle base  case if there are just two elements to be compared
    if(a[left] > a[right])
    {
      int temp = a[left];
      a[left] = a[right];
      a[right] = temp;
      number_of_inversions++;
    }
    return number_of_inversions;
    }
  size_t ave = left + (right - left) / 2;
  //cout<<"Left "<<left<<" Mid "<<ave<<" Right "<<right<<"\n";
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += MergeAndCombine(a,b,left,right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
