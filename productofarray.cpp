



void myProduct(int *a, int *b, int n)
{
    int p = 1;
    for(int i=0;i<n;i++)
    {
        b[i]=p;
        p*=a[i];
    }

    p=1;
    for(int i=n-1;i>=0;i--)
    {
        b[i] *= p;
        p*=a[i];
    }
}

void productofarray()
{
    int A[4]  = {2,3,4,5};
    int B[4];

    myProduct(A,B,4);

    return;
}