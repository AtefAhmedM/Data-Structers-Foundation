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
  void print()const;
  int length() const;
  void destroyList();
  virtual bool search(const int& dataToSearch)const=0;
  virtual void insertFirst(const int& newData)=0;
  virtual void insertLast(const int& newData)=0;
  virtual void deleteNode(const int& deletData)=0;
  virtual void doubleList()=0;
  protected:
  int count;
  nodeType *first;
  nodeType *last;
};
class unorderedLinkedList: public LinkedListType
{
    public:
    bool search(const int& dataToSearch)const ;
    void insertFirst(const int& newData) ;
    void insertLast(const int& newData) ;
    void deleteNode(const int& deleteData) ;
    void doubleList();


};
LinkedListType::LinkedListType()
{
    first=NULL;
    last=NULL;
    count=0;
}
LinkedListType::~LinkedListType()
{
    destroyList();
}
bool LinkedListType::isEmptyList()const
{
    return (first == NULL);
}
void LinkedListType::print() const
{
    nodeType *Current=first;
    while(Current!= NULL)
    {
        cout<<Current->D<<" ";
        Current=Current->nLink;
    }
}
int LinkedListType::length() const
{
    return count;
}
void LinkedListType::destroyList()
{
    nodeType *Temp;

    while(first!=NULL)
    {
        Temp=first;
        first=first->nLink;
        delete Temp;
    }

    last=NULL;
    count=0;
}
bool unorderedLinkedList::search(const int& dataToSearch)const
{
    bool dFound=false;
    nodeType *Current=first;
    while(Current!= NULL && !dFound)
    {
        if(Current->D==dataToSearch)
        {
            dFound=true;
        }
        else
        Current=Current->nLink;
    }
    return dFound;
}
void unorderedLinkedList::insertFirst(const int& newData)
{
    nodeType *nNode= new nodeType;
    nNode->D=newData;
    nNode->nLink=this->first;
    this->first=nNode;
    this->count++;
    if(this->last==NULL)
    {
        this->last=nNode;
    }
}
void unorderedLinkedList::insertLast(const int& newData)
{
    nodeType *nNode= new nodeType;
    nNode->D=newData;
    nNode->nLink=NULL;
    if(this->first==NULL)
    {
        this->last=nNode;
        this->first=nNode;
    }
    else
    {
        this->last->nLink=nNode;
        this->last=nNode;
    }
    this->count++;
}
void unorderedLinkedList::deleteNode(const int& deleteData)
{
    nodeType *Current=this->first;
    nodeType *pCurrent=NULL;


    while(Current != NULL)
    {
        if(Current->D==deleteData)
            break;

        pCurrent=Current;
        Current=Current->nLink;
    }
    if(Current!= NULL)
    {
        if(pCurrent == NULL)
        {
            this->first=this->first->nLink;
            if(this->first==NULL)
            this->last=NULL;
        }
        else
        {
            pCurrent->nLink=Current->nLink;
            if(pCurrent->nLink == NULL)
                this-> last= pCurrent;
        }
        this->count--;
        Current->nLink=NULL;
        delete Current;
    }
    else
    {
        if(this->first==NULL)
        cout<<"Cannot delete from an empty list."<<endl;
    else
        cout<<"The item to be deleted is not in the list."<<endl;
    }
}
void unorderedLinkedList::doubleList()
{
    nodeType *Current=first;
    if(Current==NULL)
    {
        cout<<"Oops. you are doubling an empty list."<<endl;
    }
    else
    {
        while(Current !=NULL)
        {
            Current->D *= 2;
            Current=Current->nLink;
        }
    }
}
int main()
{
unorderedLinkedList list;
int num;
cout << "Enter numbers ending with -999" << endl;
cin >> num;
while (num != -999)
{
list.insertLast(num);
cin >> num;
}
cout << endl;
cout << "List: ";
list.print();
cout << endl;
cout << "Length of the list: " << list.length() << endl;
cout << "Enter a number to delete fro pN    ��@ pNq�� 1���GR�Z `S�5rZ��D�0}G��C��U0�)'>�@�BS����{{� |J�PA<������Ӈ}��T`h�Q��a͟y�Jp��>+�[�B`���V���2Ց��c�O!���f����'ha�ue�P��Lq����� 4�� ,0��a�������[.}ZQ�J� �8Ё`�<%�A��f\�w�����'1uO9�2�V�ݧ[�p�O!�^Fw�	 ��@�j��Z��Ά�XG�t7@/6.&ʘ
 �,�=*��P���-��0�U<�.��$����@)\StZ(�jfn��dPB x�MT��mX�h`I:x$�'�Lj�J��p~:�^�