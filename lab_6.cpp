#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*Symmetric Order:

In your job at Albatross Circus Management (yes, it's run by a bunch of clowns), 
you have just finished writing a program whose output is a list of names in nondescending 
order by length (so that each name is at least as long as the one preceding it). 
However, your boss does not like the way the output looks, and instead wants the 
output to appear more symmetric, with the shorter strings at the top and bottom 
and the longer strings in the middle. His rule is that each pair of names belongs 
on opposite ends of the list, and the first name in the pair is always in the top 
part of the list. In the first example set below, Bo and Pat are the first pair, 
Jean and Kevin the second pair, etc.

Input: The input consists of one or more sets of strings, followed by a final 
line containing only the value 0. Each set starts with a line containing an 
integer, n, which is the number of strings in the set, followed by n strings, 
one per line, sorted in nondescending order by length. None of the strings 
contain spaces. There is at least one and no more than 15 strings per set. 
Each string is at most 25 characters long.

Output: For each input set print "SET n" on a line, where n starts at 1, 
followed by the output set as shown in the sample output.*/

int main() {

int stackSize,i,j,x,count;
string name;
stack<string> names;

count = 1;

cin >> stackSize;
   while (stackSize != 0){
      cout << "SET " << count << endl;
      for (i=0; i<stackSize; ++i){
         cin >> name;
         if (i % 2 == 0){
         cout << name << endl; // print all even names
         }
         if (i % 2 != 0){
            names.push(name); // add odd names to stack
         }
      }
      x = names.size(); // size of names stack for looping
      for (j=0;j<x;j++){
         cout << names.top() << endl; // print first name in stack
         names.pop(); // remove first name in stack
      }
   count = count + 1;
   cin >> stackSize;
   }
}


