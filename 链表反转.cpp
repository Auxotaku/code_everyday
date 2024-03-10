/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
/*
  力扣的经典题目
  双指针法非常简单
  但是 递归方法还真有点意思
  要解决的几个问题：
  1. 是先反转操作 head->next->next = head 还是先进递归 reverseList(head->next)
  那必须先进递归，这就用函数栈建立起来结点间的联系了
  如果先head->next->next = head 那进去之后 又回来了 光速成环
  2. 原先的head 在 反转后指空
  所以在递归的尾部要写上head->next = nullptr;
  3. 新的head要怎么形成
  用递归的方式，我们直接求解newHead 最后返回的其实是就是尾节点 中间不对这个newHead做一点改动
*/