

#include <iostream>
#include <string>


// hiding in domain:

void printa(const std::string &)
{

};


void printa(double ){};

void foo()
{
    //void printa(std::string);
//    printa(1); invlaid;
   // printa(1.1);
    std::string s;

    for(int i=0;i< 1000;i++)
    { 
        
    }
    printa(s);
}