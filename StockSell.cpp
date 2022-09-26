#include <iostream>
#include <vector>

using namespace std;

enum stockState
{
    REST, // -> HOLD, REST
    HOLD, // -> hold, SOLD
    SOLD, // -> Rest
};

vector<int> maxProfitDays;
vector<stockState> stateDays;

int getMaxProfitA(vector<int> &price, int i, int N)
{
    if ( N == 0 )
    {
        return 0;
    }

    if(i == N)
    {
        return maxProfitDays[i-1];
    }

    if(i == 0 || stateDays[i-1] == REST)
    {
        int pp = 0;
        if ( i == 0)
        {
            pp = 0;
        }
        else
        {
            pp = maxProfitDays[i-1];
        }
        stateDays[i] = HOLD;
        int pi1 = pp - price[i];
        maxProfitDays[i] = pi1;
        int m1 = getMaxProfitA(price,i+1,N);


        stateDays[i] = REST;
        int pi2 = pp;
        maxProfitDays[i] = pi2;
        int m2 = getMaxProfitA(price, i + 1, N);

        if(m1>m2)
        {
            stateDays[i]= HOLD;
            maxProfitDays[i] = pi1;
        }
        else
        {
            stateDays[i] = REST;
            maxProfitDays[i] = pi2;
        }

        getMaxProfitA(price, i + 1, N);
    }

    else if ( stateDays[i - 1] == HOLD )
    {
        stateDays[i] = HOLD;
        int pi1 = maxProfitDays[i - 1];
        maxProfitDays[i] = pi1;
        int m1 = getMaxProfitA(price, i + 1, N);


        stateDays[i] = SOLD;
        int pi2 = maxProfitDays[i - 1] + price[i];
        maxProfitDays[i] = pi2;
        int m2 = getMaxProfitA(price, i + 1, N);

        if ( m1 > m2 )
        {
            stateDays[i] = HOLD;
            maxProfitDays[i] = pi1;
        }
        else
        {
            stateDays[i] = SOLD;
            maxProfitDays[i] = pi2;
        }

        getMaxProfitA(price, i + 1, N);
    }

    else if ( stateDays[i - 1] == SOLD )
    {
        stateDays[i] = REST;
        maxProfitDays[i] = maxProfitDays[i - 1];
        getMaxProfitA(price, i + 1, N);
    }
}

int getMaxProfit(vector<int> &price, int N)
{
    maxProfitDays.resize(N,0);

    stockState s  = REST;
    stateDays.resize(N,s);


    return getMaxProfitA(price, 0, N);
}

void stockSellMain()
{
    vector<int> price={1,2,3,4,5};

    int n = getMaxProfit(price, 5);

    cout << n << endl;
}