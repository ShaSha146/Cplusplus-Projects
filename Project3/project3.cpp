/*
  Shyamsunder Nukala
  CSC-230-02
  Project 3
*/

#include <fstream>
#include "DLL.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;


int main(int argc, char *argv[])
{
    clock_t start, end;
    double duration;

    start = clock();

    DLL myList;
    int i_tracker = 0;
    int d_tracker = 0;
    int r_tracker = 0;
    string a, b, c, d, e; // Variables that hold the input values
    fstream input(argv[1]); // Takes the user inputs from 
    while (!input.eof())
    { 
        input >> a >> b >> c >> d; // Assigns the inputs to variables
        string e =  c + " " + d;
        if(a=="i")
        {
            //cout<<a<<endl;
            //cout << b<< " "<< e <<endl;
            myList.insert(b, e, i_tracker);
            //cout << b<< " "<< e <<endl;
            //cout<<endl;
        }
        else if(a=="d")
        {
            //cout<<a<<endl;
            //cout << b<< " "<< e <<endl;
            myList.remove(b, d_tracker);
            //cout << b<< " "<< e <<endl;
            //cout<<endl;
        }
        else if(a=="r")
        {
            //cout<<a<<endl;
            //cout << b<< " "<< e <<endl;
            if(myList.search(b) > -1)
            {
              r_tracker++;
            }
            //cout << b<< " "<< e <<endl;
            //cout<<endl;
        }
        if(!input) break; 
    }

    // myList.insert("527033775", "ODILIA DEMMAN", i_tracker);
    // myList.insert("527033775", "ODILIA DEMMAN", i_tracker);
    // myList.insert("201479024", "NADIA NAGODE", i_tracker);
    // myList.insert("595221242", "ILA HOCKLEY", i_tracker);
    // myList.insert("289086026", "TAMEKIA COLPETZER", i_tracker);
    //myList.display();
    cout << "The Number of Valid Insertation :"<<i_tracker<<endl;
    cout << "The Number of Valid Deletion :"<<d_tracker<<endl;
    cout << "The Number of Valid Retrieval :"<< r_tracker<<endl;
    cout << "Item numbers in the list :"<<myList.size()<<endl;

    end = clock();
    duration = ( end - start ) / (double) CLOCKS_PER_SEC;

    cout<<"elapsed time: "<< duration <<'\n';
    return 0;
}
