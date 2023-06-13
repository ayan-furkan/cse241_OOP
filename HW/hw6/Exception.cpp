#include "Exception.h"

using namespace std;


MissingFieldException::MissingFieldException(string message) : message(message){

}

string MissingFieldException::getMessage()const {
    return message;

}

DuplicateEntryException::DuplicateEntryException(string message) : message(message){

}


string DuplicateEntryException::getMessage() const{
    return message;
}

WrongCommandException::WrongCommandException(string message) : message(message){

}

string WrongCommandException::getMessage() const {
    return message;
}