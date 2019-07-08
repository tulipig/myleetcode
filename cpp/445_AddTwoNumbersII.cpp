#include <iostream>
#include <stack>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        int lenl1 = 0;
        int lenl2 = 0;
        while(tmp1)
        {
            tmp1 = tmp1->next;
            ++lenl1;
        }
        while(tmp2){
            tmp2 = tmp2->next;
            ++lenl2;
        }

        int tmplenl1 = lenl1;
        while(tmplenl1 > lenl2){
            stk.push(l1->val);
            l1 = l1->next;
            --tmplenl1;
        }
        while(lenl2 > lenl1){
            stk.push(l2->val);
            l2 = l2->next;
            --lenl2;
        }

        int x = 0;
        int y = 0;
        while(l1 || l2){
            if(l1){
                x = l1->val; 
                l1 = l1->next;
            }
            else{
                x = 0;
            }
            
            if(l2){
                y = l2->val; 
                l2 = l2->next;
            }
            else{
                y = 0;
            }

            stk.push(x+y);
        }

        int add = 0;
        int flag = 0;
        ListNode* head = NULL;
        while(!stk.empty()){
            add = stk.top() + flag;
            flag = add/10;

            ListNode* node = new ListNode(add%10);
            node->next = head;
            head = node;

            stk.pop();
        }

        if(flag == 1){
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }
        
        return head;
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

    Solution sol;
    ListNode* ans = sol.addTwoNumbers(&node11, &node21);

    while(ans)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }

    cout<<endl;
}