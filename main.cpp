/*
  Author:          Mohammad Seeam
  Topic:           pointers, objects in memory: stack, heap; data structures 
  Purpose:
  Show understanding of objects in memory using: values, addresses, pointers, stack, heap;
  dynamic memory allocation using new, delete, delete []. Get introduction to linked data structures
  using a singly linked list.

  Use C++ to construct a memory layout as shown in a specified memory diagram.
  Use startup code with useful macros to display variables: names, values, addresses.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class Number { 
  public:
    string name;     // name of the Number
    Number *next;    // pointer to the next Number

    //default constructor
    Number(){}

    //custom constructor
    Number(string n){
      name = n;
      next = nullptr;
    }
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own to do something similar
#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<endl;

#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_name_addr_value(var) \
  cout<<"name: "<<#var<<"  address: &"<<&var<<"  value: " << var << endl;

#define show_name_addr_value_deref(var) \
  cout<<"name: "<<#var<<"  address: &"<<&var<<"  value: " << var \
      << "  *" << #var << ": " << *var << endl;

int main () {
  cout << "Output from Lab 10 memory diagram on pointers:\n\n";

  //test
  char   garbage_c;
  short  garbage_s;
  int    garbage_i = 166;
  float  garbage_f;
  double garbage_d =  2.07494e-317;
  show_name_addr_value(garbage_c);
  show_name_addr_value(garbage_s);
  show_name_addr_value(garbage_i);
  show_name_addr_value(garbage_f);
  show_name_addr_value(garbage_d);
  cout << endl;

  //price
  float price = 0;
  float* p_price = &price;
  *p_price = 12.95;
  show_addr_value(price, 8);
  show_addr_value(p_price, 8);
  //show_name_addr_value_deref(p_price);
  cout << "The contents of *p_price is: " << *p_price << endl;
  cout << endl;

  //PI
  double PI = 3.1416;
  double PI_div_2 = 0.0;
  double* p_PI = &PI;
  PI_div_2 = (*p_PI/2);
  show_addr_value(PI, 8);
  show_addr_value(PI_div_2, 8);
  show_addr_value(p_PI, 8);
  //show_name_addr_value_deref(p_PI);
  cout << "The contents of *p_PI is: " << *p_PI << endl;  //deref example
  cout << endl;

  //ACCeID
  int ACCeID = 2214646;
  int* p_ACCeID = &ACCeID;
  show_addr_value(ACCeID, 8);
  show_addr_value(p_ACCeID, 8);
  cout<<"The contents of *p_ACCeID is: "<< *p_ACCeID<<endl;
  cout << endl;
  
  //p_amount
  int* p_amount = new int;
  *p_amount = 1918;
  show_addr_value(p_amount, 8);
  cout << "The contents of *p_amount is: " << *p_amount << endl;
  delete p_amount;
  cout << "After delete, the contents of p_amount is: "<< p_amount << endl;
  p_amount = nullptr;
  cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;
  cout << endl;

  //pArray1
  int *pArray1 = new int(3);
  pArray1[0] = 101;
  pArray1[1] = 202;
  pArray1[2] = 303;
  show_addr_value(pArray1, 8);
  show_addr_value(pArray1[0], 8);
  show_addr_value(pArray1[1], 8);
  show_addr_value(pArray1[2], 8);
  delete pArray1;
  cout << "After delete [], the contents of pArray is: " << pArray1 << endl;
  pArray1 = nullptr;
  cout << "After reset to nullptr, the contents of pArray1 is: " << pArray1 << endl;
  cout << endl;

  //pArray2
  int Array2[2] = {1001, 2002};
  int* pArray2 = &Array2[0];
  show_addr_value(pArray2, 8);
  show_addr_value(pArray2[0], 8);
  show_addr_value(pArray2[1], 8);
  cout << "No need to delete Array2, it is on the stack, not the heap" << endl;
  cout << endl;

  //big_buffer
  int array_size = 2214646;
  double *big_buffer = new double(array_size);
  double* buffer_end =nullptr;
  char *p = (char*) big_buffer;
  p = p + (sizeof(double) * (array_size));
  buffer_end = (double*) p;
  show_addr_value(big_buffer, 8);
  show_addr_value(buffer_end, 8);
  cout << "After delete [], the contents of big_buffer is: " << big_buffer << endl;
  big_buffer = nullptr;
  cout << "After reset to nullptr, the contents of big_buffer is: " << big_buffer << endl;
  cout<<endl;

  //Number emptyList
  Number* emptyList = nullptr;
  show_addr_value(emptyList, 8);
  cout << endl;

  //Number zed
  Number zed ("zero"); 
  cout<<"static (uses: Number zed):\n";
  show_addr(zed, 8);
  show_addr_value(zed.name, 8);
  show_addr_value(zed.next, 8);
  cout << endl;

  //Number p_natural
  Number* p_natural = new Number();  //go to heap and allocate Number size of memory
  p_natural->name = "two"; //first digit of my ACCeID is 2 ; AcCCeID:m2214646
  Number* next_obj = new Number();
  next_obj->name = "two"; //second digit of my ACCeID is 2
  p_natural->next = next_obj;  //join two Number nodes
  cout << "dynamic (uses: p_natural, Number(\"two\"), Number(\"two\"):" << endl;
  show_addr_value(p_natural, 8);
  show_addr_value(p_natural->name, 8);
  show_addr_value(p_natural->next, 8);
  cout << "<follow link to next Number on p_natural>" << endl;
  show_addr_value(p_natural->next->name, 8);
  show_addr_value(p_natural->next->next, 8);
  cout << endl;

  return 0;
  
} // end of main

/*
Output from Lab 10 memory diagram on pointers:

name: garbage_c  address: &  value: 
name: garbage_s  address: &0x16dd07488  value: 0
name: garbage_i  address: &0x16dd07484  value: 166
name: garbage_f  address: &0x16dd07480  value: 0
name: garbage_d  address: &0x16dd07478  value: 2.07494e-317

address of price    is: &0x16dd07474  contents of price    is: 12.95
address of p_price  is: &0x16dd07468  contents of p_price  is: 0x16dd07474
The contents of *p_price is: 12.95

address of PI       is: &0x16dd07450  contents of PI       is: 3.1416
address of PI_div_2 is: &0x16dd07448  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0x16dd07440  contents of p_PI     is: 0x16dd07450
The contents of *p_PI is: 3.1416

address of ACCeID   is: &0x16dd07424  contents of ACCeID   is: 2214646
address of p_ACCeID is: &0x16dd07418  contents of p_ACCeID is: 0x16dd07424
The contents of *p_ACCeID is: 2214646

address of p_amount is: &0x16dd07400  contents of p_amount is: 0x13c6068f0
The contents of *p_amount is: 1918
After delete, the contents of p_amount is: 0x13c6068f0
After reset to nullptr, the contents of p_amount is: 0x0

address of pArray1  is: &0x16dd073e8  contents of pArray1  is: 0x13c6068f0
address of pArray1[0] is: &0x13c6068f0  contents of pArray1[0] is: 101
address of pArray1[1] is: &0x13c6068f4  contents of pArray1[1] is: 202
address of pArray1[2] is: &0x13c6068f8  contents of pArray1[2] is: 303
After delete [], the contents of pArray is: 0x13c6068f0
After reset to nullptr, the contents of pArray1 is: 0x0

address of pArray2  is: &0x16dd073b8  contents of pArray2  is: 0x16dd07490
address of pArray2[0] is: &0x16dd07490  contents of pArray2[0] is: 1001
address of pArray2[1] is: &0x16dd07494  contents of pArray2[1] is: 2002
No need to delete Array2, it is on the stack, not the heap

address of big_buffer is: &0x16dd07390  contents of big_buffer is: 0x13c704080
address of buffer_end is: &0x16dd07388  contents of buffer_end is: 0x13d7e9830
After delete [], the contents of big_buffer is: 0x13c704080
After reset to nullptr, the contents of big_buffer is: 0x0

address of emptyList is: &0x16dd07358  contents of emptyList is: 0x0

static (uses: Number zed):
address of zed      is: &0x16dd07328
address of zed.name is: &0x16dd07328  contents of zed.name is: zero
address of zed.next is: &0x16dd07340  contents of zed.next is: 0x0

dynamic (uses: p_natural, Number("two"), Number("two"):
address of p_natural is: &0x16dd072e8  contents of p_natural is: 0x13c704090
address of p_natural->name is: &0x13c704090  contents of p_natural->name is: two
address of p_natural->next is: &0x13c7040a8  contents of p_natural->next is: 0x13c7040b0
<follow link to next Number on p_natural>
address of p_natural->next->name is: &0x13c7040b0  contents of p_natural->next->name is: two
address of p_natural->next->next is: &0x13c7040c8  contents of p_natural->next->next is: 0x0
*/
