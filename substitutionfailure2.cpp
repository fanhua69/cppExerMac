
#include <type_traits>
#include <stdint.h>

struct Counter
{
  void increase()
  {
    // Implements
  }
};

template <typename T>
void inc_counter(T& intTypeCounter, std::decay_t<decltype(++intTypeCounter)>* = nullptr)
{
  ++intTypeCounter;
}

//template <typename T>
//void inc_counter(T& counterObj, 
//								 std::decay_t<decltype(counterObj.increase())>* = nullptr)
//{
//  counterObj.increase();
//}
//
//void substitutionfailure2()
//{
//  Counter cntObj;
//  uint32_t cntUI32;
//
//  // blah blah blah
//  inc_counter(cntObj);
//  inc_counter(cntUI32);
//}
