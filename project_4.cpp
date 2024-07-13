#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::find_if

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks, const string &description);
void removeTask(vector<Task> &tasks, const string &description);

int main() {
    vector<Task> tasks;  // Vector to store tasks
    string description;  // Variable to store task description
    int choice;

    while (true) {
        // Display menu
        cout << "\nTo-Do List Manager:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                cout << "Enter task description to mark as completed: ";
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, description);
                markTaskCompleted(tasks, description);
                break;
            case 4:
                cout << "Enter task description to remove: ";
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, description);
                removeTask(tasks, description);
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to add a task
void addTask(vector<Task> &tasks, const string &description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully.\n";
}

// Function to view all tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
    } else {
        cout << "Tasks:\n";
        for (const auto &task : tasks) {
            cout << "- ";
            if (task.completed) {
                cout << "[Completed] ";
            } else {
                cout << "[Pending]   ";
            }
            cout << task.description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(),
                      [&description](const Task &task) { return task.description == description; });

    if (it != tasks.end()) {
        it->completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Task not found.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(),
                      [&description](const Task &task) { return task.description == description; });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Task not found.\n";
    }
}
