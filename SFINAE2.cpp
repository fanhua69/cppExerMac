
//
//template<typename T>
//struct FooTest
//{
//  template<typename U, void (U::*)(int) const>
//  struct Test
//  {
//  };
//
//  template<typename U> 
//  static char test(Test<U, &U::foo> *)
//  {
//  }
//
//  template<typename U> 
//  static int test(...)
//  {
//  }
//
//  static constexpr bool value = (sizeof(test<T>(0)) == sizeof(char));
//};
//
//template<typename T>
//using HasFoo = std::integral_constant<bool, FooTest<T>::value>;