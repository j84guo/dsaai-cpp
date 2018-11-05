#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Don't worry if 0% of this makes sense, I'm trying to show you how quickly
 * C++ OOP can get yi ke sai ting!
 *
 * template <typename T> means this class should be instantiated with a type
 * parameter, e.g. Stack<int>, this is so that the Stack class can work with
 * different types of data.
 *
 * Unlike Python, C++ is statically typed, so there is extra ceremony involved
 * in writing code that works with multiple types!
 */
template <typename T>
class Stack
{

public:
    Stack(int cap);
    ~Stack();
    void push(const T& data);
    T pop();

private:
    T *A;
    int size;
    int cap;
 
};

template <typename T>
Stack<T>::Stack(int cap):
    size(0),
    cap(cap)
{
    if (cap <= 0)
        throw invalid_argument("Capacity must be > 0.");

    A = new T[cap];
}

template <typename T>
Stack<T>::~Stack()
{
    if (A) {
        cout << "deleting stack" << endl;
        delete[] A;
    }
}

/**
 * fun fact #1:
 *
 * std::stack has a void pop method, you're supposed to use top() to optain a
 * const reference to an object and then call pop() when you're done with it
 * which then destroys the object in the stack's underlying container (stack is
 * composed with an underlying contained: dequeue, vector, list, etc.) so that
 *
 * 1) wasted temporary objects are not created if pop() does not require the
 *    result
 * 2) even if pop() does need the result, temporary objects should not have to
 *    be made to give the user the object
 * 3) if an exception is thrown in the copy constructor when the user pops, the
 *    object is lost (stack already modified)
 *
 *
 * fun fact #2:
 *
 * also std::stack (more accurately the underlying std::vector) does not use a
 * simple array of objects since
 *
 * 1) an array of objects created via TYPE *pt = new[TYPE] requires the type to
 *    have a default constructor
 * 2) constructing a large array of objects causes default constructors to be
 *    called many times, even if the container is initially empty
 * 3) if removed objects are explicitly destructed, calling delete[] on the
 *    array deletes the object twice, causing undefined behaviour
 * 
 * rather std::allocator is used in vector (and other containers) which
 *
 * 1) allocates a raw block of memory with enough capacity (so wasted default
 *    constructor calls are not made)
 * 2) on push, a const reference is accepted from the user and a new object is
 *    copy constructed in the allocated block in place, using IN PLACE NEW,
 *    which is the form of new allowing the location of the object to be user
 *    specified, i.e. new (ptr) TYPE(args...)
 * 3) the trick with in place new is that de-allocation should not be done via
 *    delete, rather the destructor of the object should be manually called
 *    obj_ptr->~TYPE(), the raw memory is freed by the allocator later
 */
template <typename T>
T Stack<T>::pop()
{
    if (!size)
        throw logic_error("Stack is empty.");

    return A[--size];
}

template <typename T>
void Stack<T>::push(const T& data)
{
    /** double the size of array A */
    if (size == cap) {
        cap *= 2;
        T *tmp = new T[cap];
        
        for (int i=0; i<size; ++i)
            tmp[i] = A[i];

        cout << "extending" << endl;
        delete[] A;
        A = tmp;
    }

    A[size++] = data;
}

/**
 * Don't worry if 0% of this makes sense, I'm trying to show you how quickly
 * C++ OOP can get yi ke sai ting!
 */
class Thing
{

    /**
     *  friend functions can access the private members of the class but are
     *  not member methods themselves
     *
     *  also any function / method with the keyword operator is an overloaded
     *  operator, e.g. <<, +, ==
     *
     *  it's kind of like __str__, __add__, __eq__ from Python
     */
    friend ostream& operator<<(ostream& out, const Thing &t);

/** members accessible from any class / function */
public:

    /** default constructor */
    Thing(): id(0) { }

    /** constructor accepting: int id */
    Thing(int id): id(id) { cout << "construct " << id << endl; }

    /** copy constructor (accepting a const reference) */
    Thing(const Thing &t) { this->id = t.id; cout << "copy " << id << endl; }

    /** assignment operator */
    Thing& operator=(const Thing &t) { this->id = t.id; cout << "assign " << id << endl; return *this; }

    /** destructor */
    ~Thing() { cout << "destructor " << id << endl; }

/** members accessible from this class only */
private:
    int id;
 
};

/** implementation of the friend function declared in Thing */
ostream& operator<<(ostream& out, const Thing &t)
{
    return out << "thing: " << t.id << endl;
}


int main()
{
    Stack<Thing> s(2);
    Thing t1(1);
    s.push(t1);

    cout << s.pop() << endl;
}
