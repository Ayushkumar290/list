#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data = val;
        next = nullptr;
    }

};
class list{
    private:
    Node*head ;
    public:
    list(){
        head= nullptr;
    }

    void insert_at_begin(int val){
        
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }
    void insert_at_kpoint(int val,int pos){
        if (pos <= 1) {  
            insert_at_begin(val);
            return;
        }
        Node* current = head;
        for(int i =1; current != nullptr && i<pos-1;i++){
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        } 
        Node* newnode = new Node(val);
        newnode->next = current->next;
        current->next = newnode;

    }
    void insert_at_end(int val){
        Node* current = head;
        while (current != nullptr && current->next != nullptr){
            current = current->next;
        }
        Node* newnode = new Node(val);
        current->next = newnode;
        newnode->next = nullptr;
    }
    void delete_At_begin(){
            Node* to_delete = head;
            
            if(!head)return;
            head = head->next;
            delete to_delete;

    }
    void delete_At_kthpos(int pos){
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 1) {
            delete_At_begin();  // If position is 1, just delete the first node
            return;
        }

        Node* current = head;
        for(int i =1; current != nullptr && i<pos-1;i++){
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        Node* todelete = current->next;
        current->next = current->next->next;
        delete todelete;

    }
    void delete_at_end(Node*head){
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* newnode = head;
        Node* current = head;
        while(current->next != nullptr &&current->next->next != nullptr){
            current = current->next;
        }
        newnode = current->next;
        current->next =nullptr;
        delete newnode;
    }
    void display(){
        if(!head)return;
        Node*current = head;
        while(current){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }


};

int main(){
    list N1;
    N1.insert_at_begin(1);
    N1.insert_at_begin(4);
    N1.insert_at_begin(6);
    N1.insert_at_begin(2);
    N1.display();
    N1.delete_At_kthpos(2);
    N1.display();
    N1.insert_at_kpoint(10,2);
    N1.insert_at_kpoint(16,4);
    N1.display();
    N1.delete_At_begin();
    N1.display();


    return 0;
};