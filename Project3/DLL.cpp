#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor is already implemented
// do not modify the default constructor
DLL::DLL(){
    headPtr = nullptr;
    itemCount=0;
}

// return the head pointer of the list
// it is already implemented, do not modify it
Node* DLL::getHeadPtr(){
    return headPtr;
}

// copy construct, which copies an existing list n
// the new list is a different object from n
// the new list and object n have the same contents
// Please implement it
DLL::DLL(DLL& n){
    this->headPtr = nullptr;
    Node* temp = n.getHeadPtr();
    while(temp != nullptr)
    {
        string ss =  temp->ssn;
        string name = temp->name;
        // 1. list is empty
        if(this->headPtr ==nullptr) // Check if there is a head node otherwise creates one with inputs 
        {
            Node* head = new Node;
            head->ssn = ss;
            head->name = name;
            this->headPtr = head;
            itemCount++;
        }
        // 4. node should be inserted to the end of the list
        else // All nodes added are already in ascending order and will be added to end
        { 
            Node * end =  new Node;
            end = this->headPtr;
            while(end->succ!=nullptr) // finds last exsisting node
            {
                end = end->succ;
            }
            Node* inserter = new Node; // Creates new Node and adds it to end of list
            inserter->ssn= ss;
            inserter->name= name;
            inserter->pred = end;
            inserter->succ = nullptr;
            end->succ=inserter;
            itemCount++;
        }
        temp = temp->succ;
    }
}

// destructor
// release every node of the list
// Please implement it
DLL::~DLL(){
    Node* temp = new Node;
    temp = this->headPtr;
    while (temp!= nullptr) {
        delete temp;
        temp = temp->succ;
    }
}

// if some node has SSN matcthes string ss
// return the index value of the node
// the index value of the first node is 0, the second node is 1, etc.
// if there is node matching ss, return -1
int DLL::search(string ss)const{
    Node* searcher = new Node;
    searcher = this->headPtr;
    int index = 0;
    while (searcher!= nullptr) { // Goes to through list until end found
        //cout << searcher->ssn<<endl;
        if(searcher->ssn == ss) // If match found returns index
        {
            return index;
        }
        searcher = searcher->succ; // If no match found moves to next node and increases count of index
        index++;
    }
    return -1;
}


// insert (ss, name) to the existing list
// the SSN values are each node are organized in INCREASING order
// if there is a node matching ss value, return false; otherwise true
// else create a node with (ss, name), insert the node to the proper position
// parameter count is the counter of number of valid insertion
// when you implement this method, consider the following situations:
// 1. list is empty
// 2. node should be inserted to the beginning of the list
// 3. node should be inserted to the middle of the list
// 4. node should be inserted to the end of the list
bool DLL::insert(string ss, string name, int & count){

    // 1. list is empty
    if(this->headPtr == nullptr) // If no head node exsists creates one with inputs
    {
        Node* head = new Node;
        head->ssn = ss;
        head->name = name;
        this->headPtr = head;
        count++;
        itemCount++;
        //cout << head->ssn <<endl;
        return true;
    }
    // 2. node should be inserted to the beginning of the list
    if(this->headPtr->ssn>ss) // If inserted value less than heads
    { 
        Node* insertor = new Node; // Creates new node that copies head values
        insertor->name = this->headPtr->name;
        insertor->ssn = this->headPtr->ssn;
        insertor->succ = this->headPtr->succ;
        insertor->pred = this->headPtr;
        this->headPtr->ssn = ss; // Gives head node the input values
        this->headPtr->name = name;
        this->headPtr->succ = insertor; // Inserts new node with orignal head values after head node 
        count++;
        itemCount++;
        //cout << insertor->ssn <<endl;
        return true;
    }
    // 3. node should be inserted to the middle of the list
    Node * mover =  this->headPtr;
    while(mover!=nullptr) // Moves through list until end reached
    {
        if(mover->ssn==ss) // If ssn already exsists exits
        {
            return false;
        }
        if(mover->ssn>ss) // If node with larger ssn found creates new node with inputs and inserts before found node
        {
            Node* insertor = new Node; 
            insertor->ssn = ss;
            insertor->name = name;
            insertor->succ = mover;
            insertor->pred = mover->pred;
            mover->pred->succ = insertor;
            mover->pred = insertor; 
            count++;
            itemCount++;
            //cout << insertor->ssn <<endl;
            return true;
        }
        mover = mover->succ; // Else moves to next node
    }
    // 4. node should be inserted to the end of the list
    Node * end =  new Node;
    end = this->headPtr;
    while(end->succ!=nullptr) // If no node with same or greater ssn found goes through list until end reached
    {
        end = end->succ; 
    }
    Node* inserter = new Node; // Creates new node with inputs
    inserter->ssn= ss; 
    inserter->name= name;
    inserter->pred = end;
    inserter->succ = nullptr;
    end->succ=inserter; // Inserts new node at end of list
    count++;
    itemCount++;
    //cout << end->ssn <<endl;
    return true;
}


// remove node containing ss value
// if there is no node containing ss, return false; otherwise true
// consider the following situations:
// 1. list is empty
// 2. node containing ss value is the first node
// 3. node containing ss value is in the middle of the list
// 4. node containing ss value is the last node of the list
bool DLL::remove(string ss, int & count){
    // 1. list is empty
    if(this->headPtr==nullptr) // If no head node exsist exits 
    {
        return false;
    }
    // 2. node containing ss value is the first node
    if(this->headPtr->ssn == ss) // If the head node is to be removed 
    {
        if(this->headPtr->succ != nullptr) // If more nodes after head node
        {
            Node* temp = this->headPtr->succ; // Creates new node copies properties of node after head
            temp->name = this->headPtr->succ->name;
            temp->ssn = this->headPtr->succ->ssn;
            temp->pred = this->headPtr->succ->pred;
            temp->succ = this->headPtr->succ->succ;
            if(temp->succ != nullptr) // If node exsists after head node's next node
            {
                temp->succ->pred = this->headPtr; // Set this node to be after head node
            }
            this->headPtr->succ = temp->succ; // Replaces head node values with values of node after head 
            this->headPtr->name = temp->name;
            this->headPtr->ssn = temp->ssn;
            delete temp; // Deletes node after head node
            count++;
            itemCount--;
            return true;
        }
        else // If head node is the only node deletes it
        {
            Node* temp = this->headPtr;
            delete temp;
            this->headPtr = nullptr;
            count++;
            itemCount--;
            return true;
        }
        
    }
    // 3. node containing ss value is in the middle of the list
    Node* mover =  this->headPtr; 
    while(mover->succ != nullptr) // Moves through list until end reached
    {
        if(mover->ssn == ss) // if node to be removed is found 
        { // Set its previous node's next node to be removed node's next node
            mover->pred->succ = mover->succ; 
            mover->succ->pred = mover->pred;
            delete mover;
            count++;
            itemCount--;
            return true;
        }
        mover = mover->succ;
    }
    // 4. node containing ss value is the last node of the list
    Node * end = this->headPtr;
    while(end->succ!=nullptr) // Moves through list until last node found
    {
        end = end->succ;
    }
    if(end->ssn == ss) // If last node is the node to be removed 
    { // Delete the last node
        end->pred->succ = nullptr; 
        delete end;
        count++;
        itemCount--;
        return true;
    }
    return false;

}

// return the number of the nodes
// it is already implemented, do not modify it
int DLL::size(){
    
    return itemCount;
}

// iterate through each node
// print out SSN and memory address of each node
// do not modify this method
void DLL::display(){
    Node* temp;
    temp = headPtr;
    while (temp!= nullptr) {
        cout << temp->ssn << "\t" << temp << endl;
        temp = temp->succ;
    }
}
