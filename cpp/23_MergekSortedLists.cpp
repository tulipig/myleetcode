#include <queue>
#include <vector>
#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<HeapNode,std::vector<HeapNode>,greater<HeapNode> > pq;
        ListNode* ansHeader = NULL;
        ListNode* currNode = NULL;

        {
            for(int idx=0; idx<lists.size(); ++idx){
                ListNode* lst = lists[idx];
                if(lst){
                    HeapNode heapNode(idx,lst->val);
                    pq.push(heapNode);
                } 
            }

            while(!pq.empty()){
                //get the current smallest val
                HeapNode smallest = pq.top();
                pq.pop();
                ListNode* head = lists[smallest.level];
                ListNode* headnext = head->next;

                //insert current smallest node to answers header
                head->next = NULL;
                if(!ansHeader){
                    ansHeader = head;
                    currNode = head;
                }
                else{
                    currNode->next = head;
                    currNode = head;
                } 

                //delete head form level
                lists[smallest.level] = headnext;

                if(headnext){
                    HeapNode heapNode(smallest.level,headnext->val);
                    pq.push(heapNode);
                } 
            }
        }

        return ansHeader;

    }

    struct HeapNode
    {
        int level;
        int val;
        HeapNode(int x, int y):level(x),val(y) {}
        bool operator>(const HeapNode& node) const
        { 
            return this->val > node.val;
        }
    };
};

int main(){
    ListNode node11(1);
    ListNode node12(4);
    ListNode node13(5);
    node11.next = &node12;
    node12.next = &node13;

    ListNode node21(1);
    ListNode node22(3);
    ListNode node23(4);
    node21.next = &node22;
    node22.next = &node23;

    ListNode node31(2);
    ListNode node32(6);
    node31.next = &node32;

    std::vector<ListNode*> lists;
    lists.push_back(&node11);
    lists.push_back(&node21);
    lists.push_back(&node31);

    Solution sol;
    ListNode* ansNode = sol.mergeKLists(lists);

    while(ansNode){
        cout << ansNode->val << " ";
        ansNode = ansNode->next;
    }

    cout << endl;

    return 0;
}
