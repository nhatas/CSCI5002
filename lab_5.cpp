#include <iostream>
using namespace std;

/*Doubles

As part of an arithmetic competency program, your students will be given randomly generated 
lists of from 2 to 15 unique positive integers and asked to determine how many items in each 
list are twice some other item in the same list. You will need a program to help you with the 
grading. This program should be able to scan the lists and output the correct answer for each 
one. For example, given the list 1 4 3 2 9 7 18 22 your program should answer 3, as 2 is twice 
1, 4 is twice 2, and 18 is twice 9.

The input file will consist of one or more lists of numbers. There will be one list of numbers 
per line. Each list will contain from 2 to 15 unique positive integers. No integer will be larger 
than 99. Each line will be terminated with the integer 0, which is not considered part of the list. 
A line with the single number -1 will mark the end of the file. The example input below shows 3 
separate lists. Some lists may not contain any doubles.

The output will consist of one line per input list, containing a count of the items that are double some other item.*/

int main()
{
    int i,j,n,count,a[20];
    cin >> a[0];
    while(a[0] != -1)
    {
       n=1;
       for ( ; ; n++)
       {
          cin >> a[n];
          if (a[n] == 0) break;
       }
       
       count = 0; // counter
       for (i=0; i<n-1; i++)
       {
          for (j=i+1; j<n; j++)
          {
             if (a[i]*2 == a[j] || a[j]*2 == a[i]) // pairwise comparison of integers to check for doubles
             count++;
          }
       }
       cout << count << endl;
       cin >> a[0];
    }

    return 0;
}
