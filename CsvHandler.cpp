/*****************
* ISTE-101
* Project 1
* CSV Handler Class
* Edward Alvarez Mercedes
* Ryan Flynn
******************/
#include "CsvHandler.h"

/*********************************
* Function: parseCsvLine
* Purpose: Parses a csv line and splits
*                it by ',' into a string in a
*                vector.
* Parameters:  string of the file name to
                          open and read
* Returns: A vector where each element
*                is a line of the CSV file
*********************************/
vector<string> CsvHandler::parseCsvLine(string csvLine)
{
    vector<string> tempVector;
    string tempString;
    int firstDelimiter = 0;
    int nextDelimiter =0;
    char delimiter = ',';

    for (unsigned int i = 0; i < csvLine.length(); i++){
            if(csvLine.at(i) == delimiter){
                    nextDelimiter = i;
                    tempVector.push_back(csvLine.substr(firstDelimiter, nextDelimiter - firstDelimiter));
                    firstDelimiter = nextDelimiter + 1;
            }
    }

    if(csvLine.length() - firstDelimiter >= 1 && csvLine.at(firstDelimiter) != delimiter){
        tempVector.push_back(csvLine.substr(firstDelimiter, csvLine.length() - firstDelimiter));
    }

    return tempVector;
}

/*********************************
* Function: readCvs
* Purpose: Opens a CSV file and splits
*                the lines into a string in a
*                vector.
* Parameters:  string of the file name to
                          open and read
* Returns: A vector where each element
*                is a line of the CSV file
*********************************/
vector<string> CsvHandler::readCsv(const string file)
{
        vector<string> buffer;
        ifstream wireSharkFile;
        wireSharkFile.exceptions(ifstream::badbit);
        try{
            wireSharkFile.open(file.c_str(),ifstream::in);
            if(wireSharkFile.is_open()){
                string line;
                while (getline(wireSharkFile,line,'\r')){
                    buffer.push_back(line);
                }
                wireSharkFile.close();
            }
        }
        catch (ifstream::failure e){
            throw e;
        }
        return buffer;
}
