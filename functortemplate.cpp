

template<class T>
class DataArray
{
public:
    T & operator ()(int i,int j){return p[i*5+j];};
    T *p ;
};

typedef DataArray<int> DataArrayI;

void functortemplate()
{
    DataArray<double>  a;
    DataArrayI b;
    int n = a(1,2);
}
