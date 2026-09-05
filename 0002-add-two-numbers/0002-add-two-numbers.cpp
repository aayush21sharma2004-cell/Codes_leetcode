/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the starting point of our result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        
        int carry = 0; // This will hold our carry-over value
        
        // Loop as long as there are nodes in l1, l2, or we have a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values from the current nodes (use 0 if a list has run out of nodes)
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate the sum of the digits and the current carry
            int sum = x + y + carry;
            
            // Update the carry for the next calculation (e.g., if sum is 14, carry is 1)
            carry = sum / 10;
            
            // Create a new node with the digit part of the sum (e.g., if sum is 14, digit is 4)
            curr->next = new ListNode(sum % 10);
            
            // Move our current pointer forward
            curr = curr->next;
            
            // Move l1 and l2 forward if they aren't already at the end
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // The real result starts at dummyHead->next (skipping the initial 0)
        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the allocated memory for the dummy node
        
        return result;
    }
};