#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int rand_num = 5; // suppose the random number is 5
    // adding number counts you used for guessing
    int count = 1;
    cout << "Welcome to Number Guessing Game" << endl;
    // if you have to continue the game, then
    char game = true;
    // for getting y/n input
    char x;
    while (game == true){
        while (true){
            cout << "Guess a Number Between 1-10: ";
            cin >> num;
            if (num < 1 && num > 10){
                cout << "Please Enter in a valid range" << endl;
            }
            else if (num < rand_num){
                cout << "Too low! Try Again" << endl;
            }
            else if (num > rand_num){
                cout << "Too high! Try Again" << endl;
            }
            else{
                cout << "You got the correct Answer! in " << count << " attempt" << endl;
                break;
            }
            count = count + 1;
        }
        cout << "Do you want to continue.. y/n :  ";
        cin >> x;
        if (x == 'y'){
            game = true;
        }
        else{
            game = false;
            cout<<"Thanks for playing..";
        }
    }
    return 0;
}
