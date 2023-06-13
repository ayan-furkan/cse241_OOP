#include <iostream>

using namespace std;

class Vector2D{

    public:

        Vector2D() : x(0), y(0){}
        Vector2D(int x, int y): x(x), y(y){}

        const int GetX(){
            return x;
        }
        const int GetY(){
            return y;
        }

        void SetX(int newX){
            x = newX;
        }
        void SetY(int newY){
            y = newY;
        }

        int operator *(Vector2D& other){

            return (this->GetX() * other.GetX()) + (this->GetY() * other.GetY());
        }

    private:
        int x;
        int y;

};


int main(){

    // Some test vectors
    Vector2D v1(10,7), v2(2,5), v3(3,11), v4(8,2);
    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()
        << "," << v2.GetY() << ") = " << v1*v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()
        << "," << v3.GetY() << ") = " << v2*v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()
        << "," << v4.GetY() << ") = " << v3*v4 << endl;

}