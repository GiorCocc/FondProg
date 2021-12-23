#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

#include "lstack.h"
#include "es7_binary_tree-listTest.h"
#include "lqueue.h"

// class Node
template <typename E>
class Node
{
public:
    E data; // Value for this node
    Node *lChildptr;
    Node *rChildptr;
    // Constructors<
    Node(E dataNew)
    {
        data = dataNew;
        lChildptr = NULL;
        rChildptr = NULL;
    }
};

template <class T>
class BinaryTree
{

private:
    // inserimento di un elemento nell'albero binario
    void Insert(T newData, Node<T> *&theRoot)
    {
        if (theRoot == NULL)
        {
            theRoot = new Node<T>(newData);
            return;
        }

        if (newData < theRoot->data)
            Insert(newData, theRoot->lChildptr);
        else
            Insert(newData, theRoot->rChildptr);
    }

    // attraversamento con stampa dell'albero
    // permutando le righe si ottengono attraversamenti pre-order, post-order, in-order
    void traverse(Node<T> *theRoot)
    {
        if (theRoot != NULL)
        {
            traverse(theRoot->lChildptr);
            traverse(theRoot->rChildptr);
            cout << theRoot->data << " ";
        }
    }

    // attraversamento pre-order non ricorsivo
    void traverse_preorder_NR(Node<T> *theRoot)
    {
        LStack<Node<T> *> s;
        s.push(theRoot);
        while (s.length() != 0)
        {
            theRoot = s.pop();
            cout << theRoot->data << " ";
            if (theRoot->rChildptr != NULL)
                s.push(theRoot->rChildptr);
            if (theRoot->lChildptr != NULL)
                s.push(theRoot->lChildptr);
        }
    }

    // attraversamento level-order (chiamato anche in ampiezza)
    void traverse_levelorder_NR(Node<T> *theRoot)
    {
        LQueue<Node<T> *> q;
        q.enqueue(theRoot);
        while (q.length() != 0)
        {
            theRoot = q.dequeue();
            cout << theRoot->data << " ";
            if (theRoot->lChildptr != NULL)
                q.enqueue(theRoot->lChildptr);
            if (theRoot->rChildptr != NULL)
                q.enqueue(theRoot->rChildptr);
        }
    }

    // conta il numero di elementi nell'albero binario
    int count_elements(Node<T> *h)
    {
        if (h == NULL)
            return 0;
        return count_elements(h->lChildptr) + count_elements(h->rChildptr) + 1;
    }

    // restituisce l'altezza dell'albero
    int tree_height(Node<T> *h)
    {
        if (h == NULL)
            return -1;
        int u = tree_height(h->lChildptr), v = tree_height(h->rChildptr);
        if (u > v)
            return u + 1;
        else
            return v + 1;
    }

    Node<T> *max(T a[], int l, int r)
    {
        int m = (l + r) / 2;
        Node<T> *x = new Node<T>(a[m]);
        if (l == r)
            return x;
        x->lChildptr = max(a, l, m);
        x->rChildptr = max(a, m + 1, r);
        int u = x->lChildptr->data.key(), v = x->rChildptr->data.key();
        if (u > v)
            x->data = u;
        else
            x->data = v;
        return x;
    }

    int equal(Node<T> *theRootA, Node<T> *theRootB)
    {
        if (theRootA == 0) //controllo che il primo albero sia vuoto
        {
            if (theRootB != 0) //controllo che il secondo albero non sia vuoto
                return 0;      //i due alberi sono diversi perchè il primo è nullo
        }
        else
        {
            if (theRootB == 0) //controllo che il secondo albero sia vuoto
                return 0;      //i due alberi sono diversi perchè non esistono

            int ris;
            if (theRootA->data.key() != theRootB->data.key()) //controllo che i dati in radice siano diversi
                return 0;                                     //i due alberi sono diversi perchè il dato in radice non è uguale in entrambi

            ris = equal(theRootA->lChildptr, theRootB->lChildptr); //applico la ricorsione nel sottoalbero sinistro
            if (ris == 0)                                          //controllo che il risultato sia 0
                return 0;                                          //i due alberi sono diversi

            ris = equal(theRootA->rChildptr, theRootB->rChildptr); //applico la ricorsione nel sottoalbero destro
            if (ris == 0)                                          //controllo che il risultato sia 0
                return 0;                                          //i due alberi sono diversi
        }
        return 1; //i due alberi sono uguali perchè hanno tutti i nodi uguali
    }

public:
    Node<T> *root;

    BinaryTree()
    {
        root = NULL;
    }

    void AddItem(T newData)
    {
        Insert(newData, root);
    }

    void traverse()
    {
        traverse(root);
        //traverse_preorder_NR(root);
        //traverse_levelorder_NR(root);
    }

    int count()
    {
        return count_elements(root);
    }

    int height()
    {
        return tree_height(root);
    }

    void createTournament(T a[], int l, int r)
    {
        root = max(a, l, r);
    }

    int equal_tree(BinaryTree<T> *treeB)
    {
        Node<T> *theRootB = treeB->get_root(); //ricavo la radice del secondo albero
        int risultato = equal(root, theRootB);
        return risultato;
    }

    Node<T> *get_root()
    {
        return root;
    }
};

#endif