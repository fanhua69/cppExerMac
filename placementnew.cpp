
#include <new>

struct SPort
{
};


void placementnew()
{
  char *comAddr = new char[1000];
  SPort  *comPorts = new (comAddr) SPort [10]; // SPort; // create array
  delete comAddr;
}

