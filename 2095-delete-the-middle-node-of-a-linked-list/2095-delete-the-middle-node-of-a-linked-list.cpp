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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head->next){  //If single node, return none
            return nullptr;
        }
        
        
        ListNode* p2 = head->next->next;
        ListNode* p1 = head;

        
        
        while(p2 && p2->next){
            p2 = p2->next->next;
            p1 = p1->next;
        }
        
        p1->next = p1->next->next;

        return head;
    }
};