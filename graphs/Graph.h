#ifndef GRAPH_H
#define GRAPH_H

#include<vector>
#include<unordered_map>

template <typename Vertex>
class Graph
{
    public:
        Graph() {}
        std::vector<Vertex> vertices() const
        {
            return successors.keys();
        }
        std::vector<Vertex> successors(const Vertex& v) const
        {
            return successors[v];
        }
        bool hasEdge(const Vertex& from, const Vertex& to) const
        {
            return std::find(
                             successors[from].begin(),
                             successors[from].end(),
                             to
                ) != successors[from].end();
        }
        void addVertex(const Vertex& v) {
            // does nothing if the key is already present
            successors.insert({v, std::vector<Vertex>()});
        }
        void addEdge(const Vertex& from, const Vertex& to)
        {
            addVertex(from);
            addVertex(to);
            successors[from].push_back(to);
        }
    protected:

    private:
        std::unordered_map<Vertex, std::vector<Vertex>> successors;
};

#endif // GRAPH_H
