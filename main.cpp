/*****************
* ISTE-101
* Project 1
* Sort Wireshark Log
* Edward Alvarez Mercedes
* Ryan Flynn
* Purpose: Read CSV file from
* Wireshark and sort the
* destination ip addresses in
* a output file.
******************/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <string>
#include "Row.h"
#include "CsvHandler.h"
#include "split.h"

using namespace std;

int main()
{
    //Initialize Variables
    string filename;
    string inputLine;
    vector<string> parsedData;
    vector<string> buffer;
    vector<Row> dataSet;
    char delimiter='.';
    vector<unsigned long> temporary;
    unsigned long longIp = 0;
    vector <string> finalIp;
    int amountWords = 0;
    vector <string> results;
    char firstLetter = ' ';

    //create CSV Handler Object
    CsvHandler workhorse;

    //Prompt for filename
    cout << "Enter name of file to open: ";
    getline(cin, filename);

    buffer = workhorse.readCsv(filename);

    //iterate through each string in the vector
    // and parse it into a temporary vector.
    //The temp vector will be used to create
    // a Row object
    for (unsigned int i = 0; i < buffer.size(); i++){

        parsedData = workhorse.parseCsvLine(buffer.at(i));

        //Skip the first iteration to prevent
        //capturing the header row
        //Creating the row object:
        if (i > 0){
            Row newRow(parsedData.at(0),parsedData.at(1),parsedData.at(2),parsedData.at(3),parsedData.at(4),parsedData.at(5));
            dataSet.push_back(newRow);
        }
    }

    //Now we have a vector of Row objects!

    //Lets create a vector of destination ip addresses
    vector<string> destinationIps;


    //The following iteration only takes the unique ip addresses.
    for (unsigned int i =0; i < dataSet.size(); i++){
        std::vector<std::string>::const_iterator it = std::find(destinationIps.begin(), destinationIps.end(), dataSet.at(i).getDestination());
        if (it == destinationIps.end())
        {
                destinationIps.push_back(dataSet.at(i).getDestination());
        }
    }

    //Converting the strings in integers:
    //The "if" statement validates if the field is an ipaddress.
    for (unsigned int i = 0;i < destinationIps.size(); i++) {
     firstLetter = destinationIps[i].at(0);

    //To eliminate the destination ip addresses
    //with alpha characters.
     if (!(isalpha(firstLetter))){
        amountWords = split(results, destinationIps[i], delimiter);
        longIp = ip2long(destinationIps[i]);
        temporary.push_back(longIp);
        }
    }

    // Time to do a numeric sort.
    std::sort(temporary.begin(), temporary.end());

    //Converting back the integers in Ip strings:
    for(unsigned int i = 0;i < temporary.size();i++) {
      finalIp.push_back(long2ip(temporary[i]));
    }

    //Create Output File
    ofstream fout;
    fout.open("sortedIPs.txt");

    //output the sorted list
    if (finalIp.size() == 0 || !fout.is_open()){
            cout << "An error has occured." << endl;
            return 1;
    }else{
        for(unsigned int i =0; i < finalIp.size(); i++){
            fout << finalIp.at(i) << endl;
        }
    }

fout.close();

cout << "\nOutput file sortedIPs.txt generated successfully\n";
    return 0;
}
