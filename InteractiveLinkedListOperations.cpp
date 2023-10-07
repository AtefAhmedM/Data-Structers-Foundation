#include <iostream>
#include <string>

using namespace std;

struct nodeType
{
    int D;
    nodeType *nLink;
};

class LinkedListType
{
public:
    LinkedListType();
    virtual ~LinkedListType();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    virtual bool search(const int& dataToSearch) const = 0;
    virtual void insertFirst(const int& newData) = 0;
    virtual void insertLast(const int& newData) = 0;
    virtual void deleteNode(const int& deleteData) = 0;
    virtual void doubleList() = 0;

protected:
    int count;
    nodeType *first;
    nodeType *last;
};

class UnorderedLinkedList : public LinkedListType
{
public:
    bool search(const int& dataToSearch) const override;
    void insertFirst(const int& newData) override;
    void insertLast(const int& newData) override;
    void deleteNode(const int& deleteData) override;
    void doubleList() override;
};

LinkedListType::LinkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

LinkedListType::~LinkedListType()
{
    destroyList();
}

bool LinkedListType::isEmptyList() const
{
    return (first == NULL);
}

void LinkedListType::print() const
{
    nodeType *Current = first;
    while (Current != NULL)
    {
        cout << Current->D << " ";
        Current = Current->nLink;
    }
}

int LinkedListType::length() const
{
    return count;
}

void LinkedListType::destroyList()
{
    nodeType *Temp;

    while (first != NULL)
    {
        Temp = first;
        first = first->nLink;
        delete Temp;
    }

    last = NULL;
    count = 0;
}

bool UnorderedLinkedList::search(const int& dataToSearch) const
{
    bool dFound = false;
    nodeType *Current = first;
    while (Current != NULL && !dFound)
    {
        if (Current->D == dataToSearch)
        {
            dFound = true;
        }
        else
            Current = Current->nLink;
    }
    return dFound;
}

void UnorderedLinkedList::insertFirst(const int& newData)
{
    nodeType *nNode = new nodeType;
    nNode->D = newData;
    nNode->nLink = this->first;
    this->first = nNode;
    this->count++;
    if (this->last == NULL)
    {
        this->last = nNode;
    }
}

void UnorderedLinkedList::insertLast(const int& newData)
{
    nodeType *nNode = new nodeType;
    nNode->D = newData;
    nNode->nLink = NULL;
    if (this->first == NULL)
    {
        this->last = nNode;
        this->first = nNode;
    }
    else
    {
        this->last->nLink = nNode;
        this->last = nNode;
    }
    this->count++;
}

void UnorderedLinkedList::deleteNode(const int& deleteData)
{
    nodeType *Current = this->first;
    nodeType *pCurrent = NULL;

    while (Current != NULL)
    {
        if (Current->D == deleteData)
            break;

        pCurrent = Current;
        Current = Current->nLink;
    }
    if (Current != NULL)
    {
        if (pCurrent == NULL)
        {
            this->first = this->first->nLink;
            if (this->first == NULL)
                this->last = NULL;
        }
        else
        {
            pCurrent->nLink = Current->nLink;
            if (pCurrent->nLink == NULL)
                this->last = pCurrent;
        }
        this->count--;
        Current->nLink = NULL;
        delete Current;
    }
    else
    {
        if (this->first == NULL)
            cout << "Cannot delete from an empty list." << endl;
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
}

void UnorderedLinkedList::doubleList()
{
    nodeType *Current = first;
    if (Current == NULL)
    {
        cout << "Oops. You are doubling an empty list." << endl;
    }
    else
    {
        while (Current != NULL)
        {
            Current->D *= 2;
            Current = Current->nLink;
        }
    }
}

int main()
{
    UnorderedLinkedList list;
    int choice, num;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Delete a number" << endl;
        cout << "4. Double the list" << endl;
        cout << "5. Print the list" << endl;
        cout << "6. Length of the list" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a number to insert at the beginning: ";
            cin >> num;
            list.insertFirst(num);
            break;

        case 2:
            cout << "Enter a number to insert at the end: ";
            cin >> num;
            list.insertLast(num);
            break;

        case 3:
            cout << "Enter a number to delete: ";
            cin >> num;
            list.deleteNode(num);
            break;

        case 4:
            list.doubleList();
            cout << "List doubled." << endl;
            break;

        case 5:
            cout << "List: ";
            list.print();
            cout << endl;
            break;

        case 6:
            cout << "Length of the list: " << list.length() << endl;
            break;

        case 7:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 7);

    return 0;
}
