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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr;
        ListNode* after;
        ListNode* last;
        if(!head) return nullptr;
        ptr = head;
        after = ptr->next;
        while(after != nullptr){
            if(after->val == ptr->val){
                if(ptr == head){
                    while(after != nullptr && ptr->val == after->val){
                        after = after->next;
                    }
                    if(after){head = after;}
                    else return nullptr;
                }
                else{
                    while(after != nullptr && ptr->val == after->val){
                        after = after->next;
                    }
                    if(after){
                        last->next = after;
                        ptr = after;
                        after = after->next;                   
                    }
                    else{
                        last->next = nullptr;
                    }
                }
            }
            else{
                last = ptr;
                ptr = after;
                after = after->next;
            }
        }
        return head;
    }
};