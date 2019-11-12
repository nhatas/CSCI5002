#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

/*Phone List

Given a list of phone numbers, determine if it is consistent in the s
ense that no number is the prefix of another. Let's say the phone catalog listed these numbers:

Emergency 911
Alice 97 625 999
Bob 91 12 54 26
In this case, it's not possible to call Bob, because the central would direct your call 
to the emergency line as soon as you had dialed the first three digits of Bob's phone 
number. So this list would not be consistent.

Input: The first line of the input gives a single integer, 1≤t<40, the number of test 
cases. Each test case starts with n, the number of phone numbers, on a separate line, 
1<n<10000. Then follows n lines with one unique phone number on each line. A phone 
number is a sequence of at most ten digits.

Output: For each test case, output "YES" if the list is consistent, or "NO" otherwise.*/

int main() {

vector <string> numbers;
int lines, cases, i , j;
string number, firstNum;

cin >> cases;
i=0;
while (i < cases) {
   cin >> lines;
   for (j=0; j<lines; j++) {
      cin >> number;
      numbers.push_back(number); // add numbers to vector
   }
   sort (numbers.begin(), numbers.end()); // sort numbers in vector
   firstNum = numbers.front(); // first number in vector
   
   /*int result = std::find(vector.begin(), vector.end(), item) != vector.end()
   
   if (result == -1) 
      cout << firstNum << " not found" << endl;
   else
      cout << firstNum << " found" << endl;*/
   i++;

int timesFound = 0; // how many times a prefix is found
int numSize = numbers.size(); // size of numbers vector
for (int l=0;l<numSize;l++) {
   for (auto i = numbers.begin(); i != numbers.end(); ++i) { // iterate through numbers vector
      string numString = *i;
      string numString2 = numbers[l];
      if (numString != numString2) { // make sure two strings being compared aren't identical
         //cout << numString << " compared to " << numString2 << endl;
         //if(strstr(numString.c_str(),numString2.c_str()))
         if (numString.rfind(numString2, 0) == 0) // if both strings begin the same
            timesFound = timesFound + 1; // increase timesFound
      }
   }
}
if (timesFound >= 1) // duplicate prefix exists
   cout << "NO" << endl;
else
   cout << "YES" << endl;
   
numbers.clear();
timesFound = 0;

}   
}
