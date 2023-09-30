/*
Question Link: https://leetcode.com/problems/zigzag-conversion/

*Main Approach:
We create an array (of size numRows) of StringBuffers. Then, we add each character at position i of the input string to the StringBuffer at an index that fluctuates between 0 and numRows – 1. 
Finally, we can concatenate all the StringBuffers to one StringBuffer and return that concatenation. 
The most important concepts are (1) that there will be an index that will fluctuate between 0 and numRows – 1 that will simulate the zigzag conversion and (2) we will have an array of StringBuffers that will be accessed in a zigzag manner according to that fluctuating index.

/**
*The size of every period is defined as a “cycle”
cycle = (2*nRows - 2), except nRows == 1.

*In this example, (2*nRows – 2) = 4.
In every period, every row has 2 elements, except the first row and the last row.
Suppose the current row is i, the index of the first element is j:
j = i + cycle*k, k = 0, 1, 2, ...

*The index of the second element is secondJ:
secondJ = (j - i) + cycle - i
(j-i) is the start of the current period, (j-i) + cycle is the start of the next period.


/**
 * Pseudocode:
check for edge-case (numRows = 1)
initialize the array of StringBuffers.
append each character in the input string to correct StringBuffer according to the fluctuating index
concatenate all the StringBuffers to one and return the concatenation
 */

class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows==1)
      return s;
        int step1,step2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            step1=(numRows-i-1)*2;
            step2=(i)*2;
            int pos=i;
            if(pos<len)
                result+=s.at(pos);
            while(1){
                pos+=step1;
                if(pos>=len)
                    break;
        if(step1)
          result+=s.at(pos);
                pos+=step2;
                if(pos>=len)
                    break;
        if(step2)
          result+=s.at(pos);
            }
        }
        return result;
    }
};
