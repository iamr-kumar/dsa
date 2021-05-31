#include<bits/stdc++.h>

using namespace std;

// Problem Statement - You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers 
// and return the sum as a linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Simple solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* tail = new ListNode();
        head = NULL;
        tail = NULL;
        int carry = 0;
        while(l1 or l2 or carry) {
            int a, b;
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            ListNode* newNode = new ListNode(sum % 10);
            if(!head) {
                head = newNode; tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
                
            }
            carry = sum / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head;
    }
};