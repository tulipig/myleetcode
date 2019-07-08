#include "iostream"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:  
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* headbak = head;
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }

        int start = 1;
        int groupnum = len/2;
        ListNode* l1 = head;
        ListNode* l2 = head;
        ListNode* next = NULL;
        while(groupnum-->0){
            int tmp = start;
            while(tmp--) l2=l2->next;
            if(l2->next) next = l2->next;  
            ListNode*ret = mergeTwoLists(l1,l2);
            ret->next = next;
            start += 2;
            l1 = next;
            if()
        }
    }


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1 && l2) return l2;
        if(l1 && !l2) return l1;

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 || l2){
            if(l1 && l2){
                ListNode* node = new ListNode((l1->val < l2->val) ? l1->val : l2->val);
                (l1->val < l2->val) ? l1 = l1->next : l2 = l2->next;
                if(!head) head = node;
                if(tail)  tail->next = node;
                tail = node;
            }
            else if(l1 && !l2){ //l2 is NULL
                tail->next = l1;
                break;
            }
            else if(!l1 && l2){// l1 is NULL
                tail->next = l2;
                break;
            } 
        }

        return head;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(4);
    node1.next = &node2;
    node2.next = &node3;

    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    node4.next = &node5;
    node5.next = &node6;

    Solution sol;
    ListNode* head = sol.mergeTwoLists(&node1,&node4);
    cout << "get head" << endl;
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout<<endl;
}