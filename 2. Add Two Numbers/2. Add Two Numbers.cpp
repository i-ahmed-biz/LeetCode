class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        else if(l1 == NULL && l2 == NULL) {
            return NULL;
        }

        ListNode* sumNode = new ListNode(0);
        ListNode* currNode = sumNode;

        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
           carry = 0;
           
           if(l1) {
              currNode->val =  currNode->val + l1->val;
              l1 = l1->next;
           }
           if(l2) {
              currNode->val =  currNode->val + l2->val;
               l2 = l2->next;
           }
           if(currNode->val > 9) {
               carry = 1;
               currNode->val = currNode->val % 10;
           }
           if(l1 || l2) {
             currNode->next = new  ListNode(carry); 
             currNode = currNode->next;
           }
        }
        
        if(carry != 0) {
           currNode->next =  new  ListNode(carry);
           currNode = currNode->next;
           
        }
        currNode ->next = NULL;
        
        return sumNode;
    }
};