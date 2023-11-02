#include <stdio.h>
#include <stdlib.h>
#include <CCh10S2.h>

void allocateELEMENT(LINK *l)
{
    *l = (LINK)malloc(sizeof(ELEMENT));
    //(*l)->next = NULL;
}

LINK addElement(NODE n, LINK list)
{
    for (; list->next != NULL; list = list->next)
    {
    }
    allocateELEMENT(&(list->next));
    list->next->n = n;
    return list->next;
}

unsigned int count(LINK list)
{
    unsigned int cnt = 0;
    if (list == NULL)
        return cnt;
    else
        return 1 + count(list->next);
    /*for (; list != NULL; list = list->next, count++) //iterative
    {
    }
    return count;*/
}

LINK find(NODE n, LINK list)
{
    for (; list != NULL; list = list->next)
    {
        if (list->n == n)
            return list;
    }
    return NULL;
}

void concatenate(LINK l1, LINK l2)
{
    for (; l1->next != NULL; l1 = l1->next)
    {
    }
    l1->next = l2;
}

void insertElement(LINK list, LINK before, LINK insert)
{
    // insert may be a link list
    LINK found = find(before->n, list);
    if (found && before == found) // to avoid duplicate
    {
        LINK temp = before->next;
        before->next = insert;
        concatenate(before, temp);
    }
}

void delete (LINK* list, LINK element)
{
    if(*list == element)
    {
        LINK newlist = NULL;
        allocateELEMENT(&newlist);
        newlist = (*list)->next;
        *list=newlist;
        free(element);
        return;
    }
    for (LINK l = *list; l != NULL; l = l->next)
    {
        if (l->next->n == element->n)
        {
            LINK temp = element->next;
            free(element);
            l->next = temp;
            break;
        }
    }
}

void clear(LINK list)
{
    if (list == NULL)
    {
        clear(list->next);
    }
    free(list);
}

void print(LINK list)
{
    if (list != NULL)
    {
        printf("%d ---> ", list->n->value);
        print(list->next);
    }
    if (list == NULL)
        printf("NULL\n");
}