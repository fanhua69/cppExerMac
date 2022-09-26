#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

char findfirstsinglechar(char * s)
{
    std::map<char, int> mapQuantity;
    std::map<char, int> mapIndex;

    char *sOri = s;
    while(*s)  // Warning! not while(s)
    {
        mapQuantity[*s]++;
        if(mapIndex[*s] == 0)
        {
            mapIndex[*s] = s-sOri+1;
        }
        s++;
    }

    
    std::map<char,int>::iterator it = mapQuantity.begin();
    int smallestIndex = strlen(sOri) + 1;
    char firstSingleChar = ' ';

    while(it != mapQuantity.end())
    {
        if(it->second == 1)
        {
            int indexSingle = mapIndex[it->first];
            if( indexSingle < smallestIndex)
            {
                smallestIndex = indexSingle;
                firstSingleChar = it->first; // notice;
            }
        }

        it++;
    }


    if(smallestIndex == strlen(sOri)+1)
    {
        throw 'c';
    }

    return firstSingleChar;
}


void findfirstsinglecharMain()
{
    char * s = "abcdefgabcdefg";

    try
    {
        char c = findfirstsinglechar(s);
        cout << " First Single Character:" << c << endl;
    }
    catch(int a)
    {
        cout << a << endl;
    }
    catch(std::string *e)
    {
        cout << *e  <<  endl;
        delete e;
    }
    catch(std::bad_alloc &e)
    {
        cout <<" some error happened . " << endl;
    }
    catch(std::bad_array_new_length &e)
    {
    
    }
}
