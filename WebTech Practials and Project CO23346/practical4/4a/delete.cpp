#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Template for Bubble Sort
template <typename T>
void Raman_BubbleSort(T array[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (array[j] < array[j - 1])
            {
                T temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

// Template for Insertion Sort
template <typename T>
void Raman_InsertionSort(T array[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        T k = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > k)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = k;
    }
}

// Template for Selection Sort
template <typename T>
void Raman_SelectionSort(T array[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int middle = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (array[j] < array[middle])
            {
                middle = j;
            }
        }

        T temp = array[middle];
        array[middle] = array[i];
        array[i] = temp;
    }
}

// Template for Quick Sort
template <typename T>
void Raman_QuickSort(T array[], int left, int right)
{
    if (left < right)
    {
        T pivot = array[right];
        int i = left - 1;
        for (int j = left; j < right; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        T temp = array[i + 1];
        array[i + 1] = array[right];
        array[right] = temp;

        Raman_QuickSort(array, left, i);
        Raman_QuickSort(array, i + 2, right);
    }
}

// Template for Linear Search
template <typename T>
int Raman_LinearSearch(T array[], int n, const T &item)
{
    for (int i = 0; i < n; ++i)
    {
        if (array[i] == item)
        {
            return i;
        }
    }
    return -1;
}

// Template for Binary Search
template <typename T>
int Raman_BinarySearch(T array[], int left, int right, const T &item)
{
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (array[middle] == item)
            return middle;
        if (array[middle] < item)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

// Template for printing the array
template <typename T>
void Raman_Print(T array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Template for loading data from file
template <typename T>
int Raman_Load(T array[], int &n, const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Could not open file " << filename << endl;
        return 0;
    }

    n = 0;
    while (file >> array[n])
    {
        ++n;
    }

    file.close();
    return 1;
}

// Template function to get the maximum value in the array
template <typename T>
T Raman_getMax(T array[], int n)
{
    T max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Template function for counting sort, which sorts based on the digit represented by exp (10^0, 10^1, 10^2, etc.)
template <typename T>
void Raman_countingSort(T array[], int n, T exp)
{
    T output[n];         // Output array
    int count[10] = {0}; // Initialize count array to hold 10 digits (0 to 9)

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;

    // Update count[i] so it contains the actual position of this digit in the output array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array back to the original array
    for (int i = 0; i < n; i++)
        array[i] = output[i];
}

// Template function for Radix Sort
template <typename T>
void Raman_RadixSort(T array[], int n)
{
    // Get the maximum number to know the number of digits
    T max = Raman_getMax(array, n);

    // Perform counting sort for every digit. The exp is 10^i (i = 0 for the least significant digit)
    for (T exp = 1; max / exp > 0; exp *= 10)
        Raman_countingSort(array, n, exp);
}

int main()
{
    // Choose between integer or string array based on the file
    cout << "\nChoose the file for operation:";
    cout << "\n1. Do operation on Integer Array file";
    cout << "\n2. Do operation on Character Array file";
    cout << "\nEnter your Choice: ";

    int choice;
    cin >> choice;

    int n = 0; // Size of the array

    if (choice == 1)
    {
        // Integer array case
        int array[100]; // Declare integer array
        if (Raman_Load(array, n, "input.txt"))
        {
            cout << "Original Array: ";
            Raman_Print(array, n);

            // Perform sorting
            cout << "\nSorted array using Bubble Sort: ";
            Raman_BubbleSort(array, n);
            Raman_Print(array, n);

            cout << "\nSorted array using Insertion Sort: ";
            Raman_InsertionSort(array, n);
            Raman_Print(array, n);

            cout << "\nSorted array using Selection Sort: ";
            Raman_SelectionSort(array, n);
            Raman_Print(array, n);

            cout << "\nSorted array using Quick Sort: ";
            Raman_QuickSort(array, 0, n - 1);
            Raman_Print(array, n);

            // Perform Radix Sort (now using templates)
            cout << "\nSorted array using Radix Sort: ";
            Raman_RadixSort(array, n);
            Raman_Print(array, n);

            // Perform searching
            cout << "\nEnter the item to search: ";
            int item;
            cin >> item;

            cout << "\nChoose the search method:";
            cout << "\n1. Linear Search";
            cout << "\n2. Binary Search";
            cout << "\nEnter your choice: ";

            int searchChoice;
            cin >> searchChoice;

            int index = -1;
            switch (searchChoice)
            {
            case 1:
                index = Raman_LinearSearch(array, n, item);
                if (index != -1)
                    cout << "Item found at index " << index << " using Linear Search." << endl;
                else
                    cout << "Item not found using Linear Search." << endl;
                break;
            case 2:
                index = Raman_BinarySearch(array, 0, n - 1, item);
                if (index != -1)
                    cout << "Item found at index " << index << " using Binary Search." << endl;
                else
                    cout << "Item not found using Binary Search." << endl;
                break;
            default:
                cout << "Invalid search method." << endl;
            }
        }
    }
    else if (choice == 2)
    {
        // String array case (does not support Radix Sort)
        string array[100]; // Declare string array
        if (Raman_Load(array, n, "string.txt"))
        {
            cout << "Original Array: ";
            Raman_Print(array, n);

            // Perform sorting
            cout << "\nSorted array using Bubble Sort: ";
            Raman_BubbleSort(array, n);
            Raman_Print(array, n);

            cout << "\nSorted array using Insertion Sort: ";
            Raman_InsertionSort(array, n);
            Raman_Print(array, n);

            cout << "\nSorted array using Selection Sort: ";
            Raman_SelectionSort(array, n);
            Raman_Print(array, n);

            cout << "\nSorted array using Quick Sort: ";
            Raman_QuickSort(array, 0, n - 1);
            Raman_Print(array, n);

            // Perform searching
            cout << "\nEnter the item to search: ";
            string item;
            cin >> item;

            cout << "\nChoose the search method:";
            cout << "\n1. Linear Search";
            cout << "\n2. Binary Search";
            cout << "\nEnter your choice: ";

            int searchChoice;
            cin >> searchChoice;

            int index = -1;
            switch (searchChoice)
            {
            case 1:
                index = Raman_LinearSearch(array, n, item);
                if (index != -1)
                    cout << "Item found at index " << index << " using Linear Search." << endl;
                else
                    cout << "Item not found using Linear Search." << endl;
                break;
            case 2:
                index = Raman_BinarySearch(array, 0, n - 1, item);
                if (index != -1)
                    cout << "Item found at index " << index << " using Binary Search." << endl;
                else
                    cout << "Item not found using Binary Search." << endl;
                break;
            default:
                cout << "Invalid search method." << endl;
            }
        }
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}