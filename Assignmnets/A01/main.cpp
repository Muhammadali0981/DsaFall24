#include <iostream>
#include <string>
#include <ticket.h>
#include <Agent.h>
#include <ticketSystem.h>

using namespace std;

int main() {
    TicketSystem ticketSystem;
    AgentManager agentManager;
    ticketlist ticketL;
    
    int choice;
    do {
        cout << "\nTicket Management System\n";
        cout << "1. Add Agent\n";
        cout << "2. Add Ticket\n";
        cout << "3. Assign Ticket to Agent\n";
        cout << "4. View Agents\n";
        cout << "5. View Pending Tickets\n";
        cout << "6. View Resolution Logs\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int agentID;
                string name;
                cout << "Enter Agent ID: ";
                cin >> agentID;
                cout << "Enter Agent Name: ";
                cin.ignore();
                getline(cin, name);
                agentManager.addAgent(agentID, name);
                break;
            }
            case 2: {
                int ticketID, priority;
                string customerName, description, status;
                cout << "Enter Ticket ID: ";
                cin >> ticketID;
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, customerName);
                cout << "Enter Priority (1-5): ";
                cin >> priority;
                cout << "Enter Description: ";
                cin.ignore();
                getline(cin, description);
                status = "Open"; // New tickets start as open by default
                
                Ticket newTicket(ticketID, customerName, priority, description, status);
                ticketL.insertAtEnd(newTicket);
                ticketSystem.addTicketToQueue(newTicket);
                break;
            }
            case 3: {
                if (ticketL.findbyid(1) != nullptr) { // Check if tickets exist
                    ticketL.sort_by_priority(); // Sort by priority before assigning
                    Agent* availableAgent = agentManager.getAvailableAgent();
                    if (availableAgent != nullptr) {
                        Ticket* ticket = ticketL.findbyid(ticketL.head->data.ticketID);
                        if (ticket) {
                            agentManager.assignTicketToAgent(ticket);
                            ticketSystem.logClosedTicket(*ticket);
                        }
                    } else {
                        cout << "No available agents to assign tickets.\n";
                    }
                } else {
                    cout << "No tickets available to assign.\n";
                }
                break;
            }
            case 4: {
                agentManager.displayAgents();
                break;
            }
            case 5: {
                cout << "Pending Tickets:\n";
                ticketSystem.pendingTickets.display();
                break;
            }
            case 6: {
                cout << "Resolution Logs:\n";
                ticketSystem.viewLogs();
                break;
            }
            case 0:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
