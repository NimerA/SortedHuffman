#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>
using namespace std;

class BinaryNode
{
public:
    BinaryNode* left;
    BinaryNode* right;
    char value;

    BinaryNode(char value);
};

#endif // BINARYNODE_H
