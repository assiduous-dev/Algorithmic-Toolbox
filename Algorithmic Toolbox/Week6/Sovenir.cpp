#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int rsize = w.size() +1 ;
  int csize = W+1;
  //Fails case 11 as using array will out of mermory but stack not see the forums
  //To the best of my knowledge. This probably has to do with the way memory is allocated. 
  //Array allocates a contiguous block of memory whereas vectors use dynamic memory allocation (internally).
  //In this case the grader probably runs out of continuous memory blocks large enough to store very large inputs.
  //int kpsack[rsize][csize];
  
  vector< vector<int> > kpsack(rsize, vector<int> (csize, 0)); 

  for(int i=0;i<rsize;i++)
  {
    for(int j=0;j<csize;j++)
    {
      kpsack[i][j]=0;
    }
     
  }
  
  for(int i=1;i<rsize;i++)
  { 
    for(int j=1;j<csize;j++)
    {
      if(w[i-1] > j)
      {
        kpsack[i][j] = kpsack[i-1][j];
      }
      else
      {
        int rem = j - w[i-1];
        kpsack[i][j] = std::max((w[i-1]+kpsack[i-1][rem]),kpsack[i-1][j]);
      }
      
    }
  }
//   std::cout<<"\n";
  
//   for(int i=0;i<rsize;i++)
//   {
//       std::cout<<"\n";
     
//     for(int j=0;j<csize;j++)
//     {
//         std::cout<<"   "<<kpsack[i][j];
//     }
    
//   }
  int count = 0;
  for(int i=0;i<rsize;i++)
  {
      if(kpsack[i][csize-1] == W)
      count++;
  }
  if(count >= 3)
  return 1;
  else
  return 0;
  //return kpsack[rsize-1][csize-1];
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
  std::cin >> w[i];
  }
  
  int sum = 0;
  sort(w.begin(),w.end());
  for(int i=0;i<w.size();i++)
  {
      sum += w[i];
  }
  
  if(sum%3 !=0)
  {std::cout << 0 << '\n';}
  else
  {
    std::cout << optimal_weight(sum/3, w) << '\n';  
  }
  
}

