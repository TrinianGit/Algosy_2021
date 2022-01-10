#include "BinaryTree.hpp"

using namespace std;

int main (int argn, char* argv[]){
    int a;
    cin >> a;
    BinaryTree BST = BinaryTree();
    while (cin >> a){
        BST.insert(a);
    }
    cout << BST.size() << " " << BST.depth() << " " << BST.minimum() << " " << BST.maximum() << endl;
    BST.preorder();
    for (int i=1; i < 10; i++){
        if (BST.search(i) != nullptr){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl; 
        }
    }
}