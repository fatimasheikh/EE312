// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"
#include "Song.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test1.txt");

    //BST_312<string> bst;
    BST_312<int> bst;
//    bst.insertItem("s");

    //string s;
    int s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    //cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    //s = "tree";
    s = 1;
    bst.deleteItem(s);
    print(bst.postOrderTraversal());
    cout << endl;
    //cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;

    cout << "Make empty" << endl;
    bst.makeEmpty();
    cout << "Post Order Traversal is " << endl;
    print(bst.postOrderTraversal());


}

/*
    Song s1("Waterloo", "ABBA", 10);
    Song s2("Toxic", "Britney Spears", 5);
    Song s3("Thriller", "Michael Jackson",11);

    BST_312<Song> bst;

    cout << "inserting ... " << s1.getTitle() << endl;
    bst.insertItem(s1);
    cout << "inserting ... " << s2.getTitle() << endl;
    bst.insertItem(s2);
    cout << "inserting ... " << s3.getTitle() << endl;
    bst.insertItem(s3);
*/
