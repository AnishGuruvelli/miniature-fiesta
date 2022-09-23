// Write a program to reverse an array or string
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include<iostream> 

using namespace std; 

void reverseArray(int arr[], int start, int end) {
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}   

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<< endl;
}
 
int main() { 

    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    
    reverseArray(arr, 0, size-1);

    cout<< "Reversed array is: ";

    printArray(arr, size);

    return 0;
}

