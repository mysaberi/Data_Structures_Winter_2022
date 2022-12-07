#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Stack{
    int *elements;
    int top;
    int capacity;

    public:
    Stack(int size);
    int pop();
    void push(int x);
    bool isempty();
    bool isfull();
};

Stack::Stack(int size){
    elements = new int[size];
    capacity = size;
    top = -1;
}

int Stack::pop(){
    int ans = elements[top];
    top--;
    return ans;
}

void Stack::push(int x){
    top++;
    elements[top] = x;
}

bool Stack::isempty(){
    if (top != -1)
        return false;
    return true;
}

bool Stack::isfull(){
    if (top != capacity-1)
        return false;
    return true;
}

vector<string> split(string str) {
  vector<string> input;
  stringstream ss(str);
  string t;

  while(getline(ss, t, ' ')) {
    input.push_back(t);
  }

  return input;
}

int main() {
    int n;
    string str;

    cin>> n;
    Stack stack(n);

    cin.ignore(256, '\n');
    getline(cin,str);

    vector<string> sep = split(str);


   int train [(int)sep.size()];
   int answer [(int)sep.size()];

   for(int i=0; i< (int)sep.size(); i++){
        if(sep[i]=="*"){
            train[i] = 0;
            }
        else{
            train[i] = stoi(sep[i]);
            }
    }

    int j=0;
   for(int i = (int)sep.size()-1; i>=0; i--){
       if(train[i]==0){
           if(!stack.isempty()){
               answer[j] = stack.pop();
               j++;
            }
       }
       else{
           if(stack.isfull()){
               answer[j] = train[i];
               j++;
            }
            else{
                stack.push(train[i]);
            }
        }
   }

    for(int i = j-1; i>= 0; i--){
        cout<<answer[i]<<' ';
    }

    return 0;
}
//3
//1 2 * * * 5 6 7 9 * 3 4 5 8
