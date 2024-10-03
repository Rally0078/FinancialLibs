#include <iostream>
#include <Financial/rng.hpp>
#include <Financial/walk.hpp>
#include <fstream>

int main(void)
{
    finance::Normal<double> normalRng(0.0, 1.0);
    finance::Normal<long> normalRngInt(0, 1);
    finance::BrownianWalk walk(1.0, 0.05, 0.5, 0.1);
    finance::GeometricBrownianWalk walk2(1.0, 0.05, 0.5, 0.1);
    std::ofstream fout("out.csv", std::ios::out);
    for(size_t i = 0l; i < 100; i++)
    {
        auto result = normalRng.get_random();
        fout<<i+1<<","<<result<<"\n";
    }
    std::ofstream fout2("out2.csv", std::ios::out);
    for(size_t i = 0l; i < 100; i++)
    {
        auto result = normalRngInt.get_random();
        fout2<<i+1<<","<<result<<"\n";
    }
    std::ofstream fout3("out3.csv", std::ios::out);
    fout3 << 0 << "," << walk.get_first()<<"\n";
    for (size_t i = 1l; i < 1000l; i++)
    {
        auto result = walk.get_next();
        fout3 << i + 1 << "," << result << "\n";
    }
    std::ofstream fout4("out4.csv", std::ios::out);
    fout4 << 0 << "," << walk2.get_first() << "\n";
    for (size_t i = 1l; i < 1000l; i++)
    {
        auto result = walk2.get_next();
        fout4 << i + 1 << "," << result << "\n";
        assertm(result > 0.0, "GBM is not correct!");
    }
}