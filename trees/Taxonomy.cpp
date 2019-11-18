#include "Taxonomy.h"
#include <string>
#include <vector>
#include <iostream>
Taxonomy::Taxonomy()
{
    root = new Node("Animalia");
}
void Taxonomy::deleteNode(Node* node)
{
    std::vector<Node*> children = node->children;
    delete node;
    for (Node* child : children)
    {
        deleteNode(child);
    }
}

Taxonomy& Taxonomy::addEntity(std::vector<std::string> path)
{
    if (path.size() == 0 || path[0] != root->name) {
        std::cerr << "Cannot add " << path[path.size() - 1] << " to kingdom " << path[0] << std::endl;
        return *this;
    }
    Node *currentLevel = root;
    for (auto it = path.begin() + 1; it != path.end(); ++it)
    {
        Node *next = currentLevel->findChild(*it);
        if (next == nullptr)
        {
            next = new Node(*it);
            currentLevel->children.push_back(next);
        }
        currentLevel = next;
    }
    return *this;
}

void Taxonomy::print(Node* node, std::vector<std::string>& path) const
{
    if (node->isLeaf())
    {
        for (auto category : path)
        {
            std::cout << category << "->";
        }
        std::cout << node->name << std::endl;
        return;
    }
    path.push_back(node->name);
    for (Node* child : node->children)
    {
        print(child, path);
    }
    path.pop_back();
}

void Taxonomy::print() const
{
    std::vector<std::string> path;
    print(root, path);
}

Taxonomy::~Taxonomy()
{
    deleteNode(root);
}
