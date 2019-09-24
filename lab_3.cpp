#include <iostream>
using namespace std;

/*
Bill and Ted are taking a road trip. But the odometer in their car is broken, so they don't know how many miles they have driven. 
Fortunately, Bill has a working stopwatch, so they can record their speed and the total time they have driven. Unfortunately, 
their record keeping strategy is a little odd, so they need help computing the total distance driven. You are to write a program 
to do this computation.

For example, if their log shows

| Speed in miles per hour | Total elapsed time in hours | | 20 | 2 | | 30 | 6 | | 10 | 7 |

this means they drove 2 hours at 20 miles per hour, then 6-2=4 hours at 30 miles per hour, 
then 7-6=1 hour at 10 miles per hour. The distance driven is then (2)(20) + (4)(30) + (1)(10) = 40 + 120 + 10 = 170 miles. 
Note that the total elapsed time is always since the beginning of the trip, not since the previous entry in their log.

Input: The input consists of one or more data sets. Each set starts with a line containing an integer n, 1 ≤ n ≤ 10, 
followed by n pairs of values, one pair per line. The first value in a pair, s, is the speed in miles per hour and the 
second value, t, is the total elapsed time. Both s and t are integers, 1 ≤ s ≤ 90 and 1 ≤ t ≤ 12. The values for t are 
always in strictly increasing order. A value of -1 for n signals the end of the input.

Output: For each input set, print the distance driven, followed by a space, followed by the word "miles".
*/

int main() {
   int x, speed, time, miles; // initialize variables
   cin >> x; // user input 
   while (x != -1) { // infinite loop, broken when program input is -1
      int speedarray [x]; // speed array
      int timearray [x]; // time array
      int sum = 0; // initializing sum equal to 0
      for (int i = 0; i < x; ++i) { // for loop to calculate distance driven given speed and time inputs
         cin >> speed >> time; // speed and time user input
         speedarray [i] = speed; // add speed to speed array
         timearray [i] = time; // add time to time array
         if (i == 0) { // if statement to account for initial time
            time = timearray [i];
         }
         if (i > 0) { // if statement for subsequent time
            time = timearray[i] - (timearray[i-1]); // calculate new time (current time minus previous time)
         }
         //cout << time << endl; // print to check new time
         miles =  speedarray [i] * time; // calc miles
         //cout << miles << endl; // print to check miles
         sum = sum + miles; // calc new sum of miles
      }
      cin >> x; // next input
   cout << sum << " miles" << endl; // print final calculated distance driven in miles
   }
   return 0;
}
