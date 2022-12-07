#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 1000

class Stack{
    public:
    int *elements;
    int top;
    int capacity;



    Stack(int size = SIZE){
        elements = new int[size];
        capacity = size;
        top = -1;
    }


    bool isempty(){
        if (top != -1)
            return false;
        return true;
    }

    bool isfull(){
        if (top != capacity-1)
            return false;
        return true;
    }

    int pop(){
        if (isempty()){
                cout<<"stack is empty";

        }
        else {
            int ans = elements[top];
            top--;
            return ans;
        }
    }

    void push(int x){
        if (isfull()){
            cout<<"stack is full";

        }
        else{
            top++;
            elements[top] = x;
        }
    }



};




class Queue{

    Stack s1,s2;

    public:

    Queue(){

    }

     bool issempty(){
        if(s1.isempty() && s2.isempty()){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        s1.push(x);
    }

    int dequeue(){
        if (issempty()){
            cout<< "Queue is empty"<<endl;
            exit(1);
        }
        if (s2.isempty()){
            while(!s1.isempty()){
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    int q_size(){
        return s1.top+s2.top+2;
    }

    void contains(){
        cout<<"This queue contains:\n";
        for( int i = s2.top; i>=0 ; i--){
            cout<<s2.elements[i]<<endl;
        }

        for(int i = 0 ; i<=s1.top; i++){
            cout<<s1.elements[i]<<endl;
        }
        cout<<"-------------\n";
    }

};





int main() {


   Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.contains();

    cout << q.dequeue() << '\n';

    q.enqueue(4);
    cout<< q.q_size()   << '\n';
    q.contains();
    return 0;
}
