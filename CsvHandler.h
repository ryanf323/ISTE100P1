/*****************
* ISTE-101
* Project 1
* CSV Handler Class Header File
* Edward Alvarez Mercedes
* Ryan Flynn
******************/
#include <vector>
#include <fstream>

using namespace std;

class CsvHandler{


private:

public:
        vector<string> parseCsvLine(string);
        vector<string> readCsv(const string);

};
