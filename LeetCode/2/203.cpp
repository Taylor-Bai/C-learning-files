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


// 203.链表节点删除
// 关键点：1.问题在于改变链表的  连接顺序  ，而不是改变内存值
//         2. 链表指针溢出也无所谓，边界条件设置相比于数组更简单
//          3. 注意指针和实体的区别


// 法一：把头指针删除当作特殊情况
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){         // 如果链表开始就等于val，则一直开始删
            head = head->next;
        }
        if(head == NULL){                               // 放后面，因为头节点可能删完导致 head指针溢出
            return head;
        }
        ListNode* prev = head;                          // 主程序部分，先放一个指针prev指向链表头节点，遍历prev，head也随之改变
        while (prev->next != NULL){
            if(prev->next->val == val){
                prev->next = prev->next->next;
            }else{
                prev = prev->next;
            }
        }
        return head;
    }
};

// 法二：虚拟节点法
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode virtualNode(val-1,head);           // 设置一个节点，他指向头节点，且值不为val。用于保存头节点链表的连接信息
        ListNode* prev = &virtualNode;                          
        while (prev->next != NULL){
            if(prev->next->val == val){
                prev->next = prev->next->next;
            }else{
                prev = prev->next;
            }
        }
        return virtualNode.next;                    // 注意head链表并未改变，输出head是错的
    }
};

// 法三：递归
// 
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){                             
            return head;
        }
        head->next = removeElements(head->next,val);
        if(head->val == val){                           // 反向依此遍历每一个数
            return head->next;
        }else{
            return head;
        }                         

    }
};

int main()
{
    Solution2 a;
    vector<int> b = {7,7,9,8,7};
    LinkList link(b);
    link.CreateList(b);
    link.Display();

    ListNode* gen_head = &link.head;
    ListNode* pro_head = a.removeElements(gen_head,7);

    return 0;
};

