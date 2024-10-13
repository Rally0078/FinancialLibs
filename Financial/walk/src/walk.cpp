#include <Financial/walk.hpp>
namespace finance {
	//Binomial Random Walk
	//params: start - Initial Value
	BinomialWalk::BinomialWalk(long start, long mean, long stdev) : 
		start(start), current(start), step(0ul), rng(std::make_unique<finance::Normal<long>>(mean, stdev))
	{
	}
	long BinomialWalk::get_next() 
	{
		step++;
		current += rng->get_random();
		return current;
	}
	long BinomialWalk::get_first() 
	{
		return start;
	}

	BrownianWalk::BrownianWalk(double start, double dt) : 
		start(start), current(start), step(0ull), dt(dt), t(0.0), rng(std::make_unique<finance::Normal<double>>(0.0, sqrt(dt)))
	{
	}
	double BrownianWalk::get_next() {
		step++;
		current += rng->get_random() / sqrt(step);
		return current;
	}
	double BrownianWalk::get_first()
	{
		return start;
	}

	GeometricBrownianWalk::GeometricBrownianWalk(double start, double m, double sigma, double dt) :
		start(start), mean(m), stdev(sigma), current(start), dt(dt), t(0.0), rng(std::make_unique<finance::Normal<double>>(0.0, sqrt(dt))) {
	}
	double GeometricBrownianWalk::get_first() 
	{
		return start;
	}
	double GeometricBrownianWalk::get_next()
	{
		t += dt;
		current *= exp((mean - 0.5 * stdev * stdev) * dt + stdev * rng->get_random());
		return current;
	}
};
