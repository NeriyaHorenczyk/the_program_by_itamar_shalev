#include <iostream>
#include "Stack.cpp"
#include "LinkedList.cpp"
#include "Queue.cpp"

using namespace std;

int main()
{
    cout << boolalpha;

    cout << "Choose which tests you want to run:\n";
    cout << "1 - stack\n" << "2 - list\n" << "3 - queue\n";

    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
            //stack tests
        {
            Stack<int> s;

            for (int i = 1; i <= 10; i++)
            {
                s.push(i);
            }

            cout << "The first item in the stack is: " << s.top() << endl;

            cout << "The size of the stack is: " << s.size() << endl;

            cout << "\nThe values in the stack are: \n";
            while (!s.isEmpty())
            {
                cout << s.pop() << endl;
            }


            cout << "\nIs the stack empty? " << s.isEmpty() << endl;
        }
        //break;
        case 2:
            //list tests
        {
            LinkedList<int> l;

            for (int i = 1; i <= 10; i++)
            {
                l.insert(i);
            }

            cout << "The size of the list is: " << l.size() << endl;

            cout << "\nThe values in the list are: \n";
            while (!l.isEmpty())
            {
                cout << l.pop() << endl;
            }

            cout << "\nIs the list empty? " << l.isEmpty() << endl;
        }
        //break;
        case 3:
            //queue tests
        {
            Queue<int> q;

            for (int i = 1; i <= 10; i++)
            {
                q.push(i);
            }

            cout << "The first item in the queue is: " << q.top() << endl;

            cout << "The size of the queue is: " << q.size() << endl;

            cout << "\nThe values in the queue are: \n";
            while (!q.isEmpty())
            {
                cout << q.pop() << endl;
            }


            cout << "\nIs the queue empty? " << q.isEmpty() << endl;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
        break;
    }
    return 0;
}
