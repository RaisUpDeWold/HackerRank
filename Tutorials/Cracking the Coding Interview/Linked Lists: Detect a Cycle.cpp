/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* slow = head;
	Node* fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			// Slow pointer caught up to the fast one, so there is a loop
			return true;
		}
	}
	return false; // Fast pointer hit the end of the list, so there is no loop
}
