

#include <vector>

void maximizeHeap(std::vector<int> & v, int nHead);
void findMinElements(std::vector<int> &v, std::vector<int> &vMaxElements, int nMax);
void heapSort(std::vector<int> &v, std::vector<int> &vSorted);


void heapMain()
{
    std::vector<int> v = { 3,4,5,7,8,9,2,1 };

    std::vector<int> vSorted;

    std::vector<int> vMinElements;
    findMinElements(v, vMinElements, 4);
}

void findMinElements(std::vector<int> &v, std::vector<int> &vMinElements, int nMinElementCount)
{

    for(int i=0;i<nMinElementCount;i++)
    {
        vMinElements.push_back(v[i]);
    }

    for(int i=nMinElementCount;i<v.size();i++)
    {
        vMinElements.push_back(v[i]);
        maximizeHeap(vMinElements,0);
        vMinElements.erase(vMinElements.begin());
    }
}

void heapSort(std::vector<int> &v, std::vector<int> &vSorted)
{
    while(v.size()>0)
    {
        maximizeHeap(v, 0);
        vSorted.push_back(v[0]);
        v[0] = v[v.size()-1];
        v.resize(v.size()-1);
    }
}

void maximizeHeap(std::vector<int> &v, int nHead)
{
    
    int nLeft = nHead*2+1;
    int nRight = nHead*2+2;

    if(nLeft<v.size())
    {
        maximizeHeap(v, nLeft);
        
        if ( v[nLeft] > v[nHead] )
        {
            int n = v[nHead];
            v[nHead] = v[nLeft];
            v[nLeft] = n;

            maximizeHeap(v, nLeft);
        }
    }

    if(nRight< v.size())
    {
        maximizeHeap(v,nRight);
        if ( v[nRight] > v[nHead] )
        {
            int n = v[nHead];
            v[nHead] = v[nRight];
            v[nRight] = n;

            maximizeHeap(v, nRight);
        }
    }

}
