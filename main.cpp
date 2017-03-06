#include "Test.h"
#include "BinaryNode.h"
#include <iostream>
#include <queue>
using namespace std;


map<char,string> mapa_global;


void print(BinaryNode* node)
{
    if(node == NULL)
        return;
    cout<<"V:"<<node->value<<" F:"<<node->frequency<<" LF:"<<node->left->frequency<<" RF:"<<node->right->frequency<<endl;
    print(node->left);
    print(node->right);
}



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

    cout<<endl;

    for (std::map<char,string>::iterator it=mapa_global.begin(); it!=mapa_global.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    cout<<endl;
    return mapa_global;
}

BinaryNode* findMin(queue<BinaryNode*> *q1,queue<BinaryNode*> *q2)
{
    BinaryNode* temp;
    // Step 3.a: If second queue is empty, dequeue from first queue
    if (q1->empty()) {
        temp = q2->front();
        q2->pop();
        return temp;
    }

    // Step 3.b: If first queue is empty, dequeue from second queue
    if (q2->empty()) {
        temp = q1->front();
        q1->pop();
        return temp;
    }

    // Step 3.c:  Else, compare the front of two queues and dequeue minimum
    if (q1->front()->frequency  < q2->front()->frequency ) {
        temp = q1->front();
        q1->pop();
        return temp;
    }

    temp = q2->front();
    q2->pop();
    return temp;
}



map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{


    queue<BinaryNode*> q1;
    queue<BinaryNode*> q2;
    BinaryNode *ni, *n1, *n2;

    for(int i=0;i<characters.size();i++)
        q1.push(new BinaryNode(characters[i], frequencies[i]));


    while(!(q1.empty() && q2.size()==1)) {

        //LEFT
        if (q1.empty()) {
            n1 = q2.front();
            q2.pop();
        } else if (q2.empty()) {
            n1 = q1.front();
            q1.pop();
        } else if ((q1.front()->frequency  < q2.front()->frequency) && (q1.front()->value != '$' && q2.front()->value == '$') ) {
            n1 = q1.front();
            q1.pop();
        } else {
            n1 = q2.front();
            q2.pop();
        }

        //RIGHT
        if (q1.empty()) {
            n2 = q2.front();
            q2.pop();
        } else if (q2.empty()) {
            n2 = q1.front();
            q1.pop();
        } else if ((q1.front()->frequency  < q2.front()->frequency) && (q1.front()->value != '$' && q2.front()->value == '$' )) {
            n2 = q1.front();
            q1.pop();
        } else {
            n2 = q2.front();
            q2.pop();
        }


        ni = new BinaryNode('$', n1->frequency + n2->frequency);
        ni->left = n1;
        ni->right = n2;

        cout<<"freq: "<<ni->frequency<<" left v:"<<ni->left->value<<" left f:"<<ni->left->frequency<<" right v:"<<ni->right->value<<" right f:"<<ni->right->frequency<<endl;
        q2.push(ni);
    }

    //print(q2.front());

    map<char,string> answer = getHuffmanCodes(q2.front());
    return answer;
}

int main ()
{

    test();
    return 0;
}
