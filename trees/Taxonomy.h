#ifndef TAXONOMY_H
#define TAXONOMY_H

#include <string>
#include <vector>
struct Node
{
  std::string name;
  std::vector<Node*> children;
  Node(std::string name): name(name) { }
  bool isLeaf() const
  {
      return children.empty();
  }

  Node* findChild(std::string name) const
  {
      for (auto it = children.begin(); it != children.end(); ++it)
      {
          if ((*it)->name == name) {
            return *it;
          }
      }
      return nullptr;
  }
};
class Taxonomy
{
    public:
        Taxonomy();
        virtual ~Taxonomy();
        Taxonomy& addEntity(std::vector<std::string> path);
        void print() const;
    protected:

    private:
        Node* root;
        void deleteNode(Node* node);
        void print(Node* node, std::vector<std::string>& path) const;
};

#endif // TAXONOMY_H
