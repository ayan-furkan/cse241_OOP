#include <iostream>

using namespace std;

class HotDogStand
{
public:
    HotDogStand();
    HotDogStand(int ID, int hotDog) : ID(ID) ,hotDogSold(hotDog){
        for(int i=0; i<hotDog; i++){
            totalJustSold();
        }
    }

    void printhotDogSold(){ 
        //print the how many hotdog stand saled.
        cout << "Stand " << ID << " total sale: " << hotDogSold << endl;
    }
    void printTotalHotDogSold(){
        //print how many hotdog all the stand saled.
        cout << "All Stand Sold " << totalhotDog << " hotdogs." << endl;
    }
    static void totalJustSold(){
        // Increase the total hotdog number the stand saled.
        totalhotDog++;
    }
    void JustSold(){
        // Increase the how many hotdog indivual stand saled and total hotdog
        cout << "Stand " << ID << " sold one more HotDog." << endl;
        hotDogSold++;
        printhotDogSold();
        totalJustSold();
    } 



private:
    int ID;
    int hotDogSold = 0;
    static int totalhotDog;
};



int HotDogStand::totalhotDog = 0;


int main(){

    HotDogStand ht1(1, 5);
    HotDogStand ht2(2, 3);
    HotDogStand ht3(3, 0);


    ht1.printhotDogSold();
    ht2.printhotDogSold();
    ht3.printhotDogSold();
    ht1.printTotalHotDogSold();
    cout << endl;

    ht1.JustSold();
    cout << endl;
    ht2.JustSold();
    cout << endl;
    ht3.JustSold();
    cout << endl;
    
    ht1.printTotalHotDogSold();


}