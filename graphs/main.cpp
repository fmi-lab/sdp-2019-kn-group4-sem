#include <iostream>
#include <queue>
#include <set>
#include "Graph.h"
using namespace std;

template <typename T>
bool hasLoops(const Graph<T>& g)
{
    for (const T& v : g.vertices())
    {
        if (g.hasEdge(v, v))
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool isComplete(const Graph<T>& g)
{
    for (const T& v1 : g.vertices()) {
        for (const T& v2 : g.vertices()) {
            if (!g.hasEdge(v1, v2)) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool isUnordered(const Graph<T>& g)
{
    for (const T& v1 : g.vertices()) {
        for (const T& v2 : g.successors(v1))
        {
            if (!hasEdge(v2, v1)) {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
Graph<T> complement(const Graph<T>& g)
{
    Graph<T> result;
    for (const Vertex& v : g.vertices()) {
        result.addVertex(v);
    }
    for (const Vertex& v1 : g.vertices()) {
        for (const Vertex& v2 : g.vertices()) {
            if (!g.hasEdge(v1, v2)) {
                result.addEdge(v1, v2);
            }
        }
    }
    return result;
}

template <typename T>
int propagateSecrets(const T& person, const Graph<T>& friends, T& mostSources)
{
    std::queue<T> bfs;
    std::set<T> visited;
    std::unordered_map<T, int> countSources;
    bfs.push(person);
    while (!bfs.empty()) {
        T p = bfs.front();
        bfs.pop();
        if (visited.count(p) != 0)
        {
            // already visited, skip
            continue;
        }
        visited.insert(p);
        for (const T& fr : friends.successors(p))
        {
            countSources[fr] += 1;
            if (visited.count(fr) == 0) {
                bfs.push(fr);
            }
        }
    }
    // find person with most sources
    int maxCount = 0;
    for (auto count : countSources) {
        if (count.second > maxCount) {
            maxCount = count.second;
            mostSources = count.first;
        }
    }
    // how many people know
    return visited.size();
}
int main()
{
    Graph<int> g;
    g.addEdge(15, 15);
    g.addEdge(15, 7);
    g.addEdge(15, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 7);
    g.addEdge(7, 15);
    g.addEdge(7, 3);

    cout << "Hello world!" << endl;
    return 0;
}
