#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * insert_node(struct ListNode *end,int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode) );
    end ->next = node;
    node->val = val;
    node->next = NULL;
    end = end->next; // 指向最后一个节点
    return end;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int jinwei = 0;
    struct ListNode * head, *end;
    head = (struct ListNode *)malloc(sizeof(struct ListNode) );
    end = head;
    while(l1 !=NULL || l2 !=NULL)
    {
        
        int tmp1 = 0;
        if(l1 !=NULL)
        {
            tmp1 = l1->val;
            l1 = l1->next;
        }
        int tmp2 = 0;
        if(l2 !=NULL)
        {
            tmp2 = l2->val;
            l2 = l2->next; 
        }
        int sum = tmp1 + tmp2 + jinwei;
        int dangqianwei = sum % 10;
        end = insert_node(end,dangqianwei);
        jinwei = sum/10;
    }
    //可能出现额外的进位,比如99 + 1
    if(jinwei != 0)
    {
        end = insert_node(end,1);
    }
    return head->next;
}

struct ListNode * create_list(long c)
{
    struct ListNode * head,*node,*end;
    head = (struct ListNode *)malloc(sizeof(struct ListNode) );
    end = head;
    //一个节点
    if(c == 0 )
    {
    node = (struct ListNode *)malloc(sizeof(struct ListNode) );
    end->next = node;
    node->val = 0;
    end = node;
    //结束创建
    end->next = NULL;
    return head;
    }

    // 多个节点
    while(c > 0)
    {
        node = (struct ListNode *)malloc(sizeof(struct ListNode) );
        end->next = node;
        node->val = c % 10;
        end = node;
        //结束创建
        end->next = NULL;
        c = c/10;
    }
    return head->next;
}

void print_list(struct ListNode* l)
{
    while(l != NULL)
    {
        printf("%d",l->val);
        l = l->next;
    }
    printf("\n");
}
int main(int argc,char **argv)
{
    long a = atol(argv[1]);
    long b = atol(argv[2]);
    struct ListNode *l1;
    struct ListNode *l2;
    struct ListNode *l;
    l1 = create_list(a);
    print_list(l1);
    l2 = create_list(b);
    print_list(l2);
    l = addTwoNumbers(l1,l2);
    print_list(l);
}