//
//
//template <class T, class U>
//void f(T arg1, U arg2);
//
//template <>
//void f(int arg1, int arg2)
//{
//    //...    
//}


template <class R, class T>
void f(R , T) = delete;

void f(int, int){}

void templatepartialspecilation()
{
    int a=1;
    f(a,a);
}
