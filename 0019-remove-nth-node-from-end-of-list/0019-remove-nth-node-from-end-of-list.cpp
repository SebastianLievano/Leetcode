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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode* tptr = head;
        ListNode* sptr = head;
        int length = 0;
        while(tptr){
            tptr = tptr-> next;
            length++;
        }
        if(n == length){
            head = head-> next;
            return head;
        }
        tptr = head;
        for(int i = 0; i < length - n; i++){
            sptr = tptr;
            tptr = tptr -> next;
        }
        sptr -> next = tptr -> next;
        return head;
    }
};