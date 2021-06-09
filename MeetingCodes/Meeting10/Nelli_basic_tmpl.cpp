#include <iostream>

namespace tmpl {
template <typename... Ts>
struct list {};

template <typename T, T Value>
struct integral_constant {
    static const T value = Value; // tmpl::integral_const<int, 4>::value is 4    
    using value_type = T; //allows tmpl::integral_const<int, 4>::value_type is int
};

template <typename LHS, typename RHS>
struct plus : integral_constant<typename LHS::value_type, LHS::value + RHS::value> {};
} // namespace tmpl

template <typename T>
struct TypeDisplayer;

int main() {
    using test = tmpl::list<double, int, char>;

    using three = tmpl::integral_constant<int, 3>;
    using four = tmpl::integral_constant<int, 4>;
    using five = tmpl::integral_constant<int, 5>;


    //TypeDisplayer<test> print_test;
    //TypeDisplayer<four> print_four;

    using sum = tmpl::plus<three, four>;
    using result = tmpl::integral_constant<typename sum::value_type, sum::value>;
    TypeDisplayer<result> print_sum;

    return 0;
}
