#include <iostream>
using namespace std;

//another function to get largest value using max function

int findLargest2(int a,int b,int c){
    int ans=max(a,max(b,c));
    return ans;
}


// Function to find the largest of three numbers
int findLargest(int a, int b, int c) {
    int largest;
    if(a>=b && a>=c){
        largest = a;
    }
    else if (b>=a && b>=c){
        largest = b;
    }
    else{
        largest = c;
    }
    return largest; 
}

int main() {
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    int largest = findLargest2(num1, num2, num3);
    cout << "The largest number is: " << largest << endl;

    return 0;
}
