// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;


struct node
{
    int info;
    node* next;
    node* prev;
};

void swap(node* &x, node* &y) {
    node* t = x;
    x = y;
    y = t;
}

void addlast(node*& start, int item) {
    node* n = new node();
    n->info = item;
    if (start == NULL) {
        n->prev = NULL;
        n->next = NULL;
        start = n;
        return;
    }
    node* t = start;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = n;
    n->prev = t;
    n->next = NULL;
    return;
}


void addfirst(node* &start, int item) {
    node* n = new node();
    if (start == NULL) {
        n->prev = NULL;
        n->info = item;
        n->next = NULL;
        start = n;
        return;
    }
    n->prev = NULL;
    n->info = item;
    n->next = start;
    start->prev = n;
    start = n;
}


//insert the number in a particular position of linked list
void addpos(node* &start, int item, int pos) {
    int c = 0;
    node* t = start;
    while (t!=NULL)
    {
        c++;
        t = t->next;
    }
    if (pos >= 1 && pos <= (c + 1)) {
        if (pos == 1) { 
            addfirst(start, item); 
            return;
        }
        if (pos == (c + 1)) {
            addlast(start, item);
            return;
        }
        t = start;
        for (int i = 1; i < pos; i++)
        {
            t = t->next;
        }
        node* n = new node();
        t->prev->next = n;
        n->prev = t->prev;
        n->next = t;
        t->prev = n;
        n->info = item;
    }
    else cout << "the position is wrong!" << endl;
}

void reverse(node* &start) {
    node* t = start;
    while (t != NULL)
    {
        swap(t->prev, t->next);
        if (t->prev == NULL)break;
        t = t->prev;
    }
    start = t;
}

void show(node* start) {
    if (start == NULL)cout << "empty";
    while (start!=NULL)
    {
        cout << start->info << "   -   ";
        start = start->next;
    }
    cout << "null" << endl;
}

void deletefirst(node* &start) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    if (start->prev == NULL && start->next == NULL) {
        delete start;
        start = NULL;
        return;
    }
    node* t = start;
    start->next->prev = NULL;
    delete t;
    start = start->next;
}

void deletelast(node* &start) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    if (start->prev == NULL && start->next == NULL) {
        delete start;
        start = NULL;
        return;
    }
    node* t = start;
    while (t->next!=NULL)
    {
        t = t->next;
    }
    t->prev->next = NULL;
    delete t;
}

void deletepos(node* &start, int pos) {
    if (start == NULL) {
        cout << "\nempty\n";
        return;
    }
    int c = 0;
    node* t = start;
    while (t!=NULL)
    {
        c++;
        t = t->next;
    }
    if (pos >= 1 && pos <= c) {
        if (pos == 1) {
            deletefirst(start);
            return;
        }
        if (pos == c) {
            deletelast(start);
            return;
        }
        t = start;
        for (int i = 1; i < pos; i++)
            t = t->next;
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
    }
    else cout << "\nwrong position!\n";
    return;
}

void deleteitem(node*& start, int item) {
    node* t = start;
    if (start == NULL)cout << "\nempty\n";
    int c = 0;
    while (t != NULL)
    {
        c++;
        t = t->next;
    }
    int k = 0;
    t = start;
    int* a = new int;
    for (int i = 1; i <= c; i++) {
        if (t->info == item) {
            k++;
            a[k - 1] = i;
        }
        t = t->next;
    }
    for (int i = 1; i <= k; i++) {
        deletepos(start, a[i - 1]);
    }
    delete a;
    delete t;
}

int main()
{
    node* start = NULL;
    addlast(start, 11);
    addlast(start, 12);
    addlast(start, 12);
    addlast(start, 12);
    addlast(start, 15);
    addlast(start, 16);
    show(start);
    cout << endl << endl;
    //reverse(start);
    deleteitem(start, 12);
    show(start);
    delete start;
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
