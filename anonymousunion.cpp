#include<stdio.h>
union Scope
{
    // Anonymous structure
    struct
    {
        char alpha;
        int num;
    };
    int mmm;
};

int func(int a)
{
    return a + 10;
}

void anonymousunion()
{
    Scope x;
    x.mmm = 0;
    x.num = 65;
    x.alpha = 'C';
    

    // Note that members of structure are accessed directly
    printf("x.alpha = %c, x.num = %d", x.alpha, x.num);

    int j=func(10);
    const int w = j+10;
    int* wp = const_cast <int*> (&w);
    *wp = 20;

    return;
}

