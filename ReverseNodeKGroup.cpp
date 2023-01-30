#define node ListNode
class Solution {
public:
    node*reverse(node*head, int k){
        node*curr = head;
        node*prev = NULL;
        node*next;

        while(k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //set pinter
        node*newhead = head;
        node*chotahead = head;

        int cnt = 0;

        while(cnt<k and chotahead != NULL){
            chotahead = chotahead->next;
            cnt++;
        }

        if(count == k){
            newhead = reverse(head,k);
            head->next = reverseKGroup(chotahead,k);
            return newhead;
        }
        return head;
    }
};