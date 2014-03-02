/*****************
* ISTE-101
* Project 1
* Row Class
* Edward Alvarez Mercedes
* Ryan Flynn
* Purpose: The row class works
* as a container which stores
* the fields for the CSV file.
******************/
#include "Row.h"

        //Default Constructor
        Row::Row(){

        }

        Row::Row(string number, string time, string source, string destination, string protocol, string info){
            this -> number = number;
            this -> time = time;
            this -> source = source;
            this -> destination=destination;
            this -> protocol = protocol;
            this -> info = info;
        }

        //Mutators
        void Row::setNumber (string number){
            this -> number = number;
        }

        void Row::setTime (string time){
            this -> time = time;
        }

        void Row::setDestination(string source){
            this -> source = source;
        }

        void Row::setProtocol(string protocol){
             this -> protocol = protocol;
        }

        void Row::setInfo(string info){
            this -> info = info;
        }

        //Accessors
        string Row::getNumber(){
            return number;
        }

        string Row::getTime(){
            return time;
        }

        string Row::getSource(){
            return source;
        }

        string Row::getDestination(){
            return destination;
        }

        string Row::getProtocol(){
            return protocol;
        }

        string Row::getInfo(){
            return info;
        }


