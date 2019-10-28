#ifndef CINEMASIMULATION_H
#define CINEMASIMULATION_H

#include "ServiceDesk.h"
class CinemaSimulation
{
    public:
        CinemaSimulation(int simulationLen, int timeBetweenPeople);
        void run();
        void printStats() const;
    protected:

    private:
        int timeBetweenPeople;
        int incomingPeopleCountdown;
        int simulationLen;
        ServiceDesk tickets;
        ServiceDesk popcorn;
        ServiceDesk glasses;

        void tick();
        void addPeopleToTicketQueue(int numPeople);
};

#endif // CINEMASIMULATION_H
