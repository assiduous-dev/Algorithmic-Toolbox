#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<int> value_per_weight(weights.size());

  while(capacity > 0)
  {
    int max_index = 0;
    int max_value = 0;
    double va = 0.0;
    for(int i=0; i<weights.size();i++)
    {
        double temp = ceil(((double)values[i]/(double)weights[i]) * 10000)/10000; 
        //std::cout<<"Max Value "<<temp<<"\n";
        if(temp > va && value_per_weight[i] == 0)
        {
            va = temp;
            max_index = i;
           // std::cout<<"Max Value "<<i<<"\n";
        }

    }
    if(value_per_weight[max_index] == 1)
    {
        break;
    }
    value_per_weight[max_index] = 1;
    
    //std::cout<<"Max Value "<<max_index<<"\n";
    if((capacity - weights[max_index]) < 0)
    {
        double it = (double)values[max_index]/(double)weights[max_index];
         //std::cout<<"it value "<<it<<std::endl;
         //std::cout<<"capacity value "<<capacity<<std::endl;
        value += ceil((it * capacity) * 10000)/10000;
          //std::cout<<"optimal value 1 "<<value<<std::endl;
        capacity = 0;
    }
    else
    {
        capacity -= weights[max_index];
        //std::cout<<"Capacity "<<capacity<<"\n";
        value += values[max_index]; 
    }
    
  }
  
  // write your code here
  //std::cout<<"optimal value "<<value<<std::endl;

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
 // std::cout<<"optimal value "<<optimal_value<<std::endl;
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
