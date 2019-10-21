#include "PermutationStream.h"
#include <vector>

PermutationStream::PermutationStream(
    std::vector<char> symbols,
    int variationSize): symbols(symbols), variationSize(variationSize)
{
    PermutationState initial;
    initial.targetSize = variationSize;
    for (int i = 0; i < symbols.size(); i++) {
        initial.used.push_back(false);
    }
    state.push(initial);
    unwind();
}

bool PermutationStream::hasNext() const {
    return !state.empty();
}

std::vector<char> PermutationStream::next() {
    if (!hasNext()) {
        return std::vector<char>();
    }
    PermutationState st = state.top();
    state.pop();
    unwind();
    return st.current;
}

void PermutationStream::unwind() {
    while (!state.empty() && !state.top().isComplete()) {
        PermutationState st = state.top();
        state.pop();
        for (int i = st.used.size() - 1; i >= 0; i--) {
            if (!st.used[i]) {
                PermutationState next(st);
                next.current.push_back(symbols[i]);
                next.used[i] = true;
                state.push(next);
            }
        }
    }
}
void PermutationStream::generateAll()
{
    PermutationState initial;
    for (int i = 0; i < symbols.size(); i++) {
        initial.used.push_back(false);
    }
    state.push(initial);

    while (!state.empty()) {
        PermutationState st = state.top();
        state.pop();
        if (st.isComplete()) {
            st.print();
        } else {
            for (int i = st.used.size() - 1; i >= 0; i--) {
                if (!st.used[i]) {
                    PermutationState next(st);
                    next.current.push_back(symbols[i]);
                    next.used[i] = true;
                    state.push(next);
                }
            }
        }
    }
}
