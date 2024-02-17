#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu options
void displayMenu() {
    cout << "\n===== To-Do List Manager =====\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "===============================\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> tasks; // Vector to store tasks
    int choice;
    string task;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Add Task
                cout << "Enter the task: ";
                cin.ignore(); // Ignore the newline character left in the input buffer
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added successfully!\n";
                break;
            case 2: // View Tasks
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                } else {
                    cout << "Tasks:\n";
                    for (int i = 0; i < tasks.size(); ++i) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }
                break;
            case 3: // Delete Task
                if (tasks.empty()) {
                    cout << "No tasks available to delete.\n";
                } else {
                    int index;
                    cout << "Enter the task number to delete: ";
                    cin >> index;
                    if (index >= 1 && index <= tasks.size()) {
                        tasks.erase(tasks.begin() + index - 1);
                        cout << "Task deleted successfully!\n";
                    } else {
                        cout << "Invalid task number!\n";
                    }
                }
                break;
            case 4: // Exit
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

