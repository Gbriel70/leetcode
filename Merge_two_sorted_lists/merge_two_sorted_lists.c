#include <stdio.h>
#include <string.h>

struct ListNode 
{
      int val;
      struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (!list1) return list2;
    if (!list2) return list1;

    struct ListNode resp;
    struct ListNode *p = &resp;
    p->next = NULL;
    
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }
        else
        {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list1) p->next = list1;
    if (list2) p->next = list2;
    return resp.next;
}

int main(void)
{
    struct ListNode list1[3] = {{1, &list1[1]}, {2, &list1[2]}, {4, NULL}};
    struct ListNode list2[3] = {{1, &list2[1]}, {3, &list2[2]}, {4, NULL}};
    struct ListNode *list3 = mergeTwoLists(list1, list2);

    while (list3)
    {
        printf("%d ", list3->val);
        list3 = list3->next;
    }
    printf("\n");
    return 0;
}