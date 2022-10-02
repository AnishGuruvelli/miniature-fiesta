// Write a program to reverse an array or string
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include <iostream>

using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // or
    /*
    if (start >= end)
    return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
    */
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    reverseArray(arr, 0, size - 1);

    cout << "Reversed array is: ";

    printArray(arr, size);

    return 0;
}

/*
or
Stack-based Approach: Follow the steps below to solve the problem:

    Initialize a Stack to store the array elements.
    Traverse the array and push all the array elements into the stack.
    >Pop the elements from the stack and insert into the array.
    Finally, print the array.

    Below is the implementation of the above approach:
*/

/*
for (int i = 0; i < n; i++) {

        // Insert arr[i] into the stack
        push(stack, arr[i]);
    }

    // Reverse the array elements
    for (int i = 0; i < n; i++) {

        // Update arr[i]
        arr[i] = pop(stack);
    }

    // Print array elements
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


*/