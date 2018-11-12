#include<iostream>
#include<vector>

using namespace::std;

//0 1 1 2 3 5 8

int64_t fibonacci(int64_t n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        int64_t first=0;
        int64_t second=1;
        int64_t ans;
        for(int i=2;i<=n;++i)
        {
            ans = first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
}

int main()
{   int inp;
    cin>>inp;
    int64_t ans = fibonacci(inp);
    cout<<ans;
    return 0;
}