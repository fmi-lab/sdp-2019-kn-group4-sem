#include "ServiceDesk.h"
#include <string>

ServiceDesk::ServiceDesk(int ticksPerPerson)
   : ticksPerPerson(ticksPerPerson), currentCountdown(0) {}
void ServiceDesk::enqueue(const std::string& person)
{
    people.push(person);
}

bool ServiceDesk::tick(std::string& person)
{
    if (currentCountdown == 0) {
        if (!people.empty()) {
            currentCountdown = ticksPerPerson;
        } else {
            idleTime++;
        }
    } else {
        currentCountdown--;
        if (currentCountdown == 0) {
            person = people.front();
            people.pop();
            return true;
        }
    }
    return false;
}
int ServiceDesk::getIdleTime() const
{
    return idleTime;
}
int ServiceDesk::remainingPeople() const
{
    return people.size();
}
