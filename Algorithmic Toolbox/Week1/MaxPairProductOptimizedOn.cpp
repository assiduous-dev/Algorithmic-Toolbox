#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int64_t MaxPairwiseProduct(const vector<int>& numbers)
{
    int64_t product = 0;
    int64_t first_highest = 0;
    int64_t first_highest_index = 0;
    int64_t secocnd_highest = 1;
    int64_t second_highest_index = 0;
    int64_t n = numbers.size();
    if(n == 2)
    {
        first_highest =  numbers[0]; 
        secocnd_highest = numbers[1];
        return first_highest * secocnd_highest;
    }

    for(int i=0; i<n;++i)
    {
        if( i == 0)
        {
            first_highest = numbers[i];
            secocnd_highest = numbers[i];
        }
        else
        {
           if(first_highest == numbers[i])
            {
                secocnd_highest = numbers[i];
            }
            else if(numbers[i] > first_highest)
            {
                secocnd_highest = first_highest;
                first_highest = numbers[i];
                
            }
            else if(numbers[i] > secocnd_highest && numbers[i] < first_highest)
            {
                secocnd_highest = numbers[i];
            }
        }
    }
    
    return first_highest * secocnd_highest;
}

int main() {
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }
    
    int64_t product = MaxPairwiseProduct(numbers);
    cout<<product<<"\n";
    return 0;
}