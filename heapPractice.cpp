#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <vector>
#include <cstdlib>
#include "Heap.h"
using namespace std;

int main()
{
    string str = "";
    double temp = 0;
        
    Heap heap0;

    bool loop = true;

    cout<<"\nMenu:\na: add a value\ne: extract the top priority city\np: print the heap\ns: swap\nq: quit\n";
    char ch;
    while(loop)
    {            
        cout << "Enter a choice: ";
        cin >> ch;
        switch(ch)
        {
            case 'q':
                loop = false;
                break;
            case 'p':
                heap0.printHeap();
                break;      
            case 'e' :
            {
                City *c = heap0.extract();
                if(c == nullptr) {
                    cout << "There are no objects to extract.\n";
                }
                else {
                    cout << "Extracted " << *c << endl;;\
                    delete c;
                }
                break;
            }
            case 'a':
            {
                getline (cin,str);
                cout << "Enter a city to add " << endl;
                getline (cin,str);
                cout << "Enter a temperature " << endl;
                cin >> temp;
                cout << "Adding " << str << " with temperature " <<  temp << endl;
                City *c = new City(str, temp);
                heap0.addNode(c);
                break;
            }
            case 's': 
                cout << "Enter the first index to swap " << endl;
                int idx1,idx2;
                cin >> idx1;
                cout << "Enter the second index to swap " << endl;
                cin >> idx2;
                cout << "Swapping index " << idx1 << " with " << idx2 << endl;
                heap0.swap(idx1,idx2);
                //getline (cin,str); // clear buffer
                break; 

        }
    }
    
    return 0;
}
