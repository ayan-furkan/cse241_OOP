#include "World.h"
#include <time.h>
#include <cstdlib>
#include <string>
#include "Optimusprime.h"
#include "World.cpp"
#include "Robocop.h"
#include "Bulldozer.h"
#include "Roomba.h"

using namespace std;



class World;

int main(){
    srand(time(NULL));
    World w;

    int initial_count_of_each_robot_type = 5;
    int x,y;

    int optimusCount = 0;
    // Add 5 optimus prime
    while(optimusCount < initial_count_of_each_robot_type){
        x = rand() % WORLDSIZE;
        y = rand() % WORLDSIZE;

        if(w.getAt(x,y)==NULL){
            optimusCount++;
            Optimusprime *o1 = new Optimusprime(&w,x,y);
        }
    }
    int bulldozerCount = 0;
    // Add 5 bulldozer
    while(bulldozerCount < initial_count_of_each_robot_type){
        x = rand() % WORLDSIZE;
        y = rand() % WORLDSIZE;

        if(w.getAt(x,y)==NULL){
            bulldozerCount++;
            Bulldozer *b1 = new Bulldozer(&w,x,y);
        }
    }

    int roombaCount = 0;
    //add 5 roomba
    while(roombaCount < initial_count_of_each_robot_type){
        x = rand() % WORLDSIZE;
        y = rand() % WORLDSIZE;

        if(w.getAt(x,y)==NULL){
            roombaCount++;
            Roomba *c1 = new Roomba(&w,x,y);
        }
    }

    int robocopCount = 0;
    //add 5 robocop
    while(robocopCount < initial_count_of_each_robot_type){
        x = rand() % WORLDSIZE;
        y = rand() % WORLDSIZE;

        if(w.getAt(x,y)==NULL){
            robocopCount++;
            Robocop *c1 = new Robocop(&w,x,y);
        }
    }

    w.Simulate();

}