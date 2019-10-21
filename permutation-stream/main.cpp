#include <iostream>
#include <vector>
#include "PermutationStream.h"
using namespace std;

void print(vector<char> perm) {
    for (auto s : perm) {
        cout << s << " ";
    }
    cout << endl;
}
bool allUsed(vector<bool> used) {
    for (auto u : used) {
        if (!u) {
            return false;
        }
    }
    return true;
}

void permuteRecursive(vector<char>& currentPerm,
                      vector<char>& symbols,
                      vector<bool>& used)
{

    if (allUsed(used)) {
        print(currentPerm);
        return;
    }
    for (int i = 0; i < symbols.size(); i++) {
        if (used[i]) {
            continue;
        }
        currentPerm.push_back(symbols[i]);
        used[i] = true;
        permuteRecursive(currentPerm, symbols, used);
        currentPerm.pop_back();
        used[i] = false;
    }
}
void permute(vector<char>& symbols) {
    vector<bool> used;
    for (auto s : symbols) {
        used.push_back(false);
    }
    vector<char> permutation;
    permuteRecursive(permutation, symbols, used);
}

int main()
{
    vector<char> symbols = {'a', 'b', 'c', 'd', 'e'};
    // permute(symbols);
    PermutationStream p(symbols, 3);
    // p.generateAll();

    int count = 4;
    while (p.hasNext() && count > 0) {
        print(p.next());
        count--;
    }
    return 0;
}
