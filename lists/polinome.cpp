#include "../include/polinome.h"

Polinome::Polinome(const Monome& m)
{
    first = new PolinomeElement({m, nullptr});
}
Polinome::Polinome()
{
    first = new PolinomeElement({Monome(1, 0), nullptr});
}

Polinome::Polinome(const Polinome& other)
{
    // TODO
}
Polinome& Polinome::operator=(const Polinome& other)
{
    // TODO
    return *this;
}

Polinome::~Polinome()
{
    PolinomeElement* current = first;
    while(current != nullptr)
    {
        PolinomeElement* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void Polinome::add(const Monome& m)
{
    PolinomeElement* last = first;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    PolinomeElement* newMonome = new PolinomeElement({m, nullptr});
    last->next = newMonome;
}

double Polinome::calculateAt(double x) const
{
    double result = 0;
    PolinomeElement* current = first;
    while (current != nullptr)
    {
        result += current->m.calculateAt(x);
    }
    return result;
}
Polinome Polinome::add(const Polinome& other) const
{
    // TODO
    return Polinome();
}
Polinome Polinome::mult(const Monome& other) const
{
    Polinome result;
    PolinomeElement* current = first;
    while(current != nullptr)
    {
        result.add(current->m.mult(other));
    }
    return result;
}

Polinome Polinome::mult(const Polinome& other) const
{
    Polinome result;
    PolinomeElement* current = other.first;
    while (current != nullptr)
    {
        Polinome partial = this->mult(current->m);
        result = result.add(partial);
    }
    return result;
}
