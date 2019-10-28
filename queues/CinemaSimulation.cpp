#include <cstdlib>
#include <string>
#include <iostream>
#include "CinemaSimulation.h"

CinemaSimulation::CinemaSimulation(int len, int timeBetweenPeople):
     simulationLen(len), timeBetweenPeople(timeBetweenPeople),
     incomingPeopleCountdown(timeBetweenPeople),
     tickets(30), popcorn(90), glasses(15) { }
void CinemaSimulation::run()
{
    for (int i = 0; i < simulationLen; i++)
    {
        tick();
    }
}

void CinemaSimulation::tick()
{
    incomingPeopleCountdown--;
    if (incomingPeopleCountdown == 0) {
        int numPeople = rand() % 11;
        addPeopleToTicketQueue(numPeople);
        incomingPeopleCountdown = timeBetweenPeople;
    }
    std::string movingPerson;
    if (tickets.tick(movingPerson))
    {
        int chance = rand() % 10;
        if (chance < 7) {
            popcorn.enqueue(movingPerson);
        } else {
            glasses.enqueue(movingPerson);
        }
    }
    if (popcorn.tick(movingPerson)) {
        glasses.enqueue(movingPerson);
    }
    glasses.tick(movingPerson);
}

void CinemaSimulation::addPeopleToTicketQueue(int numPeople)
{
    for (int i = 0; i < numPeople; i++)
    {
        tickets.enqueue("Person");
    }
}
void CinemaSimulation::printStats() const
{
    int peopleLeft = tickets.remainingPeople();
    peopleLeft += popcorn.remainingPeople();
    peopleLeft += glasses.remainingPeople();
    std::cout << peopleLeft << " could not enter on time" << std::endl;

    std::cout << "Ticket desk was idle " << tickets.getIdleTime() << " ticks" << std::endl;
}
