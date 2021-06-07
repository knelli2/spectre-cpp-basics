// Use trapezoid rule to integrate a function of one variable func
// using fixed step size `step_size` between limits `lower_bound`
// and `upper_bound`
double trap(double (* const func)(const double),                                                             const double step_size, const double lower_bound,                                                                        const double upper_bound) noexcept;
