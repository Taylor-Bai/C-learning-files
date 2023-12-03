#include <vector>
#include <iostream>
using namespace std;


// 环形链表

// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* sp = head;
        ListNode* fp = head;
        while(fp != NULL  && fp->next != NULL){         // 注意这里的fp指针越出的条件，不能写作fp->next->next != NULL,当链表为奇数时，fp->next为空，无法调用->next
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp) {
                ListNode* index1 = head;
                ListNode* index2 = sp;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};