#ifndef SERVICEDESK_H
#define SERVICEDESK_H

#include <string>
#include <queue>
class ServiceDesk
{
    public:
        ServiceDesk(int ticksPerPerson);
        void enqueue(const std::string& person);
        bool tick(std::string& person);
        int getIdleTime() const;
        int remainingPeople() const;
    protected:

    private:
        int currentCountdown;
        int ticksPerPerson;
        int idleTime;
        std::queue<std::string> people;
};

#endif // SERVICEDESK_H
