#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <algorithm>
// original author - The Builder

// create new device
// create initial random solutions and add them to vector Solutions
// Solution is a struct of rank, x,y,z, rank is just fitness
// goal is to set ans to 0, set ranks accordingly
// on every while iteration of while loop
// - we check how fit every solution is
// - sort our solutions by rank
// - print solutions
// - take top 1000 solutions
// - clear solutions
// - create a new random distribution
// - go thru every solution and multiply current solution by a random number
// - recombine old solution with new solution and create offspring


struct Solution
{
    double rank, x, y, z;
    void fitness()
    {
        double ans = (6 * x + -y + std::pow(z, 200)) - 25;

        rank = (ans == 0) ? 9999 : std::abs(1 / ans);
    }
};

int main()
{

    // create initial random solutions
    std::random_device device;
    std::uniform_real_distribution<double> unif(-10000, 10000);

    std::vector<Solution> solutions;

    const int NUM = 9000000;

    while (true)
    {
        for (int i = 0; i < NUM; i++)
            solutions.push_back(Solution{
                0, unif(device), unif(device), unif(device)});

        // run out fitness function
        // and see our candidates
        for (auto &s : solutions)
        {
            s.fitness();
        }

        // sort by fitness rank
        std::sort(solutions.begin(), solutions.end(), [](const auto &lhs, const auto &rhs)
                  { return lhs.rank > rhs.rank; });

        std::for_each(
            solutions.begin(),
            solutions.begin() + 10,
            [](const auto &s)
            {
                std::cout << std::fixed << "Rank " << static_cast<int>(s.rank) << "\n x:" << s.x << " y:" << s.y << "z:" << s.z << " \n";
            });

        const int SAMPLE_SIZE = 1000;
        std::vector<Solution> sample;

        std::copy(solutions.begin(), solutions.begin() + SAMPLE_SIZE, std::back_inserter(sample));

        solutions.clear();

        std::uniform_real_distribution<double> m(0.99, 1.01);

        std::for_each(sample.begin(), sample.end(), [&](auto &s)
                      {
        s.x *= m(device);
        s.y *= m(device);
        s.z *= m(device); });

        std::uniform_int_distribution<int> cross(0, SAMPLE_SIZE - 1);

        // mutate by 1% and crossover
        for (int i = 0; i < NUM; i++)
        {
            solutions.push_back(Solution{
                0,
                sample[cross(device)].x,
                sample[cross(device)].y,
                sample[cross(device)].z,
            });
        }
    }
    return 0;
}