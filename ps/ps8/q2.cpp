#include <iostream>
#include <string>

using namespace std;

template<class T, class U>
class Pair{
    public:
        Pair(T f, U s): first(f), second(s){}

        T getFirst() const{return first;}
        U getSecond()const{return second;}

        void setFirst(T f) {first = f;} 
        void setSecond(U s) {second = s;}

    private:
        T first;
        U second;
};


int main() {
    Pair<char, char> p('F', 'K');
    cout << "First is " << p.getFirst() << endl;
    p.setFirst('D');
    cout << "First changed to " << p.getFirst() << endl;
    cout << "The pair is: " << p.getFirst() << ", " << p.getSecond() << endl;

    Pair<int, string> p2(61, "Trabzon");
    Pair<string, int> p3("Bill", 34);
    cout << "The pair is: " << p2.getFirst() << ", " << p2.getSecond() << endl;
    return 0;
}