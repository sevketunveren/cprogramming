#include <stdio.h>
#include <stdlib.h>
#include <CCh10S2.h>
void main()
{
    LINK head = NULL;
    LINK branch1 = NULL;
    LINK branch2 = NULL;
    allocateELEMENT(&head);
    allocateELEMENT(&branch1);
    allocateELEMENT(&branch2);
    head->d = "APPLE";
    branch1->d = "MANDARIN";
    branch2->d = "BANANA";
    addElement("FIG", head);
    addElement("ORANGE", head);
    print(head);
    LINK l2 = find("PEAR", head);
    addElement("PEAR", branch1);
    addElement("STRAWBERRY", branch1);
    concatenate(head, branch1);
    print(head);
    LINK l1 = find("ORANGE", head);
    insertElement(head, l1, branch2);
    print(head);
    l2 = find("PEAR", head);
    delete (head, l2);
    print(head);
    clear(head);
}

void allocateELEMENT(LINK *l)
{
    *l = (LINK)malloc(sizeof(ELEMENT));
    (*l)->next = NULL;
}

void addElement(DATA d, LINK list)
{
    for (; list->next != NULL; list = list->next)
    {
    }
    allocateELEMENT(&(list->next));
    list->next->d = d;
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

LINK find(DATA d, LINK list)
{
    for (; list != NULL; list = list->next)
    {
        if (list->d == d)
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
    LINK found = find(before->d, list);
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
        free(element);
        return;
    }
    for (LINK l = *list; l != NULL; l = l->next)
    {
        if (l->next->d == element->d)
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
        printf("%s ---> ", list->d);
        print(list->next);
    }
    if (list == NULL)
        printf("NULL\n");
}