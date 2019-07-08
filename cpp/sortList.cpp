#include <string>  
#include <vector>
#include <iostream>  
#include <unordered_map>  
#include <unordered_set> 
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int len=0;
        if(!head || !head->next) return head;
        while(head){
            len++;
            head=head->next;
        }

        int group=1;
        ListNode* l1=head;
        ListNode* l2=NULL;
        while(group<len/2){
            int tmp=group;
            while(tmp--) l2=l1->next;

            tmp=group;
            ListNode* curr=NULL;
            while(group--){
                if(l1->val > l2->val){
                    int swp = l1->val;
                    l1->val = l2->val;
                    l2->val = swp;
                    l1 = l1->next;
                }
            }

        }
    }

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    }


};

int main(int argc, char const *argv[])
{


    Solution sol;
    cout << sol.findCircleNum(M) << endl;
    return 0;
}