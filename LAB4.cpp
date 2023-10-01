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

        void insertAt(int location, const elemType& inserItem){
            cout << "Yet to be implemented";
        }
        void insertEnd(const elemType& insertItem);
        void replaceAt(int location, const elemType& repItem);
        int seqSearch(const elemType& searchItem) const;
        void remove(const elemType& removeItem);



        unorderedArrayListType(int size = 100);

};

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

    unorderedArrayListType<string> stringList(25);

    string str;

    cout << "Line 9: Enter 5 strings: ";

    cin >> str;
    stringList.insertEnd(str);
    cin >> str;
    stringList.insertEnd(str);
    cin >> str;
    stringList.insertEnd(str);
    cin >> str;
    stringList.insertEnd(str);
    cin >> str;
    stringList.insertEnd(str);
    
    cout << endl;


    stringList.print();
    cout << endl;

    cout << "Enter string to be deleted: ";

    cin >> str;
    cout << endl;

    stringList.remove(str);
    cout << "After removeing " << str << "stringList: ";
    stringList.print();
    cout <<endl;

    cout << " Search for the item: " ;
    cin >> str;
    cout << endl;

    if (stringList.seqSearch(str) != -1)
        cout << str << " Found in stringList" << endl;

    else
        cout << str << " is not in string list" << endl;


    return 0;
};