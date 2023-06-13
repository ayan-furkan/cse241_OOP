#include <iostream>
#include <cmath>

using namespace std;

class MyInteger{

    public:
        MyInteger() : x(0){}
        MyInteger(int num) : x(num){}

        const int GetNum(){
            return x;
        }
        void setNum(int num){
            x = num;
        }

        int operator [](int index){
            
            int temp = this->GetNum();

            int result;
            int digitNum = 0;

            for(int i = 0; i <= index; i++){
                
                if((temp == 0)){
                    return -1;
                }

                result = temp % 10;
                temp /= 10;

                if(index == i){
                    return result;
                }

            }
            return -1;
        }

    private:
        int x;
};



int main(){
    // Some test numbers
    MyInteger num(567);
    cout << "Num: " << num.GetNum() << endl;
    cout << num[0] << " " << num[1] << " " << num[2] << endl;
    cout << num[3] << endl;
    cout << num[-1] << endl;
}