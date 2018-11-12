#include<iostream>
#include<vector>

using namespace::std;


vector<int> findFibLastDigitPisanoPeriod(int m)
{
    int prev=1, prev_prev=0, fibLastDig=0;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    bool found_zero;
    int interval = 0;
    // for(int i=0;i<60;i++)
    // {
    //     a.push_back(i);
    // }
    for(int i=2;;++i)
    {
        fibLastDig = prev + prev_prev;
        if(fibLastDig >= m)
        {
            fibLastDig = fibLastDig %  m;
        }
        cout<<fibLastDig<<"\n";
        a.push_back(fibLastDig);
        prev_prev = prev;
        prev = fibLastDig;
       
        
        interval++;
        
        if(fibLastDig == 0)
        {
            found_zero = true;
            continue;
        }

        if(found_zero == true && fibLastDig == 1)
        {
            break;
        }
        else
        {
            found_zero = false;
        }

    }
    cout<<"Size "<<a.size();
    return a;

}

int main()
{   
    int num = 0;
    //cin>>num;
     
    vector<int> re = findFibLastDigitPisanoPeriod(10);
   
//    for(int i =0;i < re.size();i++)
//    {
//        cout<<re[i]<<"\n";
//    }
//     int interval = re.size() - 2;
    
//     int digit = re[num % interval];
//     cout<<digit<<"\n";
//     int digit2  = re[(num - 1) % interval];
//     cout<<digit2<<"\n";
//     int result = digit * (digit + digit2);
//     cout<<result;
cin>>num;
    return 0;
}