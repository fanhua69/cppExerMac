

int my_strcmp(const char *a, const char *b)
{
    while ( *a == *b && *a != 0 && *b != 0 )
    {
        a++, b++;
    }
    // Version 1
    return *a - *b;
    // Version 2
    //return *a <=> *b;// C++20
    // Version 3
    return ((*a > *b) - (*a < *b));
}

void threewaycomp()
{
    char *a = "adf";
    char *b = "fdsaf";
    int n = my_strcmp(a, b);
}
