

#include "common.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next){
			return head;		
	    } 
		
		auto prev = head, slow = head, fast = head;
		while(fast != nullptr && fast->next != nullptr){
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr;
		auto l1 = sortList(head);
		auto l2 = sortList(slow);

		return merge(l1, l2);
    }

	ListNode* merge(ListNode* h1, ListNode* h2){
		
		cout << "--------------------- " << endl;
		p_list(h1);
		p_list(h2);
		if (h1 == nullptr){
			return h2;
		}
		if (h2 == nullptr){
			return h1;
		}
		ListNode dummy(0);
		ListNode* cur = &dummy;

		auto cur1 = h1, cur2 = h2;
		while(cur1 && cur2){
			if (cur1->val < cur2->val){
				cur->next = cur1;
				cur1 = cur1->next;
			}
			else {
				cur->next = cur2;
				cur2 = cur2->next;
			}
			cur = cur->next;
		}
		cur->next = cur1 != nullptr ? cur1 : cur2;
		p_list(dummy.next);
		cout << "++++++++++++++++++++++" << endl;
		return dummy.next;
	}

	void test(){
		auto l = g_list({4,2,1,3});
		p_list(l);
		auto l2 = sortList(l);
		p_list(l2);
	}
};
