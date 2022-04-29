#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Queue
{
    Node* bas;
    Node* son;
    void olustur();
    void kapat();
    void ekle(int);
    int cikar();
    bool bosmu();
};

void Queue::olustur()
{
    bas = NULL;
    son = NULL;
}

void Queue::kapat()
{
    Node* p;
    while (bas)
    {
        p = bas;
        bas = bas->next;
        delete p;
    }
};

void Queue::ekle(int veri) //! okey
{

    Node* newNode = new Node();
    newNode->data = veri;
    newNode->next = NULL;

    if (bas == NULL)
    {

        bas = newNode;
        son = bas;
    }
    else
    {
        son->next = newNode;
        son = newNode;
    }
}

int Queue::cikar() //! okey
{
    Node* temp;
    int deger;
    temp = bas;
    bas = bas->next;
    deger = temp->data;
    delete temp;

    return deger;
};

bool Queue::bosmu() //! okey
{
    return bas == NULL;
}

struct Stack
{
    Queue k1, k2;
    void olustur();
    void kapat();
    void ekle(int);
    int cikar();
    bool bosmu();
    int tepe();
    void yazdir();
    int size;
};
void siraliEkle(Stack*, int);
void yiginCikar(Stack*);

void Stack::olustur() //! okey
{
    k1.olustur();
    k2.olustur();

    size = 0;
}

void Stack::ekle(int veri) //! okey
{
    size++;
    k2.ekle(veri);

    while (!k1.bosmu())
    {
        k2.ekle(k1.cikar());
    }
    Queue k = k1;
    k1 = k2;
    k2 = k;
}

int Stack::cikar() //! okey
{

    if (k1.bosmu())
        return -1;

    size--;
    return k1.cikar();
}

int Stack::tepe() //! okey
{

    if (k1.bosmu())
        return -1;
    return k1.bas->data;
}

void Stack::kapat() 
{

    Node* p ;
     
    while (k1.bas)
    {
        p = k1.bas;
        k1.bas= k1.bas->next;
        delete p;
    }
}

bool Stack::bosmu() 
{
    return k1.bas == NULL;
}

void Stack::yazdir() 
{
    Node* tmp = k1.bas;
    while (tmp)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

void yiginCikar(Stack* s) 
{

    if (!s->bosmu())
    {
        int veri = s->cikar();
        yiginCikar(s);
        siraliEkle(s, veri);
    }
}

void siraliEkle(Stack* s, int veri) 
{

    if (s->bosmu() or veri > s->tepe())
    {
        s->ekle(veri);
        return;
    }
    int temp = s->cikar();
    siraliEkle(s, veri);
    s->ekle(temp);
}

int main()
{

    Stack* s = new Stack();
    s->olustur();
    s->ekle(3);
    s->ekle(1);
    s->ekle(7);
    s->ekle(4);
    s->ekle(8);
    s->yazdir();
    cout << "yeni hali" << endl;
    yiginCikar(s);
    s->yazdir();

    return 0;
}