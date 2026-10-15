#include <iostream>
#include <string>
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

    // Check for duplicate bus number
    if (head != NULL) {
        Bus* temp = head;
        do {
            if (temp->busNo == newBus->busNo) {
                cout << "Bus number already exists!\n";
                delete newBus;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    cout << "Enter Source: ";
    cin >> newBus->source;

    cout << "Enter Destination: ";
    cin >> newBus->destination;

    if (head == NULL) {
        head = newBus;
        newBus->next = head;
    } else {
        Bus* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newBus;
        newBus->next = head;
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

    do {
        cout << "Bus No: " << temp->busNo
             << " | " << temp->source
             << " -> " << temp->destination << endl;

        temp = temp->next;
    } while (temp != head);
}

// Search Bus
void searchBus() {
    if (head == NULL) {
        cout << "No bus routes available.\n";
        return;
    }

    int no;
    cout << "Enter Bus Number to Search: ";
    cin >> no;

    Bus* temp = head;

    do {
        if (temp->busNo == no) {
            cout << "Bus Found!\n";
            cout << "Route: " << temp->source
                 << " -> " << temp->destination << endl;
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Bus not found.\n";
}

// Delete Bus
void deleteBus() {
    if (head == NULL) {
        cout << "No bus routes available.\n";
        return;
    }

    int no;
    cout << "Enter Bus Number to Delete: ";
    cin >> no;

    Bus* curr = head;
    Bus* prev = NULL;

    // Find the bus
    do {
        if (curr->busNo == no)
            break;

        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->busNo != no) {
        cout << "Bus not found.\n";
        return;
    }

    // Delete the only node
    if (curr->next == curr) {
        head = NULL;
    }
    // Delete the first node
    else if (curr == head) {
        Bus* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }
    // Delete another node
    else {
        prev->next = curr->next;
    }

    delete curr;
    cout << "Bus deleted successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== CIRCULAR BUS ROUTE MANAGEMENT =====\n";
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
