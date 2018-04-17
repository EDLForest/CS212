#include "sorting.h"


template <typename T>
void printArr( T(&arr)[ASIZE]){
    for(int i = 0; i < ASIZE; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <typename T>
void doSorting( T(&arr)[ASIZE]){
    printArr(arr);
    sorting::SORT(arr);
    printArr(arr);
    cout << endl;
}

int main (){
    int intArr[ASIZE];
    float floatArr[ASIZE];
    double doubleArr[ASIZE];

    //reading from the test file
    ifstream inFile;
    inFile.open("sortin.txt");

    int i = 0;
    //While the file stream still have more data
    while(inFile >> intArr[i]){
        i++;
        if(i == ASIZE)
            break;
    }

    for(int i = 0; i < ASIZE; i++){
        floatArr[i] = (float)intArr[i];
        doubleArr[i] = (double)intArr[i];
    }

    doSorting(intArr);
    doSorting(floatArr);
    doSorting(doubleArr);



    return 0;
}
