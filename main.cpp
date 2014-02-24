/*****************
* ISTE-101
* Project 1
* Sort Wireshark Log
* Edward Alvarez Mercedes
* Ryan Flynn
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
vector<string> readCsv(const string file);
vector<string> parseCsvLine(const string csvLine);

int main()
{
    //Initialize Variables
    string filename;
    string inputLine;
    vector<string> parsedData;
    vector<string> buffer;
    vector<Row> dataSet;
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
        if (i > 0){
            Row newRow(parsedData.at(0),parsedData.at(1),parsedData.at(2),parsedData.at(3),parsedData.at(4),parsedData.at(5));
            dataSet.push_back(newRow);
        }
    }

    //Now we have a vector of Row objects!
    /*cout<<dataSet.at(1).getProtocol() <<endl;
    cout<<dataSet.at(2).getProtocol() <<endl;
    cout<<dataSet.at(3).getDestination() <<endl;*/

    //Lets create a vector of destination ip addresses
    vector<string> destinationIps;
    for (unsigned int i =0; i < dataSet.size(); i++){
        std::vector<std::string>::const_iterator it = std::find(destinationIps.begin(), destinationIps.end(), dataSet.at(i).getDestination());
        if (it == destinationIps.end())
        {
                destinationIps.push_back(dataSet.at(i).getDestination());
        }
    }

    //Vector is loaded with destination IPs
    // Time to sort
    std::sort(destinationIps.begin(), destinationIps.end());


    //Create Output File
    ofstream fout;
    fout.open("sortedIPs.txt");

    //output the sorted list
    if (destinationIps.size() == 0 || !fout.is_open()){
            cout << "An error has occured" << endl;
    }else{
        for(unsigned int i =0; i < destinationIps.size(); i++){
            fout << destinationIps.at(i) << endl;
        }
    }
fout.close();
    return 0;
}
