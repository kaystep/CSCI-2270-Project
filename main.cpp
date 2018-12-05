// C++ implementation of De-queue using circular
// array
#include<iostream>
#include<string>
using namespace std;

// Maximum size of array or Dequeue
#define MAX 100

// A structure to represent a Deque
class Deque
{
    int  arr[MAX];
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Operations on Deque:
    void  insertfront(const char letter);
    void  insertrear(const char letter);
    void  deletefront();
    void  deleterear();
    bool  isFull();
    bool  isEmpty();
    char  getFront();
    char  getRear();
    char  printDeque();
};

// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}

// Inserts an element at front
void Deque::insertfront(const char letter)
{
    // check whether Deque if  full or not
    if (isFull())
    {
        cout << "Overflow\n" << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

        // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;

    else // decrement front end by '1'
        front = front-1;

    // insert current element into Deque
    arr[front] = letter ;
}

// function to inset element at rear end
// of Deque.
void Deque ::insertrear(const char letter)
{
    if (isFull())
    {
        cout << " Overflow\n " << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

        // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;

        // increment rear end by '1'
    else
        rear = rear+1;

    // insert current element into Deque
    arr[rear] = letter ;
}

// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << "Queue Underflow\n" << endl;
        return ;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
    if (front == size -1)
        front = 0;

    else // increment front by '1' to remove current
        // front value from Deque
        front = front+1;
}

// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << " Underflow\n" << endl ;
        return ;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}

// Returns front element of Deque
char Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    char W = static_cast<char>(arr[front]);
    return W;
}

// function return rear element of Deque
char Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }

    char W = static_cast<char>(arr[rear]);
    return W;
}

char Deque::printDeque() {
    for (int i = 0; i < 16; i++) {
        if (arr[i] == '\0') {
            break;
        }
        char nucleic_acid = static_cast<char>(arr[i]);
        cout << nucleic_acid << " ";
    }
}

// Driver program to test above function
int main()
{
    Deque strand1(15);
    Deque strand2(15);
    char strandOneToInsert[15] = "ACGTTCGA";
    char strandTwoToInsert[15] = "TACAGGCT";
    int i = 0;
    int j = strlen(strandTwoToInsert) - 1;
    int halfway;
    //check for odd halfway point division or not because C++
    cout << j << endl;
    if (j % 2 == 0) {
        halfway = (j / 2);
    }
    else {
        halfway = (j+1)/2;
    }
    cout << halfway << endl;
    while (i < halfway ) {
        strand1.insertfront(strandOneToInsert[i]);
        strand1.insertrear(strandOneToInsert[j]);
        strand2.insertfront(strandTwoToInsert[i]);
        strand2.insertrear(strandTwoToInsert[j]);
        if (strand1.getFront() == 'A' && strand2.getFront() != 'T') {
            cout << "There is a mutation at point " << i << " in DNA Strand # 1" << endl;
        }
        if (strand1.getFront() == 'C' && strand2.getFront() != 'G') {
            cout << "There is a mutation at point " << i << " in DNA Strand # 1" << endl;
        }
        if (strand1.getFront() == 'G' && strand2.getFront() != 'C') {
            cout << "There is a mutation at point " << i << " in DNA Strand # 1" << endl;
        }
        if (strand1.getFront() == 'T' && strand2.getFront() != 'A') {
            cout << "There is a mutation at point " << i << " in DNA Strand # 1" << endl;
        }
        if (strand1.getRear() == 'A' && strand2.getRear() != 'T') {
            cout << "There is a mutation at point " << j << " in DNA Strand # 1" << endl;
        }
        if (strand1.getRear() == 'C' && strand2.getRear() != 'G') {
            cout << "There is a mutation at point " << j << " in DNA Strand # 1" << endl;
        }
        if (strand1.getRear() == 'G' && strand2.getRear() != 'C') {
            cout << "There is a mutation at point " << j << " in DNA Strand # 1" << endl;
        }
        if (strand1.getRear() == 'T' && strand2.getRear() != 'A') {
            cout << "There is a mutation at point " << j << " in DNA Strand # 1" << endl;
        }
        i++;
        j--;
    }
    return 0;
}