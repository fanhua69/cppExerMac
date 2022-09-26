
#include <iostream>

using namespace std;


class base
{
public:

   virtual  ~base()
  {
    cout << "base destructed " << endl;
  }
};


class derived : public base
{
public:
  ~derived()
  {
    cout << "derived destructed " <<  endl;
  }
};


void destructor()
{
  base * p = new derived;

  delete p;
}