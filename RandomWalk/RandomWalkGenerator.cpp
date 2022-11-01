//
// RandomWalkGenerator.cpp
// SIMPLE Random Walk Implementation.

#include "RandomWalkGenerator.h"
#include <cstdlib>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

//
// CONSTRUCTOR
RandomWalkGenerator::RandomWalkGenerator(int size, double start, double step)
: m_numSteps(size),
m_stepSize(step),
m_initialPrice(start)
{
}

RandomWalkGenerator::RandomWalkGenerator(const RandomWalkGenerator &p)
: m_numSteps(p.m_numSteps),
m_stepSize(p.m_stepSize),
m_initialPrice(p.m_initialPrice)
{
}

RandomWalkGenerator::~RandomWalkGenerator()
{
}

RandomWalkGenerator &RandomWalkGenerator::operator=(const RandomWalkGenerator &p)
{
    if (this != &p) 
    {
        m_numSteps = p.m_numSteps;
        m_stepSize = p.m_stepSize;
        m_initialPrice = p.m_initialPrice;
    }
    return *this;
}

// Returns a single step of the random walk

double RandomWalkGenerator::computeRandomStep(double currentPrice)
{
    const int num_directions = 3;
    int r = rand()%num_directions;
    double val = currentPrice;
    if (r == 0)
    {
        val += (m_stepSize * val);
    }
    else if (r == 1)
    {
        val -= (m_stepSize * val);
    }
    return val;
}

// MAIN

std::vector<double> RandomWalkGenerator::generateWalk()
{
    vector<double> walk;
    double prev = m_initialPrice;

    for(int i = 0; i<m_numSteps; ++i)
    {
        double val = computeRandomStep(prev);
        walk.push_back(val);
        prev = val;
    }
    return walk;
}

int main()
{
    // 100 steps starting at $30
    RandomWalkGenerator rw(100, 30, 0.01);
    vector<double> walk = rw.generateWalk();

    for(int i = 0; i<walk.size(); ++i)
    {
        cout << ", " << i << ", " << walk[i] << endl;
    }
    cout << endl;
    return 0;
}