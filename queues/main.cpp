#include <iostream>
#include "CinemaSimulation.h"

using namespace std;

int main()
{
    int simulationLength = 30 * 60; // 30 min
    CinemaSimulation simulation(simulationLength, 2 * 60);
    simulation.run();
    simulation.printStats();
    return 0;
}
