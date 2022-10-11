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
    //helper fn finds minimum node
    ListNode* getMinNode(vector<ListNode*>& l){
        int min_idx;
        int min_val = INT32_MAX;
        for(int i = 0; i < l.size(); ++i){
            if(l[i]->val < min_val){
                min_idx = i;
                min_val = l[i]->val;
            }
        }
        ListNode* lowest = l[min_idx];
        l[min_idx] = l[min_idx]->next;
        //Erasing any empty lists
        if(!l[min_idx]){
            l.erase(l.begin() + min_idx);
        }
        return lowest;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] == nullptr){
                swap(lists[i], lists.back());
                lists.pop_back();
                i--;
            }   //If no lists left
            if(lists.size() == 0){
                return nullptr;
            }
        }
        ListNode* head = getMinNode(lists);
        ListNode* ptr = head;
        while(lists.size() > 0){
            ptr->next = getMinNode(lists);
            ptr = ptr->next;
        }
        return head;
    }
};