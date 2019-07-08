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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0;
        int y = 0;
        int add = 0;
        int flag = 0;
        ListNode* head = NULL;
        ListNode* curr = NULL;
        while(l1 || l2 || flag){
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
            
            add = (x+y+flag)%10;
            flag = (x+y+flag)/10;
            ListNode* node = new ListNode(add);
            
            if(!head){
                head = node;
                curr = node;
            }
            else{
                curr->next = node;
                curr = node;
            }
        }
        
        return head;
    }
};

int main()
{
    ListNode node11(2);
    ListNode node12(4);
    ListNode node13(3);
    node11.next = &node12;
    node12.next = &node13;

    ListNode node21(5);
    ListNode node22(6);
    ListNode node23(4);
    node21.next = &node22;
    node22.next = &node23;

    Solution sol;
    ListNode* ans = sol.addTwoNumbers(&node11, &node21);

    while(ans)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }

    cout<<endl;
}