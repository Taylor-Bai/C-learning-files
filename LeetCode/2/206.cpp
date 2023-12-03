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



// 206.反转链表
// 双指针法：时间复杂度o(n),空间复杂度o(1)，原地反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* backptr = NULL;
        ListNode* frontptr = head;
        ListNode* temp = NULL;
        while(frontptr != NULL){
        // while(frontptr->next != NULL)    报错，原因是当遍历到空位置时（frontptr = NULL），无法调用->next
        // 每次操作frontptr指向的元素，temp用于存原链表的下一个位置

            temp = frontptr->next;
            frontptr->next = backptr;
            backptr = frontptr;
            frontptr = temp;
        }
        return backptr;
    }
};


// 递归法：

class Solution1 {
public:
    ListNode* reverse(ListNode* frontptr,ListNode* backptr){
        if(frontptr == NULL){return backptr;}
        ListNode* temp = frontptr->next;
        frontptr->next = backptr;

        // 这一步迭代实现了
        // backptr  = frontptr;
        // frontptr = temp;
        return reverse(temp,frontptr);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL);
    }
};





int main()
{
    Solution1 a;
    vector<int> b = {1,5,4,3,2,1};
    LinkList link(b);
    link.CreateList(b);
    link.Display();

    ListNode* gen_head = &link.head;
    ListNode* pro_head = a.reverseList(gen_head);

    return 0;
};