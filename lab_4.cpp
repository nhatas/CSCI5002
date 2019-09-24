#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
Tan Your Hide, Inc., owns several coin-operated tanning salons. Research has shown that if a customer arrives and there are no beds available, the customer will turn around and leave, thus costing the company a sale. Your task is to write a program that tells the company how many customers left without tanning.

The input consists of data for one or more salons, followed by a line containing the number 0 that signals the end of the input. Data for each salon is a single line containing a positive integer, representing the number of tanning beds in the salon, followed by a space, followed by a sequence of uppercase letters. Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer, the second indicates the departure of that same customer. No letter will occur in more than one pair. Customers who leave without tanning always depart before customers who are currently tanning. There are at most 20 beds per salon.

For each salon, output a sentence telling how many customers, if any, walked away.
*/

int main() {
   int numBeds;        // count the number of beds
   string strCustInOut;// input string of customer-in and -out
   bool tanning[26];   // An array that notes who is currently in a bed
   bool known[26];     // keep track of whether you have seen a particular alphabet symbol
   int numTanning;     // count of how many people are currently tanning
   int numMisses;      // count how many times of customers left
   
   while (true) {
       // get the number of beds
       numMisses = 0; //set numMisses to 0
       numTanning = 0; //set numTanning to 0
	   
       cin >> numBeds; 
	   
       if (numBeds == 0 || numBeds > 20) {break;} // if the input is 0 or more than 20, then exit
	   
       cin >> strCustInOut; // get the list of customer-in and -out
       
       for (unsigned int j=0; j<sizeof(known); j++) // init arrays
       {
          tanning[j] = 0;
          known[j] = 0;
       }
	   
       for (unsigned int i=0; i<strCustInOut.length(); i++) // convert string chars to numbers for use as array indices
       {
           //int x = (static_cast<int>(strCustInOut[i]) - 'A'); 
           int x = (static_cast<int>(strCustInOut[i]) - 'A');

           if (known[x] != true && numTanning < numBeds) { // scenario when person first walks in and beds are available for tanning
              tanning[x] = true;
              known[x] = true;
              numTanning++;
           }
           
           else if (known[x] != true && numTanning == numBeds) { // scenario when person first walks in and no beds are available for tanning
              known[x] = true;
              tanning[x] = false;
           }
           
           else if (known[x] == true && tanning[x] == true) { // scenario when person is finished tanning
              numTanning--;
              tanning[x] = false;
           }
           
           else if (known[x] == true && tanning[x] == false) { // scenario when person leaves without tanning
             numMisses++;
           }
       }
        // print the output
       if (numMisses == 0)
           cout << "All customers tanned successfully." << endl; // print if no customers left without tanning
       else
           cout << numMisses << " customer(s) walked away." << endl; // print how many customers left without tanning
   }
   return 0;
}