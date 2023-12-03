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


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* prevA = headA;
        ListNode* prevB = headB;
        int lena = 0;
        int lenb = 0;
        while(prevA != NULL){
            lena++;
            prevA = prevA->next;
        }
        while(prevB != NULL){
            lenb++;
            prevB = prevB->next;
        }
        prevA = headA;
        prevB = headB;
        if(lenb > lena){                        // 让A为长的链表，B为短的，否则交换
            swap(lena,lenb);
            swap(prevA,prevB);
        }
        int gap = lena-lenb;                    // 计算链表差值
        while(gap--){                           // 两个链表按右端对齐
            prevA = prevA->next;
        }
        while(prevA != NULL){
            if(prevA == prevB){
                return prevA;
            }else{
                prevA = prevA->next;
                prevB = prevB->next;
            }
        }
        return NULL;
    }
};


// 以下测试有问题
int main()
{
    Solution a;
    vector<int> b_1 = {1,3,2};
    vector<int> b_2 = {1,5,4};
    vector<int> c = {1,8,7};
    LinkList link(c);
    link.CreateList(b_1);
    link.CreateList(c);
    link.Display();

    LinkList link2(c);
    link2.CreateList(b_2);
    link2.CreateList(c);
    link2.Display();
    ListNode* pro_head = a.getIntersectionNode(&link.head,&link2.head);

    return 0;
};