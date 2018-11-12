#include<iostream>
#include<vector>

using namespace::std;

int64_t CalculateGcd(int64_t a, int64_t b)
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

int64_t LCM(int64_t a, int64_t b)
{
    if(a == 0 || b == 0){
        return 0;
    }
    if(a == 0 || b == 0) {
        return -1;
    }
    int64_t gcd = CalculateGcd(a,b);
    return (a*b)/gcd;
}

int main()
{
    int64_t a, b, lcm;
    cin>>a;
    cin>>b;
    lcm = LCM(a,b);
    cout<<lcm;
    return 0;
}