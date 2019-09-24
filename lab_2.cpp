#include<iostream>
#include<algorithm>
#include<initializer_list>
using namespace std;

/*
What do you do if you need to copy a 560x400mm image onto a standard sheet of US letter-size paper (which is about 216x280mm), 
while keeping the image as large as possible? You can rotate the image 90 degrees (so that it is in "landscape" mode), then reduce 
it to 50% of its original size so that it is 200x280mm. Then it will fit on the paper without overlapping any edges. 
Your job is to solve this problem in general.

Input: The input consists of one or more test cases, each of which is a single line containing four positive integers A, B, C, and D, 
separated by a space, representing an AxBmm image and a CxDmm piece of paper. All inputs will be less than one thousand. 
Following the test cases is a line containing four zeros that signals the end of the input.

Output: For each test case, if the image fits on the sheet of paper without changing its size (but rotating it if necessary), 
then the output is 100%. If the image must be reduced in order to fit, the output is the largest integer percentage of its 
original size that will fit (rotating it if necessary). Output the percentage exactly as shown in the examples below. 
You can assume that no image will need to be reduced to less than 1% of its original size, so the answer will always 
be an integer percentage between 1% and 100%, inclusive.
*/

int calcResize(double a, double b, double c, double d) { // initialize calcResize and double a,b,c,d parameters
    int answer1, answer2, minAnswer;
    answer1 = (c / a) * 100; // calculate max length % resize
    answer2 = (d / b) * 100; // calculate max width % resize
    minAnswer = std::min({answer1, answer2}); // find min resize value
    if (minAnswer > 100) // to account for photo being smaller than copy paper
    return 100;
    else
    return minAnswer;
}
int main() {
    int A, B, C, D, x, y, z;
    do{
        std::cin >> A >> B >> C >> D; // input photo dimensions (A,B) and copy paper dimensions (C,D)
        if (A>0 && B>0 && C>0 && D>0) { 
            x = calcResize(A,B,C,D); // calculate initial 
            y = calcResize(B,A,C,D); // calculate after rotating 90 degrees
            z = std::max({x, y}); // find largest possible resize
            std::cout << z << "%" << endl;
        }
    }
    while(A>0 && B>0 && C>0 && D>0);
    return 0;
}
