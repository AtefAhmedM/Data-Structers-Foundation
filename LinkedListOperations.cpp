#include <iostream>
#include <string>
using namespace std;

struct nodeType
{
    int D;
    nodeType *nLink;
};

class linkedListType
{
public:
    linkedListType();
    virtual ~linkedListType();
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

class unorderedLinkedList : public linkedListType
{
public:
    bool search(const int& dataToSearch) const override;
    void insertFirst(const int& newData) override;
    void insertLast(const int& newData) override;
    void deleteNode(const int& deleteData) override;
    void doubleList() override;
};

linkedListType::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

linkedListType::~linkedListType()
{
    destroyList();
}

bool linkedListType::isEmptyList() const
{
    return (first == NULL);
}

void linkedListType::print() const
{
    nodeType *Current = first;
    while (Current != NULL)
    {
        std::cout << Current->D << " ";
        Current = Current->nLink;
    }
    return;
}

int linkedListType::length() const
{
    return count;
}

void linkedListType::destroyList()
{
    nodeType *tempCurrent = first;
    nodeType *tempPrev = NULL;
    while (tempCurrent != NULL)
    {
        tempPrev = tempCurrent;
        tempCurrent = tempCurrent->nLink;
        delete tempPrev;
    }
    first = NULL;
    last = NULL;
    count = 0;
    return;
}

bool unorderedLinkedList::search(const int& dataToSearch) const
{
    bool bdFound = false;
    nodeType *Current = first;
    while (Current != NULL)
    {
        if (Current->D == dataToSearch)
        {
            return true;
        }
        Current = Current->nLink;
    }
    return false;
}

void unorderedLinkedList::insertFirst(const int& newData)
{
    nodeType *nNode = new nodeType;
    nNode->D = newData;
    nNode->nLink = first;
    first = nNode;
    count++;
    if (last == NULL)
    {
        last = nNode;
    }
    return;
}

void unorderedLinkedList::insertLast(const int& newData)
{
    nodeType *nNode = new nodeType;
    nNode->D = newData;
    nNode->nLink = NULL;
    if (last == NULL)
    {
        first = nNode;
    }
    else
    {
        last->nLink = nNode;
    }
    last = nNode;
    ++count;
    return;
}

void unorderedLinkedList::deleteNode(const int& deleteData)
{
    nodeType *Current;
    nodeType *pCurrent;
    bool dFound;
    if (first == NULL)
    {
        std::cout << "Cannot delete from an empty list." << std::endl;
    }
    else
    {
        if (first->D == deleteData)
        {
            Current = first;
            first = first->nLink;
            count--;
            if (first == NULL)
            {
                last = NULL;
            }
            delete Current;
        }
        else
        {
            dFound = false;
            pCurrent = first;
            Current = first->nLink;
            while (Current != NULL && !dFound)
            {
                if (Current->D != deleteData)
                {
                    pCurrent = Current;
                    Current = Current->nLink;
                }
                else
                    dFound = true;
            }
            if (dFound)
            {
                pCurrent->nLink = Current->nLink;
                count--;
                if (last == Current)
                {
                    last = pCurrent;
                }
                delete Current;
            }
            else
            {
                std::cout << "The item to be deleted is not in the list." << std::endl;
            }
        }
    }
    return;
}

void unorderedLinkedList::doubleList()
{
    nodeType *Current = first;
    if (Current == NULL)
    {
        std::cout << "Oops. You are doubling an empty list." << std::endl;
    }
    else
    {
        while (Current != NULL)
        {
            Current->D *= 2;
            Current = Current->nLink;
        }
    }
    return;
}

int main()
{
    unorderedLinkedList list;
    int num;
    cout << "Enter numbers ending with -999" << std::endl;
    cin >> num;
    while (num != -999)
    {
        list.insertLast(num);
        std::cin >> num;
    }
    cout << endl;
    cout << "List: ";
    list.print();
    cout << std::endl;
    cout << "Length of the list: " << list.length() << endl;
    cout << "Enter a number to delete from the list: ";
    cin >> num;
    cout << std::endl;
    list.deleteNode(num);
    cout << " List after deleting " << num << endl;
    list.print();
    cout << endl;
    cout << "Length of the list: " << list.length() << endl;
    list.doubleList();
    cout << "After doubling the list..." << endl;
    list.print();
    cout << std::endl;
    cout << "Length of the list: " << list.length() << endl;

    return 0;
}
