  //cout<< (12>4 ? true:false) ;
   //if 12 is greater than 4 then return true, else return false
#include<iostream>
#include <fstream>
#include "map.h"
#include "Tracker.h"
using namespace std;

int main()
{
   map m1;
  // m1.Print();
   map* m = &m1;
  
   //tracker maintains a pointer to map object
   Tracker t1(m);

   cout<<"\n";
    system("pause");   
 }