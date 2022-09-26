//
//#include <tuple>
//#include <stdexcept>
//#include <boost/variant.hpp>
//
//#include <iostream>
//
//using namespace std;
//
//template <size_t N8, typename... T>
//boost::variant<T...> dynamic_get_impl(size_t i, const std::tuple<T...>& tpl)
//{
//  int nnnn= N8;
//  if ( i == N8 )
//    return std::get<N8>(tpl);
//  else if ( N8 == sizeof...(T)-1 )
//    throw std::out_of_range("Tuple element out of range.");
//  else
//  {
//    int mm = (N8 < sizeof...(T)-1 ? N8 + 1 : 0);
//    return dynamic_get_impl<N8 < sizeof...(T)-1 ? N8 + 1 : 0>(i, tpl);
//  }
//}
//
//template <typename... T>
//boost::variant<T...> dynamic_get(size_t i, const std::tuple<T...>& tpl)
//{
//  return dynamic_get_impl<0>(i, tpl);
//}
//
//int variadiciterativ()
//{
//  std::tuple <int ,int, int , char> t={7,8,9,'c'};
//
//  int n = std::tuple_size_v<decltype(t)>;
//  boost::variant<int, char>  v;
//
//  for(int i=0;i < n ;i++)
//  {
//    v = dynamic_get (i, t);
//    cout << v << endl;
//  }
//  return 0;
//}