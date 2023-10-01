#include <iostream>
#include <string>


using namespace std;


template <class elemType>
class arrayListType

{
    public:
        const arrayListType<elemType>&
                operator=(const arrayListType<elemType>&);

        bool isEmpty() const;
        bool isFull() const;
        int listSize() const;
        int maxListSize() const;
        void print() const;
        bool isItemAtEqual(int location, const elemType& item) const;
        virtual void insertAt(int location, const elemType& insertItem) =0;
        virtual void insertEnd(const elemType& insertItem) = 0;
        void removeAt(int location);
    
        void retrieveAt(int location, elemType& retItem) const;

        virtual void replaceAt(int location, const elemType& repItem) = 0;
        void clearList();
        virtual int seqSearch(const elemType& searchItem) const = 0;
        virtual void remove(const elemType& removeItem) = 0;

        arrayListType(int size = 100);

        arrayListType(const arrayListType<elemType>& otherList);
        virtual ~arrayListType();



    protected:
        elemType *list;
        int length;
        int maxSize;


};
template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}



template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;

    list = new elemType[maxSize];

    for (int i = 0; i < length; i++)
        list[i] = otherList.list[i];
}


template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return length == 0;
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return length == maxSize;
}


template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int  i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}






template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
    if (location < 0 || location >= length){
        cout << "The location of the item to be removed is out of range" << endl;
        return false;
    }
    else
        return (list[location] == item);
}


template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cout<< "This location of the item to be removed is out of range." << endl;
    else{
        for (int i = location; i < length - 1; i++)
            list[i] = list[i + 1];
        length--;
    }
}
        
template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cout<< "This location of the item to be removed is out of range." << endl;
    else
    retItem = list[location];
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    
        if (size <= 0)
        {
            cout << "The array size must be positive. Creating an array of the size 100. " << endl;
            maxSize = 100;
        }
        else
            maxSize = size;
        length = 0;
        list = new elemType[maxSize];
}

template <class elemType>
arrayListType<elemType> :: ~arrayListType()
{
    delete [] list;
}

template <class elemType>
const arrayListType<elemType> & arrayListType<elemType>::
        operator=(const arrayListType<elemType>& otherList)
{
    if (this != &otherList)
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];

        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}




template <class elemType>
class unorderedArrayListType: public arrayListType<elemType>
{

    public:

        void insertAt(int location, const elemType& inserItem);
        void insertEnd(const elemType& insertItem);
        void replaceAt(int location, const elemType& repItem);
        int seqSearch(const elemType& searchItem) const;
        void remove(const elemType& removeItem);



        unorderedArrayListType(int size = 100);

};




template <class elemType>
void unorderedArrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    if (this->isFull())
    {
        cout << "Cannot insert into a full list." << endl;
        return;
    }

    if (location < 0 || location > this->listSize())
    {
        cout << "Invalid location for insertion." << endl;
        return;
    }

    for (int i = this->listSize(); i > location; i--)
    {
        this->list[i] = this->list[i - 1];
    }

    this->list[location] = insertItem;
    this->length++;
}

template <class elemType>
unorderedArrayListType<elemType>::unorderedArrayListType(int size) : arrayListType<elemType>(size){}

template <class elemType>
void unorderedArrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (this->listSize() >= this->maxListSize())
        cout << "Cannot insert in a full list." << endl;
    else {
        this->list[this->listSize()] = insertItem;
        this->length++; // Increment the length using the base class's listSize() function
    }
}

template <class elemType>
int unorderedArrayListType<elemType>::seqSearch(const elemType& searchItem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < this->listSize(); loc++)
        if (this->list[loc] == searchItem)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else    
        return -1;
}


template <class elemType>
void unorderedArrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;

    if (this->listSize() == 0)
        cout << "Cannot delete from an empty list." << endl;
    else {
        loc = this->seqSearch(removeItem);

        if (loc != -1)
            this->removeAt(loc);
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
}
template <class elemType>
void unorderedArrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= this->listSize())
        cout << "The location of the item to be replaced is out of range." << endl;
    else
        this->list[location] = repItem;
}








int main(){

    unorderedArrayListType<int> intList(25);
    unorderedArrayListType<float> floatList(25);

    float flt;
    int myInt;

    cout << "Enter 5 Ints: ";

    for (int count = 0; count < 5; count++)
    {
        cin >> myInt;
        intList.insertEnd(myInt);
    }
    cout << endl;


    intList.print();
    cout << endl;

    cout << "Enter int to be deleted: ";
    cin >> myInt;
    cout << endl;

    intList.remove(myInt);
    cout << "After removing " << myInt  << " from int list" <<endl; 
    cout << "IntList: ";
    intList.print();
    cout <<endl;

    cout << "Search for the item: " ;
    cin >> myInt;
    cout << endl;

    if (intList.seqSearch(myInt) != -1)
        cout << myInt << " Found in intList" << endl;
    else
        cout << myInt << " is not in intList" << endl;





    cout << "Enter 5 floats: ";

    for (int count = 0; count < 5; count++)
    {
        cin >> flt;
        floatList.insertEnd(flt);
    }
    cout << endl;
    floatList.print();

    cout << endl;

    cout << "Enter float to be deleted: ";
    cin >> flt;
    cout << endl;

    floatList.remove(flt);
    cout << "After removing " << flt  << " from float list" <<endl; 
    cout << "floatList: ";
    floatList.print();
    cout <<endl;

    cout << "Search for the item: " ;
    cin >> flt;
    cout << endl;

    if (floatList.seqSearch(flt) != -1)
        cout << flt << " Found in floatList" << endl;
    else
        cout << flt << " is not in floatList" << endl;





    return 0;
};