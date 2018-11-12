#include<iostream>
#include<vector>

using namespace::std;

int CalculateGcd(int a, int b)
{
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    if(a > b )
    { return CalculateGcd(b, a%b);}
    else
    {
        return CalculateGcd(a, b%a);
    }

}

int main()
{
    int a, b, gcd;
    cin>>a;
    cin>>b;
    gcd = CalculateGcd(a,b);
    cout<<gcd;
    return 0;
}