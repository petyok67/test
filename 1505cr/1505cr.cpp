#include <iostream>
#include <list>

using namespace std;

//function to remove even numbers from a list using iterators
void removeEvenNumbers(list<int>& numbers) {
    //сheck if the initial list contains any negative numbers
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it < 0) {
            throw "domain Error: the list contains a negative number.";
        }
    }

    //iterate through the list and remove all even numbers
    for (auto it = numbers.begin(); it != numbers.end(); ) {
        if (*it % 2 == 0) {
            // erase() removes the element and returns an iterator to the next element
            it = numbers.erase(it);
        }
        else {
            //only increment the iterator if no element was erased
            ++it;
        }
    }
}

int main() {
    list<int> userList;
    int number;

    cout << "enter integers separated by space (then press q to continue): ";

    //read numbers from the terminal until the user enters a non-integer (like 'q')
    while (cin >> number) {
        userList.push_back(number);
    }

    try {
        removeEvenNumbers(userList);

        cout << "modified list (no evens): ";
        for (int num : userList) {
            cout << num << " ";
        }
        cout << endl;

    }
    catch (const char* msg) {
        // Catching the const char* exception
        cout << "Error: " << msg << endl;
    }

    return 0;
}