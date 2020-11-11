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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        ListNode* res = new ListNode();
        ListNode* resp = res;
        ListNode* l1p = l1;
        ListNode* l2p = l2;
        while (l1p != NULL && l2p != NULL) {
            if (l1p->val < l2p->val) {
                resp->val = l1p->val;
                l1p = l1p->next;
            }
            else {
                resp->val = l2p->val;
                l2p = l2p->next;
            }
            resp->next = new ListNode();
            resp = resp->next;
        }
        if (l1p == NULL) {
            while (l2p != NULL) {
                resp->val = l2p->val;
                l2p = l2p->next;
                if (l2p != NULL) {
                    resp->next = new ListNode();
                    resp = resp->next;
                }
            }
        } else if (l2p == NULL) {
            while (l1p != NULL) {
                resp->val = l1p->val;
                l1p = l1p->next;
                if (l1p != NULL) {
                    resp->next = new ListNode();
                    resp = resp->next;
                }
            }
        }
        return res;
    }
};