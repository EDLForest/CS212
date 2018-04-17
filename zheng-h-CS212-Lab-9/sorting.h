#ifndef SORTING_H
#define SORTING_H

#include <cstdlib>
#include <fstream>
#include <iostream>

#define ASIZE 20

using namespace std;

class sorting{
public:
    void static SORT(int (&arr)[ASIZE]){
        //Implementing the Bubble sort
        cout << "Performing Bubble Sort" << endl;
        for (int i = 0; i < ASIZE; i++){
            for(int j = 0; j < ASIZE-i; j++){
                if (arr[j] > arr[j+1]){
                    //swap two value
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    void static SORT(float (&arr)[ASIZE]){
        //Implementing the Selection sort
        cout << "Performing Selection Sort" << endl;
        int minPos;
        float min;
        for(int i = 0; i < ASIZE; i++){
            minPos = i;
            min = arr[i];
            for(int j = i; j < ASIZE; j++){
                if (arr[j] < min){
                    min = arr[j];
                    minPos = j;
                }
            }
            //if the minPos did not change, then move on
            //other wise swap the two value
            if(minPos == i)
                continue;
            else{
                float temp = arr[i];
                arr[i] = arr[minPos];
                arr[minPos] = temp;
            }
        }
    }
    void static SORT(double (&arr)[ASIZE]){
        //Implementing the Insertion sort
        cout << "Performing Insertion Sort" << endl;
        //first element is automatically in the sorted portion
        for(int i = 1; i < ASIZE; i++){
            for(int j = i; j > 0; j--){
                //if the current element is less than its predeccesor
                //swap them. Else, this element is correctly sorted
                if(arr[j] < arr[j-1]){
                    double temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
                else
                    continue;
            }
        }
    }
};

#endif
