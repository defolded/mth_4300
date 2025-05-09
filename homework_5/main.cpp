#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <queue>
#include <unordered_map>


using namespace std;


// Problem 3
string preprocess(const string& input) {
    string result;
    for (char c : input) {
        if (isalpha(c)) {
            result += tolower(c);
        }
    }
    return result;
}

bool isPalindrome(const string& str) {
    string cleaned = preprocess(str);
    stack<char> s;

    for (char c : cleaned) {
        s.push(c);
    }

    for (char c : cleaned) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }

    return true;
}


// Problem 4
struct Customer {
    string name;
    int ticketNumber;
};

void addCustomer(queue<Customer>& q, int& ticketCounter) {
    Customer newCustomer;
    cout << "Enter customer name: ";
    getline(cin >> ws, newCustomer.name); // ws to ignore leading whitespace
    newCustomer.ticketNumber = ticketCounter++;
    q.push(newCustomer);
    cout << "Customer added with Ticket #" << newCustomer.ticketNumber << endl;
}

void serveCustomer(queue<Customer>& q) {
    if (q.empty()) {
        cout << "No customers to serve." << endl;
        return;
    }
    Customer served = q.front();
    q.pop();
    cout << "Serving " << served.name << " (Ticket #" << served.ticketNumber << ")" << endl;
}

void displayQueue(const queue<Customer>& q) {
    if (q.empty()) {
        cout << "No customers in the queue." << endl;
        return;
    }

    queue<Customer> temp = q;
    cout << "Current waiting customers:" << endl;
    while (!temp.empty()) {
        Customer c = temp.front();
        cout << "- " << c.name << " (Ticket #" << c.ticketNumber << ")" << endl;
        temp.pop();
    }
}


// Problem 5
bool isAnagram(const string& s, const string& t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }

    for (char c : t) {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0)
            return false;
        charCount[c]--;
    }

    return true;
}


int main() {
//    Problem 3
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

//    Problem 4
    queue<Customer> customerQueue;
    int ticketCounter = 1;
    int choice;

    do {
        cout << "\n--- Ticket Counter Menu ---\n";
        cout << "1. Add customer\n";
        cout << "2. Serve next customer\n";
        cout << "3. Display waiting customers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCustomer(customerQueue, ticketCounter);
                break;
            case 2:
                serveCustomer(customerQueue);
                break;
            case 3:
                displayQueue(customerQueue);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1-4." << endl;
        }
    } while (choice != 4);

//    Problem 5
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}