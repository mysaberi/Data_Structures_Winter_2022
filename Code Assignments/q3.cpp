#include <iostream>
#include <math.h>

using namespace std;

class Queue
{
    int n;
    int s;
    int *arr;

public:
    Queue(int size,int number)
    {
        s = size;
        n = number;
        arr = new int[s*n+2*n];

        for (int i=s*n; i<n*s+2*n;i++)
            arr[i]=-1;
    }

    void enQueue(int k, int value)
{
    int front = arr[n*s+2*(k-1)];
    int rear = arr[n*s+2*(k-1)+1];

    if ((front == 0 && rear == s-1) || (front == rear+1))
    {
        cout<< k << "-th queue is Full\n";
        return;
    }

    else if (front == -1)
    {
        front = rear = 0;
        arr[rear+(k-1)*s] = value;
    }

    else if (rear == s-1 && front != 0)
    {
        rear = 0;
        arr[(k-1)*s] = value;
    }

    else
    {
        rear++;
        arr[rear+(k-1)*s] = value;
    }
    arr[n*s+2*(k-1)] = front;
    arr[n*s+2*(k-1)+1] = rear;
}

int deQueue(int k)
{
    int front = arr[n*s+2*(k-1)];
    int rear = arr[n*s+2*(k-1)+1];

    if (front == -1)
    {
        cout<< k << "-th queue is Empty\n";
        return pow(-10,10);
    }

    int data = arr[front+(k-1)*s];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == s-1)
        front = 0;
    else
        front++;

    arr[n*s+2*(k-1)] = front;
    arr[n*s+2*(k-1)+1] = rear;

    return data;
}

void displayQueue(int k)
{
    int front = arr[n*s+2*(k-1)];
    int rear = arr[n*s+2*(k-1)+1];;
    if (front == -1)
    {
        cout<< k << "-th queue is Empty\n";
        return;
    }
    cout<<"Queue "<<k<<" contains\n";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<< arr[i+(k-1)*s]<<endl;
    }
    else
    {
        for (int i = front; i < s; i++)
           cout<< arr[i+(k-1)*s]<<endl;

        for (int i = 0; i <= rear; i++)
            cout<< arr[i+(k-1)*s]<<endl;
    }

    cout<<"-------------"<<endl;
}

bool isEmpty(int k){
    int front = arr[n*s+2*(k-1)];
    if (front == -1 ){
     return true;
    }
    return false;
}

};





int main()
{
    Queue q(3,3);
    cout<<q.isEmpty(1)<<endl;
    cout<<q.isEmpty(2)<<endl;
    cout<<q.isEmpty(3)<<endl;
    q.enQueue(1,11);
    q.enQueue(1,22);
    q.enQueue(1,33);
    q.enQueue(1,44);
    q.enQueue(2,13);
    q.enQueue(3,-3);
    q.enQueue(3,-2);
    q.enQueue(3,-6);

    cout<<q.isEmpty(1)<<endl;
    cout<<q.isEmpty(2)<<endl;
    cout<<q.isEmpty(3)<<endl;

    q.displayQueue(1);
    q.displayQueue(2);
    q.displayQueue(3);

    q.deQueue(1);
    q.displayQueue(1);
    q.enQueue(1,44);
    q.displayQueue(1);
    q.deQueue(1);
    q.deQueue(1);
    q.deQueue(1);
    q.displayQueue(1);
    cout<<q.isEmpty(1)<<endl;

    cout<<endl;

       return 0;
}
