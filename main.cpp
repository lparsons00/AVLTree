#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <valarray>

#include "AVL_ADT.h"
#include "avlTree.h"

using namespace std;

//packing data for AVT
struct DATA{
    string key;
    int age;
};

void print(DATA ss){
    cout << ss.key <<" "<< ss.age << endl;
}

int main() {
    AvlTree<DATA, string> tree;
    DATA newItem;
    DATA dataItem;
    if(tree.AVL_Empty()){
        cout << "EMPTY TREE." << endl;
    }
    //read file
    string temp;
    ifstream test ("test2.txt");
    
    if(test.is_open()){
        while(test >> temp){
            //read word
            //cout << temp << endl;
            
            //search word in AVL
            if(tree.AVL_Retrieve(temp, dataItem)){
                dataItem.age = dataItem.age + 1;
                cout << "test::" << dataItem.age << " & "
                     << dataItem.key << endl;
            } else {
                dataItem.key = temp;
                dataItem.age = 1;
                tree.AVL_Insert(dataItem);
            }
        }
        test.close();
    }
    
    
    
    if(tree.AVL_Empty()){
        cout << "EMPTY TREE." << endl;
    }
    cout << "All nodes:---------------" << endl;
    tree.AVL_Traverse(print);
    cout << endl;
    
    
    return 0;
}

