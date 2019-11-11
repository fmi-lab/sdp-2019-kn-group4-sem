#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T>
list<list<T>> chunk(list<T>& l, int chunkSize)
{
    list<list<T>> result;
    int currentCounter = 0;
    for (auto el : l)
    {
        if (currentCounter == 0) {
            // begin new list
            result.push_back(list<T>());
        }
        result.back().push_back(el);
        currentCounter = (currentCounter + 1) % chunkSize;
    }
    return result;
}
int main()
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        // l.push_back(i); // put element at the end of list, like queue
        l.push_front(i); // put element at the start of list, like stack
    }

    vector<int> v;
    for (int i = 20; i < 25; i++) {
        v.push_back(i);
    }
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        int value = *it;
        // inserts element(s) before the iterator
        l.insert(it, value + 100);
        // returns an iterator to the newly inserted element
        // list<int>::iterator it2 = l.insert(it, value + 100);
        // inserts all elements of the vector before the iterator
        // l.insert(it, v.begin(), v.end());
    }
    cout << endl;
    // delete every second element
    int i = 0;
    for (auto it = l.begin(); it != l.end(); ++i)
    {
        if (i % 2 == 1) {
            // erase moves the iterator to the next valid element
            it = l.erase(it);
        } else {
            // manually move the iterator
            ++it;
        }
    }
    for (auto el : l) {
        cout << el << " ";
    }
    cout << endl;
    // delete all elements between two iterators
    list<int>::iterator thirdEl = l.begin();
    advance(thirdEl, 3);
    list<int>::iterator fifthEl = l.begin();
    advance(fifthEl, 5);
    l.erase(thirdEl, fifthEl);
    // delete all elements from iterator to end of list
    list<int>::iterator fourthEl = l.begin();
    advance(fourthEl, 4);
    l.erase(fourthEl, l.end());
    for (auto el : l) {
        cout << el << " ";
    }
    cout << endl;

    // print every third element
    i = 0;
    for (list<int>::iterator it = l.begin();
        it != l.end();
         ++it, ++i)
    {
        if (i % 3 == 0)
        {
            cout << *it << " ";
        }
    }
    cout << endl;
    // reverse iterator - print backward
    i = 0;
    for (list<int>::reverse_iterator it = l.rbegin();
        it != l.rend();
         ++it, ++i)
    {
        if (i % 3 == 0)
        {
            cout << *it << " ";
        }
    }
    cout << endl;
    // auto examples
    i = 0;
    for (auto it = l.begin(); it != l.end(); ++it, ++i)
    {
        if (i % 3 == 0)
        {
            cout << *it << " ";
        }
    }
    cout << endl;
    i = 0;
    for (auto element : l)
    {
        if (i % 3 == 0) {
            cout << element << " ";
        }
        i++;
    }
    cout << endl;
    cout << "====CHUNK TEST====" << endl;
    list<int> l2;
    for (int i = 20; i < 30; i++)
    {
        l2.push_back(i);
    }
    list<list<int>> chunks = chunk(l2, 3);
    for (list<list<int>>::iterator it1 = chunks.begin();
        it1 != chunks.end();
        ++it1)
        {
            for (list<int>::iterator it2 = (*it1).begin();
                it2 != (*it1).end(); ++it2)
                {
                    cout << *it2 << " ";
                }
                cout << endl;
        }
    for (auto c : chunks)
    {
        for (auto el : c) {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}
