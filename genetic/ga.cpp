#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <algorithm>
// original author - The Builder

struct Solution 
{
    double rank, x, y, z;
    void fitness()
    {
        double ans = (6 * x + -y + std::pow(z, 200)) - 25;

        rank = (ans == 0) ? 9999 : std::abs(1/ans);
    }
};

int main ()
{

    // create initial random solutions
    std::random_device device;
    std::uniform_real_distribution<double> unif(-10000, 10000);

    std::vector<Solution> solutions;

    const int NUM = 100000;
    for (int i = 0 ; i < NUM ; i++)
        solutions.push_back(Solution
        {
            0, unif(device), unif(device), unif(device)
        });


    // run out fitness function
    // and see our candidates
    for (auto& s: solutions)
    {
        s.fitness();
    }

    // sort by fitness rank
    std::sort(solutions.begin(), solutions.end  (), [](const auto& lhs, const auto& rhs)
        {
            return lhs.rank > rhs.rank;
        }
    ); 

    std::for_each(solutions.begin(), solutions.end() +10,[](const auto& s)
    {
        std::cout << std::fixed << "Rank " << static_cast<int>(s.rank) << "\n x:" << s.x << " y:" << s.y << "z:" >> s.z << " \n";        
    }
    )
}