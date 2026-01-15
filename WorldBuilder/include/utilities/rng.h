#ifndef RNG_H
#define RNG_H

#include <cstdint>
#include <mutex>
#include <random>

class RandomGenerator
{
  public:
	static RandomGenerator &getInstance();

	void SetSeed(unsigned int seed);

	int NextInt(int min, int max);
	uint64_t NextUint64(uint64_t min, uint64_t max);

	double NextDouble(double min, double max);

	RandomGenerator(const RandomGenerator &) = delete;
	RandomGenerator &operator=(const RandomGenerator &) = delete;

  private:
	RandomGenerator();
	void ThrowUninitialized();

	bool initialized = false;

	std::mt19937 rng_engine;
	std::mutex mutex_instance;
};

static inline int RandomUint64(const uint64_t low, const uint64_t high)
{
	return RandomGenerator::getInstance().NextInt(low, high);
}

static inline int RandomInt(const int low, const int high)
{
	return RandomGenerator::getInstance().NextInt(low, high);
}

#endif // RNG_H
