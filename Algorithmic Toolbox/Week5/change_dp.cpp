#include <iostream>
#include <vector>
using namespace::std;

int get_change(int m) {
  //write your code here
  int coins[]{1,3,4};
  vector<int> dp_change(m+1);
  int min_change = 0;
  int change = 0;
  for(int mny=0;mny<=m;mny++)
  {
    min_change = 0;
    for(int i=0;i<3;i++)
    { change = 0;
      int mny_left = mny - coins[i];
      if(mny_left < 0)
      {
        continue;
      }
      if(mny_left == 0 && change <= min_change)
      {
        min_change = 1;
      }
      if(mny_left > 0)
      {
        change = dp_change[mny_left] + 1; 
        if(min_change == 0 || change < min_change)
        {
          min_change =  change;
        }
      }
    }
    dp_change[mny] = min_change; 
  }
  
  // for(int i=0;i<dp_change.size();i++)   
  // {cout << dp_change[i] << " ";}
  // cout<<"\n"; 
  return dp_change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
