#include<iostream>
#include<vector>

using namespace::std;

//0 1 1 2 3 5 8

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if( n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }

}

int main()
{   int inp;
    cin>>inp;
    int ans = fibonacci(inp);
    cout<<ans;
    return 0;
}