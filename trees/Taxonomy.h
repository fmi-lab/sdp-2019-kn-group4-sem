#ifndef TAXONOMY_H
#define TAXONOMY_H

#include <string>
#include <vector>
#include <stack>
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
        class TaxonomyIterator
        {
            friend class Taxonomy;
            Taxonomy* taxonomy;
            std::stack<Node*> frames;
            TaxonomyIterator(Taxonomy* taxonomy): taxonomy(taxonomy)
            {
                if (taxonomy->root != nullptr) {
                    frames.push(taxonomy->root);
                    unwind();
                }
            }
            void unwind()
            {
                while (!frames.empty() && !frames.top()->isLeaf())
                {
                    Node* top = frames.top();
                    frames.pop();
                    for (Node* child : top->children)
                    {
                        frames.push(child);
                    }
                }
            }
        public:
            bool hasNext() const
            {
                return !frames.empty();
            }
            std::string getValue() const
            {
                if (frames.empty()) {
                    return "";
                }
                return frames.top()->name;
            }
            void next()
            {
                if (!frames.empty())
                {
                    frames.pop();
                    unwind();
                }
            }
        };
        Taxonomy();
        virtual ~Taxonomy();
        Taxonomy& addEntity(std::vector<std::string> path);
        void print() const;
        int countSpeciesWithTwoWords() const;
        TaxonomyIterator iterateLeaves() {
            return TaxonomyIterator(this);
        }
        void printPreOrder() const;
        void printPostOrder() const;
    private:
        int countSpeciesWithTwoWords(Node* node) const;
        void printPreOrder(Node*) const;
        void printPostOrder(Node*) const;
    protected:

    private:
        Node* root;
        void deleteNode(Node* node);
        void print(Node* node, std::vector<std::string>& path) const;
};

#endif // TAXONOMY_H
