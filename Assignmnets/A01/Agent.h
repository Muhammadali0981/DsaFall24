#include <iostream>
#include <string>
#include <algorithm> 
#include <ticket.h>
#include <DynamicArray.h>
using namespace std;

#ifndef AGENT_H
#define AGENT_H



struct Agent {
    int agentID;
    string name;
    DynamicArray<int> assignedTickets; 
    bool availability;
    string status;

   
    Agent(int id, string n) : agentID(id), name(n), availability(true), status("Available") {}

    
    void assignTicket(int ticketID) {
        assignedTickets.push_back(ticketID);
        if (assignedTickets.getSize() >= 5) {
            availability = false;
            status = "Unavailable";
        }
    }

   
    void updateAvailability() {
        if (assignedTickets.getSize() < 5) {
            availability = true;
            status = "Available";
        }
    }
};

class AgentManager {
private:
    DynamicArray<Agent> agents; 

public:
    
    void addAgent(int agentID, string name) {
        agents.push_back(Agent(agentID, name));
        cout << "Agent " << name << " added with ID: " << agentID << endl;
    }

    
    Agent* getAvailableAgent() {
        Agent* selectedAgent = nullptr;
        for (int i = 0; i < agents.getSize(); ++i) {
            if (agents[i].availability) {
                if (!selectedAgent || agents[i].assignedTickets.getSize() < selectedAgent->assignedTickets.getSize()) {
                    selectedAgent = &agents[i];
                }
            }
        }
        return selectedAgent;
    }

    
    void assignTicketToAgent(Ticket* ticket) {
        Agent* agent = getAvailableAgent();
        if (agent) {
            agent->assignTicket(ticket->ticketID);
            cout << "Ticket ID " << ticket->ticketID << " assigned to Agent " << agent->name << endl;
        } else {
            cout << "No available agents to assign the ticket." << endl;
        }
    }

  
    void displayAgents() {
        for (int i = 0; i < agents.getSize(); ++i) {
            cout << "Agent ID: " << agents[i].agentID << ", Name: " << agents[i].name
                 << ", Assigned Tickets: " << agents[i].assignedTickets.getSize()
                 << ", Status: " << agents[i].status << endl;
        }
    }
};


#endif
