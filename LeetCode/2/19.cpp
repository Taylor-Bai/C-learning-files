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


// 19.倒数第N个节点的删除
// 双指针的经典应用，使用一次遍历就可以得到结果，时间复杂度o(n)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtualptr = new ListNode(0,head);
        ListNode* sp = virtualptr;
        ListNode* fp = virtualptr;
        int i;
        while(fp != nullptr){
            if(i > n){
                sp = sp->next;
                i--;
            }
            fp = fp->next;
            i++;
        }
        if(sp->next->next != nullptr){
            ListNode* dp = sp->next;
            sp->next = sp->next->next;                      // 注意delete掉节点
            delete dp;
        }else{
            ListNode* dp = sp->next;
            sp->next = nullptr;
            delete dp;
        }
        return virtualptr->next;
    }
};

// 不严谨，当head为链表时（非{1}），删除第一个元素时，报错，unkonwn signal头节点找不到了
// 直接delete头节点会导致内存泄露，后面的内存无法释放


int main()
{
    Solution a;
    vector<int> b = {1,4,3,2};
    LinkList link(b);
    link.CreateList(b);
    link.Display();

    ListNode* gen_head = &link.head;
    ListNode* pro_head = a.removeNthFromEnd(gen_head,1);

    return 0;
};