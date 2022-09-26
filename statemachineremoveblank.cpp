

#include <iostream>

using namespace std;


#include <stdio.h>  

int statemachineremoveblank()
{
    char ch;
    int flag = 0;
    while ( (ch = getchar()) != EOF )
    {
        switch ( flag )
        {
            case 0:
                if ( ch == '/' )
                    flag = 1;
                else
                    putchar(ch);
                break;

            case 1:
                if ( ch == '/' )
                    flag = 2;
                else if ( ch == '*' )
                    flag = 3;
                else
                {
                    flag = 0;
                    putchar('/');
                    putchar(ch);
                }
                break;

            case 2:
                if ( ch == '\n' )
                {
                    putchar(ch);
                    flag = 0;
                }
                break;

            case 3:
                if ( ch == '*' )
                    flag = 4;
                break;

            case 4:
                if ( ch == '/' )
                    flag = 0;
                else
                    flag = 3;
                break;
        }
    }  
    return 0;
}
