//Demonstration of different sorting algorithms
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

template<class ItemType>
int findIndexOfLargest(const vector<ItemType>theArray, int size);

//function to generate random vector of size n
vector<int> getRandomVec(int n) {
    vector<int> v;
    srand(time(0));
    for(int i = 0; i< n; i++){
        v.push_back((rand()%100)+1);
    }
    return v;
}

//function to print out vector
void printVec(vector<int> v){
    cout << "[ ";
    for(auto elem : v){
        cout<<elem <<" ";
    }
    cout<<"]\n";
}

//insertion sort from https://www.geeksforgeeks.org/insertion-sort-using-c-stl/
void insertionSort(std::vector<int> v)
{
    vector<int> vec(v);
    for (auto it = vec.begin(); it != vec.end(); it++)
    {        
        // Searching the upper bound, i.e., first 
        // element greater than *it from beginning
        auto const insertion_point = 
                std::upper_bound(vec.begin(), it, *it);
          
        // Shifting the unsorted part
        std::rotate(insertion_point, it, it+1); 
        printVec(vec);      
    }
}


//selection sort from sort package
template<class ItemType>
void selectionSort(vector<ItemType> v, int n)
{
    vector<ItemType> theArray(v);
   // last = index of the last item in the subarray of items yet
   //        to be sorted;
   // largest = index of the largest item found
   for (int last = n - 1; last >= 1; last--)
   {
      // At this point, theArray[last+1..n-1] is sorted, and its 
      // entries are greater than those in theArray[0..last].
      // Select the largest entry in theArray[0..last]
      int largest = findIndexOfLargest(theArray, last+1);
      
      // Swap the largest entry, theArray[largest], with
      // theArray[last]
      std::swap(theArray[largest], theArray[last]);
      printVec(theArray);
   }  // end for
}  // end selectionSort

template<class ItemType>
int findIndexOfLargest(const vector<ItemType> theArray, int size)
{
   int indexSoFar = 0; // Index of largest entry found so far
   for (int currentIndex = 1; currentIndex < size; currentIndex++)
   {
      // At this point, theArray[indexSoFar] >= all entries in
      // theArray[0..currentIndex - 1]
      if (theArray[currentIndex] > theArray[indexSoFar])
         indexSoFar = currentIndex;
   }  // end for
   return indexSoFar; // Index of largest entry
}  // end findIndexOfLargest

//shellSort from sorting package
void shellSort(vector<int> v, int n)
{
    vector<int> theArray(v);
   for (int h = n / 2; h > 0; h = h / 2)
   {
      for (int unsorted = h; unsorted < n; unsorted++)
      {
         int nextItem = theArray[unsorted];
         int loc = unsorted;
         while ( (loc >= h) && (theArray[loc - h] > nextItem) )
         {
            theArray[loc] = theArray[loc - h];
            loc = loc - h;
         } // end while
         theArray[loc] = nextItem;
         printVec(theArray);
      }  // end for
   }  // end for
}  // end shellSort

//Bubble sort code obtained from sorting package
void bubbleSort(const vector<int> v, int n)
{
    vector<int> theArray(v);
    
   bool sorted = false; // False when swaps occur
   int pass = 1;
   while (!sorted && (pass < n))
   {
      // At this point, theArray[n+1-pass..n-1] is sorted
      // and all of its entries are > the entries in theArray[0..n-pass]
      sorted = true; // Assume sorted
      for (int index = 0; index < n - pass; index++)
      {
         // At this point, all entries in theArray[0..index-1]
         // are <= theArray[index]
         int nextIndex = index + 1;
         if (theArray[index] > theArray[nextIndex])
         {
            // Exchange entries
            std::swap(theArray[index], theArray[nextIndex]);
            printVec(theArray);
            sorted = false; // Signal exchange
         } // end if
      }  // end for
      pass++;
   }  // end while
   printVec(theArray);
   
}  // end bubbleSort

//merge helper code from https://www.bogotobogo.com/Algorithms/mergesort.php
vector<int> merge(vector<int> left, vector<int> right)
{
   vector<int> result;
   while ((int)left.size() > 0 || (int)right.size() > 0) {
      if ((int)left.size() > 0 && (int)right.size() > 0) {
         if ((int)left.front() <= (int)right.front()) {
            result.push_back((int)left.front());
            left.erase(left.begin());
         } 
   else {
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
      }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
      }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
               result.push_back(right[i]);
            break;
      }
   }
   return result;
}

//mergeSort code from https://www.bogotobogo.com/Algorithms/mergesort.php
vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;
 
   vector<int> left, right, result;
   int middle = ((int)m.size()+ 1) / 2;
 
   for (int i = 0; i < middle; i++) {
      left.push_back(m[i]);
   }

   for (int i = middle; i < (int)m.size(); i++) {
      right.push_back(m[i]);
   }
 
   left = mergeSort(left);
   cout <<"left sub array: ";
   printVec(left);
   right = mergeSort(right);
   cout <<"right sub array: ";
   printVec(right);
   result = merge(left, right);
    cout <<"merged array: ";
    printVec(result);
   return result;
}

int main(){
    auto v = getRandomVec(11);
    cout<<"Random Vector:";
    printVec(v);

    cout<<"\nBegin Insertion Sort: ";
    printVec(v);
    insertionSort(v);
    cout<<"End Insertion Sort\n";

    cout<<"\nBegin Selection Sort: ";
    printVec(v);
    selectionSort(v,11);
    cout<< "End Selection Sort\n";

    cout<<"\nBegin Shell Sort: ";
    printVec(v);
    shellSort(v,11);
    cout<<"End Shell Sort\n";

    cout<<"\nBegin Bubble Sort: ";
    printVec(v);
    bubbleSort(v,11);
    cout<<"End Bubble sort\n";

    cout<<"\nBegin Merge Sort: ";
    printVec(v);
    mergeSort(v);
    cout<<"End Merge Sort\n";
    return 0;
}