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
    int64_t secocnd_highest = 0;
    int64_t second_highest_index = 0;
    int64_t n = numbers.size();
    for(int i=0; i<n;++i)
    {
        if(i == 0)
        {
            first_highest = numbers[i];
            first_highest_index = 0;

        }
        else
        {
            if(numbers[i] > first_highest){
                first_highest = numbers[i];
                first_highest_index = i;
            }
            
        }
        
    }
    //cout << "Highest number" <<first_highest<<"\n";

    for(int i=0; i<n;++i)
    {
        if(i == first_highest_index)
        { continue; }

        if(i == 0)
        {
            secocnd_highest = numbers[i];
            second_highest_index = 0;

        }
        else
        {
            if(numbers[i] > secocnd_highest){
                secocnd_highest = numbers[i];
                second_highest_index = i;
            }
            
        }
        
    }
   // cout << "Second Highest number" <<secocnd_highest<<"\n";

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

// 3 10 8 9 7 2 4

// 1 f = 3, s =3
// 2 f = 10, s = 3
// 3 f = 10 , s = 8
// 4 f = 10, s = 9