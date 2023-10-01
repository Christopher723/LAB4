#include <iostream>


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
    bool isItemAtEqual*int location, const elemType& item) const;
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







int main(){




    return 0;
}