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

int Taxonomy::countSpeciesWithTwoWords() const
{
    return countSpeciesWithTwoWords(root);
}

int Taxonomy::countSpeciesWithTwoWords(Node* node) const
{
    if (node->isLeaf()) {
            return 1;
        // return countSpaces(node->name) == 1 ? 1 : 0;
    }
    int total = 0;
    for (auto child : node->children)
    {
        total += this->countSpeciesWithTwoWords(child);
    }
    return total;
}
void Taxonomy::printPreOrder() const
{
    printPreOrder(root);
}
void Taxonomy::printPostOrder() const
{
    printPostOrder(root);
}
void Taxonomy::printPreOrder(Node* node) const
{
    std::cout << "'" << node->name <<"'" <<  " ";
    for (auto child : node->children) {
        printPreOrder(child);
    }
}
void Taxonomy::printPostOrder(Node* node) const
{
    for (auto child : node->children)
    {
        printPostOrder(child);
    }
    std::cout << "'" << node->name << "'" << " ";
}

Taxonomy::~Taxonomy()
{
    deleteNode(root);
}
