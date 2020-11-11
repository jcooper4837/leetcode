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
        ListNode* res = new ListNode();
        ListNode* pr = res;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int c = 0;
        while (p1 != NULL && p2 != NULL) {
            pr->next = new ListNode();
            pr = pr->next;
            pr->val = p1->val + p2->val;
            pr->val += c;
            c = 0;
            while (pr->val >= 10) {
                pr->val -= 10;
                c++;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != NULL) {
            pr->next = new ListNode();
            pr = pr->next;
            pr->val = p1->val;
            pr->val += c;
            c = 0;
            while (pr->val >= 10) {
                pr->val -= 10;
                c++;
            }
            p1 = p1->next;
        }
        while (p2 != NULL) {
            pr->next = new ListNode();
            pr = pr->next;
            pr->val = p2->val;
            pr->val += c;
            c = 0;
            while (pr->val >= 10) {
                pr->val -= 10;
                c++;
            }
            p2 = p2->next;
        }
        if (c > 0) {
            pr->next = new ListNode();
            pr = pr->next;
            pr->val = c;
        }
        return res->next;
    }
};