// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

void addlast(node* &start, int item) {
    node* n = new node();
    if (start == NULL) {
        n->data = item;
        n->next = NULL;
        start = n;
        return;
    }
    node* t = start;
    while (t->next!=NULL)
    {
        t = t->next;
    }
   
    t->next = n;
    n->data = item;
    n->next = NULL;
}

void addfirst(node* &start,int item) {
    node* n = new node();
    if (start == NULL) {
        n->data = item;
        n->next = NULL;
        start = n;
        return;
    }
    n->data = item;
    n->next = start;
    start = n;
}

void addpos(node* &start, int item,int pos) {
    node* t = start;
    int c = 0;
    while (t!=NULL)
    {
        c++;
        t = t->next;
    }
    if (pos == 1) {
        addfirst(start, item);
        return;
    }
    if (pos == (c + 1)) {
        addlast(start, item);
        return;
    }
    t = start;
    for (int i = 1; i < pos - 1; i++)
        t = t->next;
    node* n = new node();
    n->next = t->next;
    t->next = n;
    n->data = item;
}

void deletelast(node* &start) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    if (start->next == NULL) {
        delete start;
        start = NULL;
        return;
    }
    node* t = start;
    while (t->next->next!=NULL)
    {
        t = t->next;
    }
    delete t->next;
    t->next = NULL;

}

void deletefirst(node* &start) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    if (start->next == NULL) {
        delete start;
        start = NULL;
        return;
    }
    node* t = start;
    start = start->next;
    delete t;
}

void deletepos(node* &start, int pos) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    if (pos == 1) {
        deletefirst(start);
        return;
    }
    node* t = start;
    int c = 0;
    while (t!=NULL)
    {
        c++;
        t = t->next;
    }
    if (pos == c) {
        deletelast(start);
        return;
    }
    t = start;
    for (int i = 1; i < pos - 1; i++) {
        t = t->next;
    }
    node* p = t->next;
    t->next = t->next->next;
    delete p;
}

void deleteaddress(node* start, node* x) {
    if (x == start) {
        deletefirst(start);
        return;
    }
    node* t = start;
    while (t->next!=NULL)
    {
        t = t->next;
    }
    if (x == t) {
        deletelast(start);
        return;
    }
    t = start;
    while (t->next!=NULL)
    {
        if (t->next == x)break;
        t = t->next;
    }
    t->next = t->next->next;
    delete x;
}

void show(node* start) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    node* t = start;
    cout << endl;
    while (t!=NULL)
    {
        cout << t->data << "\t";
        t = t->next;
    }
    cout << endl;
}

void concate(node* &head1, node* head2) {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    node* t = head1;
    while (t->next!=NULL)
    {
        t = t->next;
    }
    t->next = head2;
}



int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    addlast(head1, 4);
    addlast(head1, 6);
    addlast(head1, 8);
    addlast(head1, 10);
    addlast(head2, 11);
    addlast(head2, 12);
    addlast(head2, 13);
    addlast(head2, 14);
    addlast(head2, 15);
    addlast(head2, 16);
    concate(head2, head1);
    show(head2);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
