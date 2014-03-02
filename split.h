/*****************
* ISTE-101
* Project 1
* Split Functions
* Edward Alvarez Mercedes
* Ryan Flynn
******************/
#ifndef SPLIT_H_INCLUDED
#define SPLIT_H_INCLUDED
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

int split (vector<string>& results, string toParse, char delimiter ){
    int wordCount = 0;
    int firstDelimiter = 0;
    int nextDelimiter =0;

//Get words from beginning to last delimiter
    for (unsigned int i = 0; i < toParse.length(); i++){
            if(toParse.at(i) == delimiter)
                {
                    nextDelimiter = i;
                    results.push_back(toParse.substr(firstDelimiter, nextDelimiter - firstDelimiter));
                    firstDelimiter = nextDelimiter + 1;
                    wordCount++;
            }
    }

    if(toParse.length() - firstDelimiter >= 1 && toParse.at(firstDelimiter) != delimiter)
    {
        results.push_back(toParse.substr(firstDelimiter, toParse.length() - firstDelimiter));
        wordCount++;
    }

    //get the last word

    return wordCount;
}

unsigned long ip2long (string ip){

    //declare variables
    unsigned long value =0;
    char delimiter = '.';
    vector<string> octets;

    //Call split function
    split(octets, ip, delimiter);

    //Convert octets to long
    unsigned long a = atol(octets[0].c_str());
    unsigned long b = atol(octets[1].c_str());
    unsigned long c = atol(octets[2].c_str());
    unsigned long d = atol(octets[3].c_str());

    //perform calculation
    value = d + (256.0 * c) + (256 * 256 * b) + (256 * 256 * 256 * a);

    return value;
}

string long2ip (unsigned long ip){

    string dotted;
    double temp;
    int quadA, quadB, quadC, quadD;

    temp = ip / 256.0;
    quadD = (int)(256.0 * (temp - (int)temp));

    temp = temp / 256.0;
    quadC = (int)(256.0 * (temp - (int)(temp)));

    temp = ((int)(temp)) / 256.0;
    quadB = 256 * (temp - (int)(temp));

    quadA = (int)(temp);

    //Convert ints to strings
    stringstream oct1;
    oct1 << quadA;
    string temp1 = oct1.str();

    stringstream oct2;
    oct2 << quadB;
    string temp2 = oct2.str();

    stringstream oct3;
    oct3 << quadC;
    string temp3 = oct3.str();

    stringstream oct4;
    oct4 << quadD;
    string temp4 = oct4.str();

    //put the strings together, adding periods
    dotted = temp1 + '.' +temp2 + '.' + temp3 + '.' + temp4;

    return dotted;
}

;

#endif // SPLIT_H_INCLUDED
