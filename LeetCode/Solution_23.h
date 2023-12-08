#pragma once

#include "pch.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) return nullptr;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); ++i)
        {
            ListNode* tmp = head;
            ListNode* Other = lists[i];

            // head가 nullptr인 경우 예외 처리
            if (tmp == nullptr)
            {
                head = Other;
                continue;
            }

            // 정렬을 위한 이전 노드 저장
            ListNode* Prev = nullptr;

            // head가 nullptr 아닐 경우 두 리스트를 정렬
            while (tmp && Other)
            {
                if (tmp->val < Other->val)
                {
                    Prev = tmp;
                    tmp = tmp->next;
                }
                else
                {
                    if (Prev == nullptr)
                    {
                        Prev = Other;
                        head = Other;
                        Other = Other->next;
                        head->next = tmp;
                    }
                    else
                    {
                        Prev->next = Other;
                        Other = Other->next;
                        Prev->next->next = tmp;
                        Prev = Prev->next;
                    }
                }
            }

            // Other가 남은 경우 뒤에 붙여줌
            if (Other != nullptr)
            {
                Prev->next = Other;
            }
        }

        return head;
    }
};