#include "Test.h"
#include "BinaryNode.h"
#include <iostream>
using namespace std;


map<char,string> mapa_global;

void recorrerArbol(BinaryNode* actual,string codigo)
{
    if(actual->value!=NULL)
    {
        mapa_global[actual->value] = codigo;
    }else
    {
        recorrerArbol(actual->left,codigo+"0");
        recorrerArbol(actual->right,codigo+"1");
    }
}

map<char,string> getHuffmanCodes(BinaryNode* huffman_tree)
{
    mapa_global.clear();

    recorrerArbol(huffman_tree,"");

    return mapa_global;
}



map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
    map<char,string> answer;
    return answer;
}

int main ()
{
    test();
    return 0;
}
