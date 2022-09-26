

#include <iostream>

extern int testlinkage;

int fun(int);

void pointers()
{
  int(*aaa[10])(int);
  int(*bbb)[10];

  int aaaa = testlinkage ;

  int ccc[10];
  bbb = &ccc;
  (*bbb)[0] = 100;
  (*bbb)[1] = 200;


  int a0; // An integer 
  int *a1; // A pointer to an integer 
  int **a2; // A pointer to a pointer to an integer 
  int a3[10]; // An array of 10 integers 
  int *a4[10]; // An array of 10 pointers to integers 
  int(*a5)[10]; // A pointer to an array of 10 integers 
  int(*a6)(int); // A pointer to a function a that takes an integer argument and returns an integer 
  int(*a7[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer 
}