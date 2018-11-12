#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace::std;

vector<int> optimal_sequence(int n, vector<int> dp) {
  std::vector<int> sequence;
  int min_steps,min_steps1,min_steps2,min_steps3;
  int num;
  
  while (n >= 1) {
    min_steps=0,min_steps1=0,min_steps2=0,min_steps3=0;
    sequence.push_back(n);
    //cout<<"number "<<n<<"\n";
    if (n % 3 == 0) {
      min_steps3 = dp[n/3] + 1;
      //cout<<"min steps 3 "<<min_steps3<<"\n";
    }
    else
    {
      min_steps3 = dp[n/3] + n%3 + 1;
    }
    if (n % 2 == 0) {
      min_steps2 = dp[n/2] + 1;
      //cout<<"min steps 2 "<<min_steps2<<"\n";
    }else
    {
      min_steps2 = dp[n/2] + n%2 + 1;
    } 
    min_steps1 = dp[n-1] + 1;
    //cout<<"min steps 1 "<<min_steps1<<"\n";
    
    
    if(min_steps2 <= min_steps1 && min_steps2 <= min_steps3 && n%2 == 0)
    {
      n = n/2;
      //cout<<"here 2 "<<n<<"\n";
    }
    else if(min_steps3 <= min_steps2 && min_steps3 <= min_steps1 && n%3 == 0)
    {
      n = n/3;
      //cout<<"here 3 "<<n<<"\n";
    }else
    {
      n = n -1;
    }
    

  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_no_of_steps(int n)
{
  int size = n+1;
  vector<int> dp_save_steps(size);
  
  dp_save_steps[0] = 0;
  dp_save_steps[1] = 1;
  dp_save_steps[2] = 1;
  dp_save_steps[3] = 1;
   
   int minstepscount = 0;
  for(int i=4;i<size ;i++)
  {
    minstepscount = 0;
    int minstepscount1,minstepscount2,minstepscount3,nu;
    
    if(i%2 == 0)
    {
      minstepscount2 = dp_save_steps[i/2] + 1;
     // cout<<"min step 2 "<<minstepscount2<<"\n";
    }else
    {
      minstepscount2 = dp_save_steps[i/2] + (i%2) + 1;
      //cout<<"i/2 "<< dp_save_steps[i/2] << "i2 "<<(i%2)<<"\n";
      //cout<<"min step 2 "<<minstepscount2<<"\n";
    }
    if(i%3 == 0)
    {
      minstepscount3 = dp_save_steps[i/3] + 1;
      //cout<<"min step 3 "<<minstepscount3<<"\n";
    }else
    {
      minstepscount3 = dp_save_steps[i/3] + (i%3) + 1; 
      //cout<<"min step 3 "<<minstepscount3<<"\n";
    }

    nu = i - 1;
    minstepscount1 = dp_save_steps[nu] + 1;
    //cout<<"min step 1 "<<minstepscount1<<"\n";
    if(minstepscount1 <= minstepscount2 && minstepscount1 <= minstepscount3)
    {
      minstepscount = minstepscount1;
    }

    if(minstepscount2 <= minstepscount1 && minstepscount2 <= minstepscount3)
    {
      minstepscount = minstepscount2;
    }
    if(minstepscount3 <= minstepscount2 && minstepscount3 <= minstepscount1)
    {
      minstepscount = minstepscount3;
    }

    dp_save_steps[i] = minstepscount;
  }

  // cout<<dp_save_steps.size()<<"\n";
  // for(int i = 0;i<dp_save_steps.size();i++)
  // {
  //   cout<<dp_save_steps[i]<<" ";
  // }
  // cout<<"\n";

  return dp_save_steps;
}

int main() {
  int n;
  std::cin >> n;
  
  vector<int> seq = optimal_no_of_steps(n);
  //int num = n;
  //cout<<seq[n]<<"\n";
  
  vector<int> sequence = optimal_sequence(n,seq);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
