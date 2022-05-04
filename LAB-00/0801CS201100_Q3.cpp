#include <bits/stdc++.h>
using namespace std;

class List
{
public:
    int size;
    int getNth(int arr[], int n)
    {
        return arr[n - 1];
    }
    int *insertStart(int arr[], int n, int k, int position)
    {
        n++;
        position = 1;
        for (size_t i = n; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = k;
        size++;
        return arr;
    }
    int *insertEnd(int arr[], int n, int k, int position)
    {
        n++;
        position = n;
        for (size_t i = n; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = k;
        size++;
        return arr;
    }
    int *insertK(int arr[], int n, int k, int position)
    {
        n++;
        for (size_t i = n; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = k;
        size++;
        return arr;
    }
    int *removeK(int arr[], int n, int position)
    {
        n--;
        for (size_t i = position - 1; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return arr;
    }
    int getSize(int arr[])
    {
        return size;
    }
};

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array values: \n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int choice;
    List l1;
    l1.size = n;
    while (choice != 7)
    {
        cout << "What will you like to perform:\n1. Get the kth element form array.\n2. Insert a new element at beginning.\n3. Insert a new element at the end.\n4. Insert a new element at a position.\n5. Remove the element at kth position.\n6. Get the size of the array\n7. Exit the program.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int k1;
            cout << "Enter the value of k: ";
            cin >> k1;
            cout << l1.getNth(arr, k1) << "\n";
            break;
        case 2:
            int k2;
            cout << "Enter the value of new element: ";
            cin >> k2;
            l1.insertStart(arr, n, k2, 1);
            n++;
            for (size_t i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            break;
        case 3:
            int k3;
            cout << "Enter the value of new element: ";
            cin >> k3;
            l1.insertEnd(arr, n, k3, n + 1);
            n++;
            for (size_t i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            break;
        case 4:
            int k4, position;
            cout << "Enter the value of new element: ";
            cin >> k4;
            cout << "Position where you want it to be: ";
            cin >> position;
            l1.insertK(arr, n, k4, position);
            n++;
            for (size_t i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            break;
        case 5:
            int k5;
            cout << "Enter the value of k: ";
            cin >> k5;
            l1.removeK(arr, n, k5);
            n--;
            for (size_t i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            break;
        case 6:
            cout << "Length of array is: " << l1.getSize(arr) << "\n";
            for (size_t i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
            break;
        }
    }
    return 0;
}