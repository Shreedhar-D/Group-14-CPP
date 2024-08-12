#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* arr;
    int size;

public:
    Vector(int size) {//Construcutor
        this->size = size;
        arr = new T[size];
    }

    ~Vector() {//Destrucutor
        delete[] arr;
    }

    void inputVector() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    T findSmallest() {
        T smallest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        return smallest;
    }

    bool searchElement(T element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }

    T findAverage() {
        T sum = arr[0];
        for (int i = 1; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
    }

    void displayVector() {
        cout << "Vector: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Vector<int> vec(5);
    vec.inputVector();
    vec.displayVector();

    int smallest = vec.findSmallest();
    cout << "Smallest element: " << smallest << endl;

    int element;
    cout << "Enter element to search: ";
    cin >> element;
    if (vec.searchElement(element)) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    int average = vec.findAverage();
    cout << "Average of elements: " << average << endl;

    return 0;
}
