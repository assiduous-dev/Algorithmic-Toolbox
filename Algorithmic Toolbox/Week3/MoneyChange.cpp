#include<iostream>
#include<vector>

using namespace::std;

int findBigDenomination(int moneyAmt)
{
    vector<int> coinsDenomination = {1,5,10};
    int bigdenomination=0;

    for(int i=0;i<coinsDenomination.size();i++)
    {
        if(moneyAmt >= coinsDenomination[i])
        {
            bigdenomination = coinsDenomination[i];
            
        }
    }
    //find biggest denomination coin which can be split

     return bigdenomination;
}

int main()
{
    vector<int> noOfCoinsEachDenomination = {0,0,0};
    int money=0;
    int bigdenomination = 0;
    cin>>money;

    while(true)
    {
        if(money ==  0)
        {
            break;
        }
        bigdenomination= findBigDenomination(money);
        //cout<<"BigDenomination"<<bigdenomination<<"\n";
        noOfCoinsEachDenomination[bigdenomination/5] += money / bigdenomination;
        //cout<<"Initial Money"<<money<<"\n";
        money = money % bigdenomination; 
        //cout<<"Money Left"<<money<<"\n";
        if(money == 0)
        {
            break;
        }
    }
    int count = 0;
    for(int i=0;i<noOfCoinsEachDenomination.size();i++)
    {
        count += noOfCoinsEachDenomination[i];
    }
    cout<<count;
    return 0;
}