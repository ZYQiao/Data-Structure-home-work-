#include <iostream>
#include "linklist.h"


using namespace std;
LinkList finalList;


void merge(Node* l1, Node* l2){
    if(l1->val > l2->val){
        if(l2->next != NULL)
            return merge(l1, l2->next);
        else{
            for(; l1 != NULL; l1 = l1->next){
                finalList.insert(l1->val);
            }
        }
    }else{
        finalList.insert(l1->val);
        if(l1->next != NULL)
            return merge(l1->next, l2);
        else{
            for(; l2 != NULL; l2 = l2->next){
                finalList.insert(l2->val);
            }
        }
    }
}

LinkList list1;
LinkList list2;

void SecMerge(Node *l1, Node *l2){
    if(l1->next == NULL){
        l1->next = l2;
    }else{
        if(l1->next->val <= l2->val){
            if(l2 != NULL)
                SecMerge(l1->next, l2);
        }else{
            Node* tmp = l1->next;
            l1->next = l2;
            SecMerge(l1, tmp);
        }
    }
}

int main()
{
    list1.insert(11); list1.insert(23); list1.insert(33); list1.insert(44);
    list2.insert(27); list2.insert(33); list2.insert(45);

    Node *l1 = list1.getHead(), *l2 = list2.getHead();
    Node *head = list1.getHead();
    SecMerge(l1, l2);

    for(; head != NULL; head = head->next){
        cout<< " val: "<<head->val <<endl;
    }
    return 0;
}
