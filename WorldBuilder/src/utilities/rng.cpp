#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <utilities/rng.h>

void RandomGenerator::ThrowUninitialized()
{
	if (!initialized)
		throw std::runtime_error("RandomGenerator accessed without being seeded.");
}

RandomGenerator &RandomGenerator::getInstance()
{
	static RandomGenerator instance;
	return instance;
}

RandomGenerator::RandomGenerator()
{
	std::random_device rd;
	rng_engine.seed(rd());
}

void RandomGenerator::SetSeed(unsigned int seed)
{
	std::lock_guard<std::mutex> lock(mutex_instance);
	rng_engine.seed(seed);
	initialized = true;
}

uint64_t RandomGenerator::NextUint64(uint64_t min, uint64_t max)
{
	ThrowUninitialized();
	std::lock_guard<std::mutex> lock(mutex_instance);
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng_engine);
}

int RandomGenerator::NextInt(int min, int max)
{
	ThrowUninitialized();
	std::lock_guard<std::mutex> lock(mutex_instance);
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rng_engine);
}

double RandomGenerator::NextDouble(double min, double max)
{
	ThrowUninitialized();
	std::lock_guard<std::mutex> lock(mutex_instance);
	std::uniform_real_distribution<double> dist(min, max);
	return dist(rng_engine);
}
