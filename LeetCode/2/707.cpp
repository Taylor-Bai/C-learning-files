#include <vector>
#include <iostream>
using namespace std;


struct linknode{
    int val;
    linknode* next;
    linknode() : val(0),next(nullptr) {}
    linknode(int a) : val(a),next(nullptr){}
    linknode(int a,linknode* b) : val(a),next(b){}
};

class MyLinkedList {
public:
    linknode virtualhead;
    int size;

    MyLinkedList() : virtualhead(0),size(0){}
    
    int get(int index) {
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        linknode* cur = virtualhead.next;
        while(index--){              // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;

    }
    
    void addAtHead(int val) {
        linknode* n = new linknode(val);        // 用 new 去产生新节点，返回是一个对象的指针
        n->next = virtualhead.next;
        virtualhead.next = n;
        size++;
    }
    
    void addAtTail(int val) {
        linknode* n = new linknode(val);
        linknode* prev = &virtualhead;
        while(prev ->next != nullptr){prev = prev->next;}
        prev->next = n;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0){index = 0;}               // index 参考头节点为0
        if(index > size){return ;}
        linknode* n = new linknode(val);
        linknode* prev = &virtualhead;
        while(index--){                         // index = 0跳出时 prev 位于 index-1 的位置
            prev = prev->next;
        }
        n->next = prev->next;                   // 注意和下一行之间顺序
        prev->next = n;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){return ;}
        linknode* prev = &virtualhead;
        while(index--){
            prev = prev->next;
        }
        linknode* dp = prev->next;
        prev->next = prev->next->next;
        delete dp;                            // 被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        dp = nullptr;
        size--;
    }

    // 打印链表
    void printLinkedList() {
        linknode* cur = &virtualhead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


int main()
{

    MyLinkedList link;
    int a;
    link.addAtHead(0);
    link.addAtTail(3);
    link.addAtIndex(1,2);
    a = link.get(2);
    link.printLinkedList();


    return 0;
};