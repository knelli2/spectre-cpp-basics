#include <iostream>

#include "brigand.hpp"

template <typename T>
struct TypeDisplayer;

namespace tmpl = brigand;

int main() {
    using test = tmpl::list<double, int, char>;

    using three = tmpl::integral_constant<int, 3>;
    using four  = tmpl::integral_constant<int, 4>;
    using five  = tmpl::integral_constant<int, 5>;


    //TypeDisplayer<test> print_test;
    //TypeDisplayer<four> print_four;

    using sum = tmpl::plus<three, four>;
    using result = tmpl::integral_constant<typename sum::value_type, sum::value>;
    //TypeDisplayer<result> print_sum;
    
    // TypeDisplayer<tmpl::bool_<tmpl::less<four, three>::value>> print_bool;

    using which_is_smaller = tmpl::if_<tmpl::less<three, four>::type, three, four>;

    TypeDisplayer<tmpl::integral_constant<int, which_is_smaller::type::value>> print_if; 

    using unsorted_list = tmpl::list<five, three, four>;
    using sorted_list = tmpl::sort<unsorted_list>;

    TypeDisplayer<sorted_list> print_sorted;

    using first_list = tmpl::list<three, four, three>;
    using second_list = tmpl::list<four, four, five>;
    using joined_list = tmpl::append<first_list, second_list>;

    TypeDisplayer<joined_list> print_joined;

    return 0;
}
