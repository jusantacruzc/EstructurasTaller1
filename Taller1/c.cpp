// made by Esteban Santacruz (https://github.com/Jestebansamt)

#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Node{
public:
    T data;
    Node* next;

public:
    Node(T data) : data(data), next(nullptr) {}

};
template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    bool empty(){
        if(head == nullptr) return 1;
         return 0;
    }
    
    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        if(tail == nullptr) tail = head;
    }
    
    void pop_front(){
        if(empty())
            throw runtime_error("LinkedList is empty");
        head= head->next;
        if(empty())
            tail = nullptr;
    }

    void push_back(T data){
        Node<T>* newNode = new Node<T>(data); 
        if(tail == nullptr) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }

    void pop_back(){
        Node<T>* temp = new Node<T>(0);
        if(empty()) 
            throw runtime_error("LinkedList is empty");
        else if(head == tail){
            head = nullptr;
            tail = nullptr;
        }else{
            temp = head;
            while(temp->next->next != nullptr){
                temp= temp->next;
            }
            temp->next = nullptr;
            tail = temp;
        }

    }

    void printList(){
        Node<T>* temp = head;
        if(empty())
            throw runtime_error("LinkedList is empty");
        while(temp != nullptr){
            cout << temp->data << "";
            temp= temp->next;
        }
    }
    
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, cstr, stre;
    LinkedList<string> ans;
    bool end = 1;
    while(getline(cin, stre)){
        for(auto&c: stre){
            if(c == '['){
                if(cstr != "") ans.push_front(cstr);
                end = 0;
                cstr = "";
            }else if(c == ']'){
                end = 1;
            }else if(end){
                str += c;
            }
            else {
                cstr += c;
            }
        }
        if(cstr != "") ans.push_front(cstr);
        if(!ans.empty()) ans.printList();
        cout << str << "\n";
        str="", cstr="";end = 1;
        while(!ans.empty()){ 
            ans.pop_front();
        }

    }
    return 0;
}