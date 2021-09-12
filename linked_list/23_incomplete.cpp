#include<bits/stdc++.h>

using namespace std;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        ListNode* head = NULL;
        int done = 0;
        int n = lists.size();
        while(!done) {
            int going = 1;
            int val = 1e5, ind = 0;
            for(int i = 0; i < n; i++) {
                if(lists[i] != NULL) {
                    going = 0;
                    if(val > lists[i]->val) {
                        val = lists[i]->val;
                        ind = i;
                    }
                }
            }
            if(going) {
                done = 1;
            } else {
                ListNode* a = lists[ind];
                lists[ind] = lists[ind]->next;
                if(head == NULL) {
                    ans = a;
                    head = a;
                } else {
                    head->next = a;
                    head = a;
                }
                head->next = NULL;

            }
        }
        return ans;
    }
};
