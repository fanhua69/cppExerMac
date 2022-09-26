

#include <iostream>
#include <algorithm>
#include <vector>

int stdmakeheapmain()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };

    std::cout << "initially, v: ";
    for ( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    std::make_heap(v.begin(), v.end());

    std::cout << "after make_heap, v: ";
    for ( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    std::pop_heap(v.begin(), v.end());
    std::cout << "after pop_heap, v: ";
    for ( auto i : v ) std::cout << i << ' ';
    auto largest = v.back();
    v.pop_back();
    std::cout << "largest element: " << largest << '\n';

    std::pop_heap(v.begin(), v.end());
    std::cout << "after pop_heap, v: ";
    for ( auto i : v ) std::cout << i << ' ';
    v.pop_back();

    std::pop_heap(v.begin(), v.end());
    std::cout << "after pop_heap, v: ";
    for ( auto i : v ) std::cout << i << ' ';
    v.pop_back();


    std::cout << "after removing the largest element, v: ";
    for ( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}