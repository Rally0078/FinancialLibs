#pragma once
#include <Financial/rng.hpp>
#include <math.h>
#include <memory>

namespace finance
{
    template <typename T>
    class Walk
    {

    public:
        virtual T get_next() = 0;
        virtual T get_first() = 0;
    };

    class BinomialWalk : public Walk<long> 
    {
        private:
            std::unique_ptr<Normal<long>> rng;
            long start;
            long current;
            size_t step;
        public:
            BinomialWalk(long start, long mean, long stdev);
            long get_next();
            long get_first();
    };

    class BrownianWalk : public Walk<double> 
    {
        private:
            std::unique_ptr<Normal<double>> rng;
            double start;
            double current;
            size_t step;
            double dt;
            double t;
        public:
            BrownianWalk(double start, double dt);
            double get_next();
            double get_first();
    };

    class GeometricBrownianWalk : public Walk<double>
    {
        private:
            std::unique_ptr<Normal<double>> rng;
            double start;
            double current;
            double mean;
            double stdev;
            double dt;
            double t;
    public:
        GeometricBrownianWalk(double start, double mean, double stdev, double dt);
        double get_next();
        double get_first();
    };

};
