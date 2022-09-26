
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class fraction
{
public:
    int a;
    int b;
    double v;

    fraction(int a,int b)
    {
        this->a = a;
        this->b = b;
        v = (double)a/(double)b;
    }

    bool operator < (const fraction &o) const
    {
        return v < o.v;
    }
};

vector<int> findKSmallestFraction(vector<int> A, int K)
{
    int N = A.size();
    double l=0;
    double r = 1;
    int p,q;

    while(l<r)
    {
        double m = (l+r)/2;
        int total = 0;
        double maxf = 0;

        int i=0,j=0;
        for(int i=0;i<N;i++)
        {
            for(;j<N;j++)
            {
                if(A[i]<m*A[j])
                {
                    break;
                }
            }
            total+=(N-j);
            if ( j == N )
            {
                break;
            }

            const double f = static_cast<double>(A[i])/A[j];
            if(f > maxf)
            {
                p = i;
                q= j;
                maxf =f;
            }
        }

        if(total == K)
        {
            break;
        }
        else if(total > K)
        {
            r= m;
        }
        else
        {
            l=m;
        }
    }

    return {p,q};

}


void findKSmallestFrationMain()
{
    vector<int> p = { 1,2,3,5,7 };
    int k=4;
    vector<int> f = findKSmallestFraction(p, k);
    cout << f[0] << " , " << f[1]<< endl;
}