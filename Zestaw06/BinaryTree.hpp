#ifndef _HPP_BINARYTREE
#define _HPP_BINARYTREE

#include <iostream>

struct Leaf{
    Leaf* Parent;
    int Value;
    Leaf* Left;
    Leaf* Right;
};


class BinaryTree{

    public:
        BinaryTree(){
            tree_size = 0;
            tree_depth = 0;
        }

        void insert(int x, Leaf* searched = nullptr, int depth = 1){
            if (core == nullptr){
                Leaf* new_leaf = new Leaf();
                new_leaf->Value = x;
                core = new_leaf;
                tree_size++;
                if (tree_depth < depth){
                    tree_depth = depth;
                }
            }
            else{
                if (searched == nullptr){
                    searched = core;
                }
                if (searched->Value > x){
                    if(searched->Left == nullptr){
                        Leaf* new_leaf = new Leaf();
                        new_leaf->Parent = searched;
                        new_leaf->Value = x;
                        searched->Left = new_leaf;
                        tree_size++;
                        if (tree_depth < depth + 1){
                            tree_depth = depth + 1;
                        }
                    }
                    else{
                        insert(x, searched->Left, depth+1);
                    }
                }
                else{
                    if(searched->Right == nullptr){
                        Leaf* new_leaf = new Leaf();
                        new_leaf->Parent = searched;
                        new_leaf->Value = x;
                        searched->Right = new_leaf;
                        tree_size++;
                        if (tree_depth < depth + 1){
                            tree_depth = depth + 1;
                        }
                    }
                    else{
                        insert(x, searched->Right, depth+1);
                    }
                }
            }
        }

        Leaf* searchRecursive(int x, Leaf* searched = nullptr){
            if (searched == nullptr){
                searched = core;
            }
            if (searched->Value > x){
                if(searched->Left == nullptr){
                    return nullptr;
                }
                else{
                    searchRecursive(x, searched->Left);
                }
            }
            else if (searched->Value == x){
                return searched;
            }
            else{
                if(searched->Right == nullptr){
                    return nullptr;
                }
                else{
                    searchRecursive(x, searched->Right);
                }
            }
        }

        Leaf* search(int x){
            Leaf* searched;
            for (searched = core; searched != nullptr; ){
                if (searched->Value > x){
                    searched = searched->Left;
                }
                else if (searched->Value == x){
                    return searched;
                }
                else{
                    searched = searched->Right;
                }
            }
            return searched;
        }

        int size(){
            return tree_size;
        }

        int minimum(){
            Leaf* searched;
            for (searched = core; searched->Left != nullptr; searched = searched->Left);
            return searched->Value;
        }

        int maximum(){
            Leaf* searched;
            for (searched = core; searched->Right != nullptr; searched = searched->Right);
            return searched->Value;
        }

        int depth(){
            return tree_depth;
        }

        void inorder(Leaf* searched = nullptr){
            if (searched == nullptr){
                searched = core;
            }
            if (searched->Left != nullptr){
                inorder(searched->Left);
            }
            std::cout << searched->Value << std::endl;
            if (searched->Right != nullptr){
                inorder(searched->Right);
            }
            return;
        }

        void preorder(Leaf* searched = nullptr){
            if (searched == nullptr){
                searched = core;
            }
            std::cout << searched->Value << std::endl;
            if (searched->Left != nullptr){
                preorder(searched->Left);
            }
            if (searched->Right != nullptr){
                preorder(searched->Right);
            }
        }

        void postorder(Leaf* searched = nullptr){
            if (searched == nullptr){
                searched = core;
            }
            if (searched->Left != nullptr){
                postorder(searched->Left);
            }
            if (searched->Right != nullptr){
                postorder(searched->Right);
            }
            std::cout << searched->Value << std::endl;
        }

    private:
        int tree_size;
        int tree_depth;
        Leaf* core = nullptr;

};


#endif