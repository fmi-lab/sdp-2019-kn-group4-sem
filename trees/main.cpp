#include <iostream>
#include "Taxonomy.h"
using namespace std;

int main()
{
    Taxonomy t;
    t.addEntity({"Animalia", "Chordata", "Mammalia", "Primates", "Hominidae", "Homo", "Homo Sapiens" })
     .addEntity({"Animalia", "Chordata", "Mammalia", "Grizachi", "Mishka", "Polska Mishka" });

    t.print();
    Taxonomy::TaxonomyIterator it = t.iterateLeaves();
    while (it.hasNext())
    {
        cout << it.getValue() << endl;
        it.next();
    }

    cout << "PREORDER" << endl;
    t.printPreOrder();
    cout << endl;
    cout << "POSTORDER" << endl;
    t.printPostOrder();
    cout << endl;
    return 0;
}
