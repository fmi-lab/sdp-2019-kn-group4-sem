#include <iostream>
#include <sstream>
#include <string>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d, Node* l = nullptr, Node* r = nullptr): data(d), left(l), right(r) { }
};

string serialize(Node* node) {
    if (node == nullptr) {
        return "()";
    }
    stringstream res;
    res << "(" << node->data << " " <<
            serialize(node->left) << " " <<
            serialize(node->right) << ")";
    return res.str();
}

Node* deserialize(string& s) {
    if (s[0] != '(') {
        cerr << "expected ( at pos " << 0 << endl;
        return nullptr;
    }
    if (s[1] == ')')
    {
        s = s.substr(2);
        return nullptr;
    }
    stringstream ss;
    ss << s;
    // ignore the (
    ss.get();
    Node* result = new Node(0);
    ss >> result->data;
    // remove space after data
    ss.get();
    getline(ss, s);
    result->left = deserialize(s);
    // remove space after left
    s = s.substr(1);
    result->right = deserialize(s);
    // remove closing )
    if (s[0] != ')') {
        cerr << "expected )" << endl;
    }
    s = s.substr(1);

    return result;
}

int main()
{
    Node* d = new Node{
        1,
        new Node(2,
                 new Node(3),
                 new Node(4)),
        new Node(5,
                 nullptr,
                 new Node(6))
    };
    string s = serialize(d);
    cout << "Serialized: " << s << endl;
    Node* copy = deserialize(s);
    cout << "Serialized copy: " << serialize(copy) << endl;
    return 0;
}
