#include <iostream>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        ListNode* pre1 = NULL;
        ListNode* pre2 = NULL;
        int lenl1 = 0;
        int lenl2 = 0;
        while(tmp1)
        {
            pre1 = tmp1;
            tmp1 = tmp1->next;
            ++lenl1;
        }
        while(tmp2){
            pre2 = tmp2;
            tmp2 = tmp2->next;
            ++lenl2;
        }

        if(pre1 != pre2) return NULL; //no intersection node

        if(lenl1 > lenl2){
            int diff = lenl1 - lenl2;
            while(diff>0){
                headA = headA->next;
                --diff;
            }
        }

        if(lenl2 > lenl1){
            int diff = lenl2 - lenl1;
            while(diff>0){
                headB = headB->next;
                --diff;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

int main()
{
    ListNode node11(8);
    ListNode node12(9);
    ListNode node13(9);
    node11.next = &node12;
    node12.next = &node13;

    ListNode node21(2);
 /*   ListNode node22(6);
    ListNode node23(4);
    node21.next = &node22;
    node22.next = &node23;*/

    // Solution sol;
    // ListNode* ans = sol.addTwoNumbers(&node11, &node21);

    // while(ans)
    // {
    //     cout<<ans->val<<" ";
    //     ans = ans->next;
    // }

    cout<<endl;
}