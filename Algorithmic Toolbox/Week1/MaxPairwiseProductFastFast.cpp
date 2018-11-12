#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int64_t MaxPairwiseProductCorrect(const vector<int>& numbers)
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


int64_t MaxPairwiseProduct(const vector<int>& numbers)
{
    int64_t product = 0;
    int64_t first_highest = 0;
    int64_t first_highest_index = 0;
    int64_t secocnd_highest = 1;
    int64_t second_highest_index = 0;
    int64_t n = numbers.size();
//     3 10 8 9 11 7 12

// 1 f = 3, s =3
// 2 f = 10, s = 3
// 3 f = 10 , s = 8
// 4 f = 10, s = 9
// 5 f=11,
    
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
    // int n;
    // cin>>n;
    // vector<int> numbers(n);
    // for(int i=0;i<n;i++)
    // {
    //     cin>>numbers[i];
    // }

    while(true)
    {
        int size = rand() % 500 + 2;
        cout<<"size "<<size<<"\n";
        vector<int> a;
        for(int i=0; i<size;++i)
        {
            a.push_back(rand() % 100000);
        }
        for(int i=0;i<size;++i)
        {
            cout<<a[i]<<' ';
        }
        cout << "\n";

        long long res1 = MaxPairwiseProductCorrect(a);
        long long res2 = MaxPairwiseProduct(a);

        if(res1 != res2)
        {
            cout<<"wrong answer: " <<res1<<' '<<res2<<"\n";
            break;
        }
        else{
            cout<<"OK\n";

        }

    }
    
    // int64_t product = MaxPairwiseProduct(numbers);
    // cout<<product<<"\n";
    return 0;
}