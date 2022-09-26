

#include <iostream>
using namespace std;

int knapsackme(int chosenNumber, int maxNumber, int number,int weight[],int value[],int capacity,int in[])
{
  if(number < 0 || capacity <= 0)
  {
    return 0;
  }

  if(chosenNumber >= maxNumber)
  {
    return 0;
  }

  if(capacity < weight[number])
  {
    return knapsackme(chosenNumber, maxNumber, number - 1, weight, value, capacity, in);
  }

  
  int valueOut = knapsackme(chosenNumber, maxNumber, number-1,weight,value,capacity,in);

  int *nIn = new int[number];
  memset(nIn,0, sizeof(int)*number);

  int valueIn = value[number] + knapsackme(chosenNumber+1, maxNumber, number-1,weight,value,capacity - weight[number],nIn);


  int valueTotal = valueOut;
  in[number] = 0;
  if(valueIn > valueOut)
  {
    chosenNumber++;
    memcpy(in, nIn, number*sizeof(int));
    in[number] = 1;
    valueTotal = valueIn;
  }

  delete nIn;

  return valueTotal;

}

void knapsackmemain()
{
  int number = 6;
  int weight[] = {1,2,3,4,5,3};
  int value[] = {9,8,7,1000,2000,1};
  int in[] = {0,0,0,0,0,0};
  int capacity = 9;
  int maxNumber=4;

  int total = knapsackme(0, maxNumber,number-1,weight,value,capacity,in);

  cout << total << endl;
  for(int i=0;i<number;i++)
  {
    cout<< i<< "  " << in[i] << endl;
    }
}
  