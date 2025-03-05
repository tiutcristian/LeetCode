struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
            ListNode* head = new ListNode((l1->val + l2->val) % 10);
            int c = (l1->val + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;
            ListNode* prev = head;
            
            while(l1 != nullptr && l2 != nullptr) {
                ListNode* crt = new ListNode((c + l1->val + l2->val) % 10);
                c = (c + l1->val + l2->val) / 10;
                l1 = l1->next;
                l2 = l2->next;
                prev->next = crt;
                prev = crt;
            }
            while(l1 != nullptr) {
                ListNode* crt = new ListNode((c + l1->val) % 10);
                c = (c + l1->val) / 10;
                l1 = l1->next;
                prev->next = crt;
                prev = crt;
            }
            while(l2 != nullptr) {
                ListNode* crt = new ListNode((c + l2->val) % 10);
                c = (c + l2->val) / 10;
                l2 = l2->next;
                prev->next = crt;
                prev = crt;
            }
            if (c) {
                ListNode* crt = new ListNode(c);
                prev->next = crt;
            }
    
            return head;
        }
    };