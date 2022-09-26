//
//#include <boost/hana.hpp>
//#include <iostream>
//#include <string>
//
//using namespace std;
//namespace hana = boost::hana;
//
//// Check if a type has a serialize method.
//auto hasSerialize = hana::is_valid([](auto&& x) -> decltype(x.serialize())
//{});
//
//// Serialize any kind of objects.
//template <typename T>
//std::string serialize(T const& obj)
//{
//  return hana::if_(hasSerialize(obj), // Serialize is selected if available!
//                   [](auto& x)
//  {
//    return x.serialize();
//  },
//                   [](auto& x)
//  {
//    return to_string(x);
//  }
//  )(obj);
//}
//
//// Type A with only a to_string overload.
//struct A
//{
//};
//
//std::string to_string(const A&)
//{
//  return "I am a A!";
//}
//
//// Type B with a serialize method.
//struct B
//{
//  std::string serialize() const
//  {
//    return "I am a B!";
//  }
//};
//
//// Type C with a "wrong" serialize member (not a method) and a to_string overload.
//struct C
//{
//  std::string serialize;
//};
//
//std::string to_string(const C&)
//{
//  return "I am a C!";
//}
//
//template <class T> struct hasSerialize
//{
//  // For the compile time comparison.
//  typedef char yes[1];
//  typedef yes no[2];
//
//  // This helper struct permits us to check that serialize is truly a method.
//  // The second argument must be of the type of the first.
//  // For instance reallyHas<int, 10> would be substituted by reallyHas<int, int 10> and works!
//  // reallyHas<int, &C::serialize> would be substituted by reallyHas<int, int &C::serialize> and fail!
//  // Note: It only works with integral constants and pointers (so function pointers work).
//  // In our case we check that &C::serialize has the same signature as the first argument!
//  // reallyHas<std::string (C::*)(), &C::serialize> should be substituted by 
//  // reallyHas<std::string (C::*)(), std::string (C::*)() &C::serialize> and work!
//  template <typename U, U u> struct reallyHas;
//
//  // Two overloads for yes: one for the signature of a normal method, one is for the signature of a const method.
//  // We accept a pointer to our helper struct, in order to avoid to instantiate a real instance of this type.
//  // std::string (C::*)() is function pointer declaration.
//  template <typename C> static yes& test(reallyHas<std::string(C::*)(), &C::serialize>* /*unused*/)
//  {
//  }
//  template <typename C> static yes& test(reallyHas<std::string(C::*)() const, &C::serialize>* /*unused*/)
//  {
//  }
//
//  // The famous C++ sink-hole.
//  // Note that sink-hole must be templated too as we are testing test<T>(0).
//  // If the method serialize isn't available, we will end up in this method.
//  template <typename> static no& test(...)
//  { /* dark matter */
//  }
//
//  // The constant used as a return value for the test.
//  // The test is actually done here, thanks to the sizeof compile-time evaluation.
//  static const bool value = sizeof(test<T>(0)) == sizeof(yes);
//};
//
//
//void hasSerializeMain()
//{
//  A a;
//  B b;
//  C c;
//
//  std::cout << serialize(a) << std::endl;
//  std::cout << serialize(b) << std::endl;
//  std::cout << serialize(c) << std::endl;
//
//  // Using the struct A, B, C defined in the previous hasSerialize example.
//  std::cout << hasSerialize<A>::value << std::endl;
//  std::cout << hasSerialize<B>::value << std::endl;
//  std::cout << hasSerialize<C>::value << std::endl;
//}