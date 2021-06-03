#include <iostream>

using namespace std;

template <typename Nodetype> class list;

template <typename Nodetype>
class ListNode
{
    friend class list<Nodetype>;

    private:
    Nodetype data;
    ListNode<Nodetype> *nextptr;
    public:
        ListNode(const Nodetype &);
};

template <typename Nodetype>
ListNode<Nodetype> ::ListNode(const Nodetype &info): data(info),nextptr(0)
{}

//////////////////////////////////////////////////////////////////////////////////////////
template <typename Nodetype>
class list
{
    private:

        ListNode<Nodetype> *getNewNode(const Nodetype &);
        ListNode<Nodetype> *firstptr;
        ListNode<Nodetype> *lastptr;
    public:
        list();
        bool isEmpty();
        void push_back(Nodetype &);
        bool pop_back();
        void clear();
        void print();
        bool search(Nodetype );
        int size();
        void insert(Nodetype & , int);
        void erase(int );
        void sort();
        void swap(int ,int );
};

template <typename Nodetype>
list<Nodetype>::list():firstptr(0),lastptr(0)
{}

template <typename Nodetype>
ListNode<Nodetype>* list<Nodetype>::getNewNode(const Nodetype & address) //////returns the address of new Node
{
    return new ListNode<Nodetype> (address);
}

template <typename Nodetype>
bool list<Nodetype>::isEmpty()
{
    return firstptr == 0;
}

template <typename Nodetype>
void list<Nodetype>::push_back(Nodetype &value)
{
    ListNode<Nodetype> *newptr= getNewNode(value);
    if(isEmpty())
        firstptr=lastptr=newptr;
    else
    {
        lastptr->nextptr=newptr;
        lastptr=newptr;
    }
}

template <typename Nodetype>
bool list<Nodetype>::pop_back()
{
    if(isEmpty())
        return false;
    else
    {
        ListNode<Nodetype> *tempptr = lastptr;
        if(firstptr==lastptr)
            firstptr=lastptr=0;
        else
        {
            ListNode<Nodetype> *currptr = firstptr;
            while(currptr->nextptr!=lastptr)
                currptr=currptr->nextptr;
            lastptr = currptr;
            currptr->nextptr=0;
            delete tempptr;
            return true;
        }
    }
}

template <typename Nodetype>
void list<Nodetype> ::clear()
{
    if(!isEmpty())
        cout<<"destroying started.\n";
    ListNode<Nodetype> *currptr = firstptr;
    ListNode<Nodetype> *temp;

    while(currptr->nextptr!=0)
    {
        temp = currptr;
        cout<<currptr->data<<"\n";
        currptr = currptr -> nextptr;
        delete temp;
    }
    firstptr=lastptr=0;
    cout<<"List is clean\n";
}

template <typename Nodetype>
void list<Nodetype> ::print()
{
    if(isEmpty())
    {
        cout<<"List is empty\n\n\n";
        return;
    }
    ListNode<Nodetype> *currptr=firstptr;

    cout<<"List:";
    while(currptr !=0 )
    {
        cout<<currptr -> data<<" ";
        currptr = currptr -> nextptr;
    }
    cout<<endl;
}

template <typename Nodetype>
bool list<Nodetype>::search(Nodetype val)
{
    ListNode<Nodetype> *spy=firstptr;
    while(spy != 0)
    {
        if(spy->data == val) {
            cout<<"Was found\n";
            return true;
        }
        spy = spy->nextptr;
    }
    cout<<"not found\n";
    return false;
}

template <typename Nodetype>
int list<Nodetype> ::size()
{
    int counter = 0;
    ListNode<Nodetype>* currptr=firstptr;
    while (currptr != 0) {
        counter++;
        currptr = currptr -> nextptr;
    }
    return counter;
}

template <typename Nodetype>
void list<Nodetype> ::insert(Nodetype &value, int index)
{
    ListNode<Nodetype>* valptr=getNewNode(value);
    ListNode<Nodetype>* currptr=firstptr;
    ListNode<Nodetype>* tempptr;
    ListNode<Nodetype>* Bcurrptr=firstptr;

    int counter = 0;
    int counter1 = 0;

    if(index==0)
    {
        valptr->nextptr=firstptr;
        firstptr=valptr;
    }
    else {
        while (counter1 < index - 1) {
            Bcurrptr = Bcurrptr->nextptr;
            counter1++;
        }
        while (counter < index) {
            currptr = currptr->nextptr;
            counter++;
        }
        tempptr = currptr;
        currptr = valptr;
        Bcurrptr->nextptr = currptr;
        currptr->nextptr = tempptr;
    }
}

template <typename Nodetype>
void list<Nodetype> ::erase(int index)
{
    ListNode<Nodetype>* tmpptr;
    ListNode<Nodetype>* currptr=firstptr;
    ListNode<Nodetype>* Bcurrptr=firstptr;

    int counter=0;
    int counter1=0;

    if(index==0)
    {
        tmpptr=firstptr;
        firstptr=firstptr->nextptr;
        delete tmpptr;
    }
    else{
        while (counter < index) {
            currptr = currptr->nextptr;
            counter++;
        }
        while (counter1 < index - 1) {
            Bcurrptr = Bcurrptr->nextptr;
            counter1++;
        }
        tmpptr=currptr;
        if(currptr==lastptr)
        {
            lastptr = Bcurrptr;
            lastptr->nextptr=0;
            delete tmpptr;
        }
        else
        {
            Bcurrptr->nextptr = currptr->nextptr;
            delete tmpptr;
        }
    }
}

template<typename Nodetype >
void list< Nodetype >::sort()
{
    ListNode<Nodetype>* i, *j;
    Nodetype temp;
    for(i = firstptr; i != NULL; i=i->nextptr)
    {
        for(j=i->nextptr; j!=NULL; j=j->nextptr)
        {
            if((i->data)>j->data)
            {
                temp = i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

template<typename Nodetype>
void list<Nodetype> ::swap(int index0, int index1)
{
    ListNode<Nodetype> *pos0 = firstptr , *pos1=firstptr;
    Nodetype temp;

    while (index0 > 0)
    {
        pos0=pos0->nextptr;
        index0--;
    }
    while (index1 > 0)
    {
        pos1=pos1->nextptr;
        index1--;
    }
    temp = pos0->data;
    pos0->data=pos1->data;
    pos1->data=temp;
}

void menu()
{
    cout<<"Enter one of the following:\n"
        <<" 1 to push_back\n"
        <<" 2 to pop_back\n"
        <<" 3 to  clear the list\n"
        <<" 4 to search for element\n"
        <<" 5 to show the size of the list\n"
        <<" 6 to insert element\n"
        <<" 7 to erase an element\n"
        <<" 8 to sort\n"
        <<" 9 to swap 2 elements\n"
        <<" 0 to exit the program\n";
}

template <typename T>
void testlist(list<T> & linklist , const string &Typename)
{
    cout<<"testing a list of "<<Typename<<" value\n";
    menu();
    int choice;
    int pos;
    int pos1;
    T value;
    do{
        cout<<"* ";
        cin>>choice;
        switch (choice){
            case 1 : //////push_back
                cout<<"Enter "<<Typename<<":";
                cin>>value;
                linklist.push_back(value);
                linklist.print();
                break;
            case 2 : /////pop_back
                linklist.pop_back();
                linklist.print();
                break;
            case 3:////clear
                linklist.clear();
                break;
            case 4:////search
                cout<<"Enter data: ";
                cin>>value;
                linklist.search(value);
                linklist.print();
                break;
            case 5://///size
                cout<<"the size of list is ";
                cout<<linklist.size()<<endl;
                linklist.print();
                break;
            case 6:////insert
                cout<<"Enter data:";
                cin>>value;
                cout<<"Enter position:";
                cin>>pos;
                linklist.insert(value,pos);
                linklist.print();
                break;
            case 7:///////erase
                cout<<"Enter the Position of data: ";
                cin>>pos;
                linklist.erase(pos);
                linklist.print();
                break;
            case 8://///sort
                linklist.sort();
                linklist.print();
                break;
            case 9://///swap
                cout<<"Enter position of first data : ";
                cin>>pos;
                cout<<"Enter position of second data : ";
                cin>>pos1;
                linklist.swap(pos,pos1);
                linklist.print();
                break;
        }
    } while (choice != 0);
    cout<<endl;
}

int main()
{
    cout<<"Choose type of your data:\n"
    <<"1.integer\n"
    <<"2.float\n"
    <<"3.double\n"
    <<"4.char\n";
    cout<<"you choice:";
    int choice;
    cin>>choice;
    if(choice==1)
    {
        list<int> intlist;
        testlist(intlist, "integer");
    }
    if(choice==2)
    {
        list<float> inlist;
        testlist(inlist,"float");
    }
    if(choice==3)
    {
        list<double> inlist;
        testlist(inlist,"double");
    }
    if(choice==4)
    {
        list<char> inlist;
        testlist(inlist,"char");
    }
}
