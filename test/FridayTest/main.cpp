#include <iostream>

struct Node
{
    int data;
    Node *next;

    Node() : data(0), next(nullptr){}

    Node(int data) : data(data), next(nullptr){}

    ~Node(){ data = 0; next = nullptr; }

    friend std::ostream &operator<<(std::ostream &stream, Node &node)
    {
        stream << node.data;
        return stream;
    }
};

class LinkedList
{
    public:
    LinkedList() : head(nullptr){}
    ~LinkedList(){ dispose(); }
    int Length();
    bool IsEmpty();
    void PushHead(int data);
    int PopHead();
    void PushTail(int data);
    int PopTail();
    void Insert(int index, int data);
    int Extract(int index);
    int Data(int index);
    void swap(int ia, int ib);
    void sort();
    friend std::ostream &operator<<(std::ostream &stream, const LinkedList &list)
    {
        Node *node = list.head;
        while (node != nullptr)
        {
            stream << *node << " ";
            node = node->next;
        }
        return stream;
    }

    private:
    Node *head;
    Node *ExtractNode(int index);
    void dispose();
    void InsertNode(int index, Node *node);
    int PopData(Node *node);
    bool IndexValid(int index);
};

int main(int argc, char *argv[])
{
    LinkedList list;
    std::cout << list << std::endl;
    list.PushHead(1);
    std::cout << list << std::endl;
    list.PushTail(3);
    std::cout << list << std::endl;
    list.Insert(1, 2);
    std::cout << list << std::endl;
    list.Insert(3, 4);
    std::cout << list << std::endl << std::endl;
    std::cout << list << std::endl;
    std::cout << list.PopHead() << " ";
    std::cout << list.Extract(1) << " ";
    std::cout << list.PopTail() << " ";
    std::cout << list.Extract(0) << std::endl;
    std::cout << list << std::endl;

    list.PushHead(3);
    list.PushHead(4);
    list.PushHead(1);
    list.PushHead(2);
    list.PushHead(7);
    list.PushHead(5);
    list.PushHead(8);
    list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;

    return EXIT_SUCCESS;
}

int LinkedList::Length()
{
    int len = 0;
    Node *node = head;
    while (node != nullptr)
    {
        node = node->next;
        ++len;
    }
    return len;
}

bool LinkedList::IsEmpty()
{
    return head == nullptr;
}

void LinkedList::PushHead(int data)
{
    Node *node = new Node(data);
    InsertNode(0, node);
}

void LinkedList::Insert(int index, int data)
{
    Node *node = new Node(data);
    InsertNode(index, node);
}

void LinkedList::PushTail(int data)
{
    Node *node = new Node(data);
    InsertNode(Length(), node);
}

int LinkedList::PopHead()
{
    return PopData(ExtractNode(0));
}

int LinkedList::Extract(int index)
{
    return PopData(ExtractNode(index));
}

int LinkedList::PopTail()
{
    return PopData(ExtractNode(Length() - 1));
}

int LinkedList::Data(int index)
{
    if (!IndexValid(index))
    {
        return -1;
    }

    Node *node = head;
    while(index > 0)
    {
        --index;
        node = node->next;
    }

    return node->data;
}

void LinkedList::swap(int ia, int ib)
{
    if (ia == ib || !IndexValid(ia) || !IndexValid(ib))
    {
        return;
    }
    if (ia > ib)
    {
        int res = ia;
        ia = ib;
        ib = res;
    }
    Node *Anode = ExtractNode(ia);
    Node *Bnode = ExtractNode(ib - 1);
    if (Anode == nullptr || Bnode == nullptr)
    {
        return;
    }
    InsertNode(ia, Bnode);
    InsertNode(ib, Anode);
}

void LinkedList::sort()
{
    for (int i = Length() - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (Data(j) > Data(j + 1))
            {
                swap(j, j + 1);
            }
        }
    }
}

void LinkedList::dispose()
{
    while (head != nullptr)
    {
        Node *node = head;
        head = head->next;
        delete node;
    }
}

bool LinkedList::IndexValid(int index)
{
    if (index < 0 || index > Length())
    {
        return false;
    }
    return true;
}

Node *LinkedList::ExtractNode(int index)
{
    if (!IndexValid(index))
    {
        return nullptr;
    }
    if (index == 0)
    {
        Node *node = head;
        head = head->next;

        return node;
    }
    Node *res = head;
    for (int i = 0; i < index - 1; ++i)
    {
        res = res->next;
    }
    Node *node = res->next;
    res->next = node->next;

    return node;
}

void LinkedList::InsertNode(int index, Node *node)
{
    if (index <= 0 || head == nullptr)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node *res = head;
        for (int i = 0; i < index - 1 && res->next != nullptr; ++i)
        {
            res = res->next;
        }
        node->next = res->next;
        res->next = node;
    }
}

int LinkedList::PopData(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int res = node->data;
    delete node;

    return res;
}
