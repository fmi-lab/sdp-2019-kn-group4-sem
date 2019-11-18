#include <iostream>
#include "Taxonomy.h"
using namespace std;

int main()
{
    Taxonomy t;
    t.addEntity({"Animalia", "Chordata", "Mammalia", "Primates", "Hominidae", "Homo", "Homo Sapiens" })
     .addEntity({"Animalia", "Chordata", "Mammalia", "Grizachi", "Mishka", "Polska Mishka" });

    t.print();
    return 0;
}
