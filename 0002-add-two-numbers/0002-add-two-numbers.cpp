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
#include <string>
#include <cmath>



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum, val1, val2, val, out, i=1;
        ListNode* head = nullptr;
        ListNode* ptr = nullptr; 
        ListNode* tail = nullptr;
        while(l1 || l2){
            if(l1){
                val1 = l1 -> val;
                l1 = l1->next;
            }
            else val1 = 0;
            if(l2){
                val2 = l2 -> val;
                l2 = l2 -> next;
            }
            else val2 = 0;
            sum = val1 + val2 + carry;
            out = sum % 10;
            cout << out << " " << sum << " ";
            carry = floor(sum/10);
            if(head){
                ptr = new ListNode(out);
                tail->next = ptr;
                tail = ptr;
            }
            else{
                head = new ListNode(out);
                head->next = nullptr;
                tail = head;
            }
        }
        if(carry){
            ptr = new ListNode(carry);
            tail -> next = ptr;
        }
        return head;
    }
};