/*****************
* ISTE-101
* Project 1
* Row Header File
* Edward Alvarez Mercedes
* Ryan Flynn
******************/
#include <string>
#include <iostream>
using std::cout;
using std::string;

class Row {

    private:
        string number;
        string time;
        string source;
        string destination;
        string protocol;
        string info;

    public:
        //Constructor
        Row();
        Row(string, string, string, string, string, string);

        //Mutators
        void setNumber (string);
        void setTime (string);
        void setDestination(string);
        void setProtocol(string);
        void setInfo(string);

        //Accessors
        string getNumber();
        string getTime();
        string getSource();
        string getDestination();
        string getProtocol();
        string getInfo();


};
