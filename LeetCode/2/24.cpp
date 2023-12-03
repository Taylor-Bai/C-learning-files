#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};


struct LinkList
{
public:
	ListNode head;
    LinkList(vector<int>& a) : head(a[0],NULL) {}

	void CreateList(vector<int>& a);
	void Display();
};


void LinkList::CreateList(vector<int>& a) { // 头插法创建链表
	for (int i = 1; i < a.size(); i++) {
		ListNode* tmp = new ListNode;
		tmp->val = a[i];
		tmp->next = head.next;
		head.next = tmp;
	}
};


void LinkList::Display() {
	ListNode* tmp;
    cout << head.val << "  ";
	tmp = head.next;
	while (tmp) {
		cout << tmp->val << "  ";
		tmp = tmp->next;
	}
}

// 24. 两两交换链表中的节点

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* virtualptr = new ListNode(0,head);
        ListNode* prev = virtualptr;
        ListNode* temp = virtualptr->next;
        while(temp != NULL && temp->next != nullptr){           
            // 条件temp != NULL 对应输入为空的情况      
            // 条件temp->next != nullptr,表示只要temp指向的有东西，就可以进行交换，对应输入为奇数的情况
            temp = prev->next;
            prev->next = temp->next;
            temp->next = temp->next->next;
            prev->next->next = temp;
            

            prev = temp;
            temp = temp->next;
        }
        return virtualptr->next;        // 不是输出head
    }
};


int main()
{
    Solution a;
    vector<int> b = {};
    LinkList link(b);
    link.CreateList(b);
    link.Display();

    ListNode* gen_head = &link.head;
    ListNode* pro_head = a.swapPairs(gen_head);

    return 0;
};