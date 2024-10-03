//Random Number Generators
#pragma once

#include <random>
#include <typeinfo>

#define NDEBUG
#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))

namespace finance 
{
    template <typename T>
    class Rng
    {
        public:
            virtual T get_random() = 0;
    };
    template <typename T>
    class Normal : public Rng<T>
    {        
        T mean;
        T stdev;

        std::random_device rd;
        std::mt19937_64 gen;
        std::normal_distribution<double> gaussian;

        public:
            Normal(T mean, T stdev);
            T get_random();
    };
};
