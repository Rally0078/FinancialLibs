#include <Financial/rng.hpp>

namespace finance
{
    template <typename T>
    Normal<T>::Normal(T mean, T stdev) : mean(mean), stdev(stdev), gaussian(mean, stdev)
    {
        bool typeCheck = typeid(T) == typeid(long(5l)) || typeid(T) == typeid(int(3)) || typeid(T) == typeid(float(3.0f)) || typeid(T) == typeid(double(5.0));
        assertm(typeCheck, "Assertion failed! templated type must be double, long, float, or int");
        gen.seed(rd());
    }
    template <typename T>
    T Normal<T>::get_random()
    {
        double gaussianOutput = gaussian(gen);
        T result;
        if(typeid(T) == typeid(long(5l)) || typeid(T) == typeid(int(3)) )
        {
            if(gaussianOutput >= 0)
                result = 1;
            else
                result = -1;
        }
        else
            result = gaussianOutput;
        return result;
    }
};
template finance::Normal<double>::Normal(double, double);
template finance::Normal<float>::Normal(float, float);
template finance::Normal<long>::Normal(long, long);
template finance::Normal<int>::Normal(int, int);

template double finance::Normal<double>::get_random();
template float finance::Normal<float>::get_random();
template long finance::Normal<long>::get_random();
template int finance::Normal<int>::get_random();