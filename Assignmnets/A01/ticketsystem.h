#include <Stack.h>
#include <queue.h>
#include <DynamicArray.h>
#include <ticket.h>
#include <Agent.h>

#ifndef TICKET_SYSTEM_H
#define TICKET_SYSEM_H

class TicketSystem {

public:
    Stack<string> resolutionLog; 
    Queue<Ticket> pendingTickets; 

    void logClosedTicket(const Ticket& ticket) {
        string logEntry = "Ticket ID " + to_string(ticket.ticketID) + " closed at " + ctime(&ticket.creationTime);
        resolutionLog.push(logEntry);
    }

    void addTicketToQueue(const Ticket& ticket) {
        pendingTickets.enqueue(ticket);
        cout << "Ticket ID " << ticket.ticketID << " added to the pending queue." << endl;
    }

    void viewLogs() {
        cout << "Resolution Log:" << endl;
        resolutionLog.display();
    }

    void viewPendingTickets() {
        cout << "Pending Tickets:" << endl;
        pendingTickets.display();
    }

    
    void assignTickets(AgentManager& agentManager) {
        while (!pendingTickets.isEmpty()) {
            Ticket currentTicket = pendingTickets.dequeue();
            agentManager.assignTicketToAgent(&currentTicket);
        }
    }
};
#endif