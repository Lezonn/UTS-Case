#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/model.h"

int monthToDay(char *str, int year) {
    if(strcmp(str, "january")==0) return 31;
    else if((strcmp(str, "february")==0) && (year % 4 == 0)) return 29;
    else if(strcmp(str, "february")==0) return 28;
    else if(strcmp(str, "march")==0) return 31;
    else if(strcmp(str, "april")==0) return 30;
    else if(strcmp(str, "may")==0) return 31;
    else if(strcmp(str, "juni")==0) return 30;
    else if(strcmp(str, "july")==0) return 31;
    else if(strcmp(str, "august")==0) return 31;
    else if(strcmp(str, "september")==0) return 30;
    else if(strcmp(str, "october")==0) return 31;
    else if(strcmp(str, "november")==0) return 30;
    else if(strcmp(str, "december")==0) return 31;
    return 0;
}

int yearToDay(int year) {
    return year*365 + year/4;
}

Node *createNode(Profile c) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->c.date = c.date;
    strcpy(temp->c.month, c.month);
    temp->c.year = c.year;
    strcpy(temp->c.name, c.name);
    temp->c.days = c.date + monthToDay(c.month, c.year) + yearToDay(2020-c.year);
    temp->next = temp->prev = NULL;
    return temp;
};

void pushPQ(Profile c) {
    Node *temp = createNode(c);
    if(!head) {
        head = tail = temp;
    } else if(temp->c.days > head->c.days) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    } else if(temp->c.days < tail->c.days) {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    } else {
        Node *curr = head;
        while(curr && curr->next->c.days > temp->c.days) {
            curr = curr->next;
        }
        curr->next->prev = temp; 
        temp->next = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }
}

void removePQ() {
    if(head && head == tail) {
        head = tail = NULL;
        free(head);
    } else {
        Node *newHead = head->next;
        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
}
