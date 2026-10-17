#include <iostream>
using namespace std;

struct Bus {
    int busNo;
    string source, destination;
    Bus* next;
};

Bus* head = NULL;

// Add Bus
void addBus() {
    Bus* newBus = new Bus;

    cout << "Enter Bus Number: ";
    cin >> newBus->busNo;

    cout << "Enter Source: ";
    cin >> newBus->source;

    cout << "Enter Destination: ";
    cin >> newBus->destination;

    newBus->next = NULL;

    if (head == NULL) {
        head = newBus;
    } else {
        Bus* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newBus;
    }

    cout << "Bus added successfully!\n";
}

// Display Buses
void displayBuses() {
    if (head == NULL) {
        cout << "No bus routes available.\n";
        return;
    }

    Bus* temp = head;

    cout << "\nBus Routes:\n";
    while (temp != NULL) {
        cout << "Bus No: " << temp->busNo
             << " | " << temp->source
             << " -> " << temp->destination << endl;

        temp = temp->next;
    }
}

// Search Bus
void searchBus() {
    int no;
    cout << "Enter Bus Number to Search: ";
    cin >> no;

    Bus* temp = head;

    while (temp != NULL) {
        if (temp->busNo == no) {
            cout << "Bus Found!\n";
            cout << "Route: " << temp->source
                 << " -> " << temp->destination << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Bus not found.\n";
}

// Delete Bus
void deleteBus() {
    int no;
    cout << "Enter Bus Number to Delete: ";
    cin >> no;

    Bus* temp = head;
    Bus* prev = NULL;

    while (temp != NULL && temp->busNo != no) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Bus not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Bus deleted successfully!\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n===== BUS ROUTE MANAGEMENT =====\n";
        cout << "1. Add Bus\n";
        cout << "2. Display Buses\n";
        cout << "3. Search Bus\n";
        cout << "4. Delete Bus\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBus();
                break;

            case 2:
                displayBuses();
                break;

            case 3:
                searchBus();
                break;

            case 4:
                deleteBus();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
