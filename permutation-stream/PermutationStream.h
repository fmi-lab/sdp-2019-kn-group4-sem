#ifndef PERMUTATIONSTREAM_H
#define PERMUTATIONSTREAM_H

#include <vector>
#include <stack>
#include <iostream>
struct PermutationState {
    int targetSize;
    std::vector<char> current;
    std::vector<bool> used;

    bool isComplete() const {
        return current.size() == targetSize;
    }
    void print() const {
        for (auto s : current) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
};

class PermutationStream
{
    public:
        PermutationStream(std::vector<char> symbols, int variationSize);
        bool hasNext() const;
        void generateAll();
        std::vector<char> next();
    protected:

    private:
        std::vector<char> symbols;
        std::stack<PermutationState> state;
        int variationSize;
        void unwind();
};

#endif // PERMUTATIONSTREAM_H
