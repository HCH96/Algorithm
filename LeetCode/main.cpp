#include "pch.h"
#include <iostream>

#include "Solution_23.h"




int main()
{
	//		[
	//		1->4->5,
	//		1->3->4,
	//		2->6
	//		]
	vector<ListNode*> lists;

	ListNode* pNode = new ListNode(1);
	ListNode* head = pNode;
	head->next = new ListNode(4);
	head = head->next;
	head->next = new ListNode(5);
	head = head->next;
	lists.push_back(pNode);

	pNode = new ListNode(1);
	head = pNode;
	head->next = new ListNode(3);
	head = head->next;
	head->next = new ListNode(4);
	head = head->next;
	lists.push_back(pNode);

	pNode = new ListNode(2);
	head = pNode;
	head->next = new ListNode(6);
	head = head->next;
	lists.push_back(pNode);



	Solution s;

	s.mergeKLists(lists);

	return 0;
}