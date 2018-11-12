#include<iostream>
#include<vector>

using namespace::std;

//0 1 1 2 3 5 8

int fibonacci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    else
    {
        int first=0;
        int second=1;
        int ans;
        for(int i=2;i<=n;++i)
        {
            ans = (first + second)%10;
            first = second%10;
            second = ans;
        }
        return ans;
    }
}

int main()
{   int inp;
    cin>>inp;
    int ans = fibonacci(inp);
    cout<<ans;
    return 0;
}