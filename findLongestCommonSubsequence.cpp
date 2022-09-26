


#include <iostream>
#include <vector>

using namespace std;

int findLongestCommonSubsequence(const vector <char> &data1, const vector<char> &data2)
{
    unsigned int i,j;

    vector<vector<int>> LCS(data1.size()+1);

    for(i = 0;i<data1.size()+1;i++)
    {
        LCS[i].resize(data2.size()+1);
        LCS[i][0] = 0;
    }

    for ( i = 0; i < data2.size()+1; i++ )
    {
        LCS[0][i] = 0;
    }

    for ( i = 1; i < data1.size()+1; i++ )
    {
        for(j = 1; j < data2.size()+1; j++)
        {
            if(data1[i-1] == data2[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else
            {
                LCS[i][j] = LCS[i-1][j] > LCS[i][j-1] ? LCS[i-1][j]:LCS[i][j-1];
            }
        }
    }

    int max = 0;
    for(i=0;i<data1.size()+1;i++)
    {
        for(j=0;j<data2.size();j++)
        {
            cout << LCS[i][j] << " " ;
            if(LCS[i][j] > max)
            {
                max = LCS[i][j];
            }

        }
        cout << endl;
    }

    cout << max;

    return max;
}

void findLongestCommonSubsequenceMain()
{
    vector<char> X = {'A','C','C','G'};
    vector<char> Y = { 'C','C','A','G','C','A' };

    vector<char> Z(10,'c');

    findLongestCommonSubsequence(X,Y);

}
