#include <iostream>
using namespace std;

int main() {
    const int max_emp = 100;
    const int max_name = 1000; // Maximum length of all names combined
    int size;

    int id[100];
    float sal[100] = { 0 };
    int exp[100] = { 0 };

    char names[1000]; // 1D array for all names
    int name_start[100]; // Starting index of each name in the names array
    int name_len[100] = { 0 }; // Length of each name

    // Input: Number of employees
    cout << "Enter the number of employees (up to 100): ";
    cin >> size;

    if (size < 0 || size > max_emp) {
        cout << "Invalid number of employees!" << endl;
        return 1;
    }

    int current_name_index = 0; // Tracks the next free position in the names array
    float t_Salary = 0; // To calculate the total salary of all employees
    int above_100 = 0; // To count employees earning more than 100,000
    int highest = 0; // To track the employee with the highest salary

    // Input employee details
    for (int i = 0; i < size; i++) {
        cout << endl << "Enter details for employee " << i + 1 << ": " << endl;

        // Input ID

        id:
        do
        {
            cout << "ID: ";
            cin >> id[i];
            if (id[i] < 0)
            {
                cout << "Invild ID" << endl;
            }
        } while (id[i] < 0);

        for (int j = 0; j < size; j++)
        {
            if (id[i] == id[j] && i != j)
            {
                cout << "ID is already registered" << endl;
                goto id;
            }
        }

        // Input Name
        cout << "Name: ";
        cin.ignore(); // Clear the input buffer
        name_start[i] = current_name_index; // Store the starting index for this name
        char ch;
        int length = 0;
        while ((ch = cin.get()) != '\n' && length < max_name - current_name_index - 1) {
            names[current_name_index++] = ch;
            length++;
        }
        names[current_name_index++] = '\0'; // Null-terminate the name
        name_len[i] = length;

        // Input Salary with validation
        do {
            cout << "Salary (30,000 - 200,000): ";
            cin >> sal[i];
            if (sal[i] < 30000 || sal[i] > 200000) {
                cout << "Invalid salary! Please try again.\n";
            }
        } while (sal[i] < 30000 || sal[i] > 200000);

        // Update total salary and check for employees earning above 100,000
        t_Salary += sal[i];
        if (sal[i] > 100000) {
            above_100++;
        }

        // Update highest salary
        if (sal[i] > sal[highest]) {
            highest = i;
        }

        // Input Years of Experience
        cout << "Years of Experience: ";
        cin >> exp[i];
    }

    // Display Employee Records in Original Order
    cout << "\nEmployee Records (Original Order):\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << id[i]
            << ", Name: ";
        for (int j = 0; j < name_len[i]; j++) {
            cout << names[name_start[i] + j];
        }
        cout << ", Salary: " << sal[i]
            << ", Experience: " << exp[i] << " years\n";
    }

    // Reverse traversal
    cout << "\nTraversing in reverse order:\n";
    for (int i = size - 1; i >= 0; i--) {
        cout << "ID: " << id[i]
            << ", Name: ";
        for (int j = 0; j < name_len[i]; j++) {
            cout << names[name_start[i] + j];
        }
        cout << ", Salary: " << sal[i]
            << ", Experience: " << exp[i] << " years\n";
    }

    // Total salary, count of employees earning more than 100,000, and highest salary
    cout << "\nTotal salary of all employees: " << t_Salary;
    cout << "\nNumber of employees earning more than 100,000: " << above_100;
    cout << "\nEmployee with the highest salary: ";
    cout << &names[name_start[highest]] << " (" << sal[highest] << ")\n";

    // Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (id[j] > id[j + 1]) {
                // Swap IDs
                int tempID = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempID;

                // Swap Salaries
                float tempSalary = sal[j];
                sal[j] = sal[j + 1];
                sal[j + 1] = tempSalary;

                // Swap Experience
                int tempExp = exp[j];
                exp[j] = exp[j + 1];
                exp[j + 1] = tempExp;

                // Swap Name Indices and Lengths
                int tempStart = name_start[j];
                name_start[j] = name_start[j + 1];
                name_start[j + 1] = tempStart;

                int tempLength = name_len[j];
                name_len[j] = name_len[j + 1];
                name_len[j + 1] = tempLength;
            }
        }
    }

    // Sorted Employee Records
    cout << "\nSorted Employee Records:\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << id[i]
            << ", Name: ";
        for (int j = 0; j < name_len[i]; j++) {
            cout << names[name_start[i] + j];
        }
        cout << ", Salary: " << sal[i]
            << ", Experience: " << exp[i] << " years\n";
    }

    // Linear Search
    cout << "\nEnter an Employee ID to search (linear search): ";
    int searchID;
    cin >> searchID;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (id[i] == searchID) {
            cout << "Result: Name: " << &names[name_start[i]]
                << ", Salary: " << sal[i]
                << ", Experience: " << exp[i] << " years\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found.\n";
    }

    // Binary Search
    cout << "\nEnter an Employee ID to search (binary search): ";
    cin >> searchID;
    int low = 0, high = size - 1;
    found = false;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (id[mid] == searchID) {
            cout << "Result: Name: " << &names[name_start[mid]]
                << ", Salary: " << sal[mid]
                << ", Experience: " << exp[mid] << " years\n";
            found = true;
            break;
        }
        else if (id[mid] < searchID) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if (!found) {
        cout << "Employee not found.\n";
    }

    // String Manipulation
    cout << "\nString Manipulation (Name Analysis):\n";
    for (int i = 0; i < size; i++) {
        int vowels = 0;
        cout << "Name: ";
        for (int j = 0; j < name_len[i]; j++) {
            char ch = names[name_start[i] + j];
            cout << ch;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            }
        }
        cout << ", Vowels: " << vowels << ", Uppercase: ";
        for (int j = 0; j < name_len[i]; j++) {
            char ch = names[name_start[i] + j];
            if (ch >= 'a' && ch <= 'z') {
                ch -= 32; // Convert to uppercase
            }
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
