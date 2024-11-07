#include <iostream>
#include <ctime>
#include <cstdlib>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    BinarySearchTree<int> printBST;

    srand(time(0));

    cout << "Inserting 20 random numbers:\n";
    for (int i = 0; i < 20; i++)
        printBST.insert(rand() % 100 + 1);

    printBST.print();

    cout << "--------------------------------------\n";


    cout << "Inserting values: 10, 5, 15, 3, 7, 12, 18" << endl;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    bst.print();

    cout << "--------------------------------------\n";
    cout << "Testing search funciton\n";
    cout << "Searching for 5: " << (bst.search(5) ? "Found" : "Not Found") << endl;
    cout << "Searching for 50: " << (bst.search(50) ? "Found" : "Not Found") << endl;

    cout << "--------------------------------------\n";
    cout << "testing minimum and maximum functions\n";
    cout << "Minimum value is: " << bst.findMin() << endl;
    cout << "Maximum value is: " << bst.findMax() << endl;

    cout << "--------------------------------------\n";
    cout << "testing the size function\n";
    cout << "Number of nodes is: " << bst.size() << endl;

    cout << "---------------------------------------\n";
    cout << "testing remove funcition\n";
    cout << "Removing 3 (a leaf node)" << endl;
    bst.remove(3);
    cout << "Number of items after removing 3: " << bst.size() << endl;
    cout << "Removing 15 (a node with one child)" << endl;
    bst.remove(15);
    cout << "Number of items after removing 15: " << bst.size() << endl;
    cout << "Removing 10 (the root node)" << endl;
    bst.remove(10);
    cout << "Number of items after removing 10: " << bst.size() << endl;
    bst.print();

    cout << "Press Enter to exit\n";
    cin.ignore();
    //cin.get();

    return 0;
}
