#ifndef EXCPETION_H
#define EXCPETION_H

#include <string>
#include <exception>

using namespace std;


class MissingFieldException :public exception{
    public:
        MissingFieldException(string message);
        string getMessage() const;

    private:
        string message;

};

class DuplicateEntryException {
    public:
        DuplicateEntryException(string message);
        string getMessage() const;

    private:
        string message;
};

class WrongCommandException  {
    public:
        WrongCommandException(string message);
        string getMessage() const;
    private:
        string message;
};




#endif