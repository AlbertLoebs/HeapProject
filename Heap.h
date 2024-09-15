#include <iostream>
using namespace std;

static const int MAX_ITEMS = 20;

// Class to maintain the data for a City
// This class is complete, nothing for you to do here except to see what methods
// you have available. 
class City {
private:
    string name;            // The name of the city
    double averageTemp;     // The average temperature of the city
    
public:
    City(string name, double temp) {
        this->name = name;
        this->averageTemp = temp;
    }
    
    string getName() { return name; }
    double getTemperature() { return averageTemp; }
    
    friend ostream &operator<<( ostream &output, const City &c ) { 
         output << "City : " << c.name << ", Average Temp : " << c.averageTemp;
         return output;            
      }    
};

// Class to manage a minheap of City pointers prioritized by lowest
// average temperature
// Look for methods stating "Complete this method"
class Heap
{
public:    
   Heap() { 
       num = 0;  
   }

   // Given a node index, bubble it up the heap.
   // It is advised that you write this as a recursive function
   // The rules for bubble up are:
   //   if the node index is the root, there is nothing to do, just return.
   //   if the node value at the current index is less than the parent node's value
   //        swap the node with the parent (we want lower values at the top)
   //        call bubbleUp again using the index of the parent
   void bubbleUp(int idx) {
       if(idx == 0){
           return;
      }

    int parentIdx = parentLoc(idx);

    if(arr[idx]->getTemperature() < arr[parentIdx]->getTemperature()){
        swap(idx, parentIdx);
        bubbleUp(parentIdx);
    }

}

   // Add a City to the heap, maintaining the minheap structure
   void addNode(City *c)    
   { 
       if(num >= MAX_ITEMS){
           cout << "Cant add heap is full";
           return;
       }
       arr[num] = c;
       bubbleUp(num);
       num++;
   }

   // Given a node index, bubble it down the heap
   // It is advised that you write this as a recursive function
   // The rules for bubble down are:
   //   if the node at the given index has no children, there is nothing to do, return.
   //   find the lower value from idx's two children
   //   if the node value at the current index is greater than the lower of the two children
   //        swap the node with the lower of the two children
   //        call bubbleDown again using the new index of the swapped node
   void bubbleDown(int idx) {
    int current = idx;

    while (true) {
     int leftChild = leftChildLoc(current);
     int rightChild = rightChildLoc(current);
     int minIdx = current;

        if (leftChild < num && arr[leftChild]->getTemperature() < arr[minIdx]->getTemperature()) {
            minIdx = leftChild;
        }

        if (rightChild < num && arr[rightChild]->getTemperature() < arr[minIdx]->getTemperature()) {
            minIdx = rightChild;
        }

        if (minIdx != current) {
            swap(current, minIdx);
            current = minIdx;
            } else {
                break;
        }
    }
}


   // Remove the City with the minimum temperature from the heap and return a pointer to it
   // If the heap is empty, return nullptr
   City *extract()    
   {
       if(num == 0){
           return nullptr;
       }
    City *minCity = arr[0];
    
    swap(0, num - 1);
    num--;

    if(num > 0){
        bubbleDown(0);
    }
    
    return minCity;
}

   int retRootIndex()       { return(0); }

   int leftChildLoc(int i)  { return(2*i+1); }

   int rightChildLoc(int i) { return(2*i+2); }

   int parentLoc(int i)     { return((i-1)/2); }

   // Print the heap in level order
   void printHeap()          
   { 
       for (int i = 0; i < num; i++) {
            cout << *(arr[i])  << endl; 
       }
   }

   // Swap two items in the heap at the given indices      
   void swap(int idx1, int idx2) {
       City* temp = arr[idx1];
       arr[idx1] = arr[idx2];
       arr[idx2] = temp;
   }

   private:
      City *arr[MAX_ITEMS];
      int num;

};
