#include <iostream>
#include "World.h"

World::World(){
    int i,j;

    for(i = 0; i < WORLDSIZE; i++){
        for(j=0; j < WORLDSIZE; j++){
            grid[i][j] = NULL;
        }
    }

}

World::~World(){
    int i,j;

    for(i = 0; i < WORLDSIZE; i++){
        for(j=0; j < WORLDSIZE; j++){
            if(grid[i][j] != NULL) delete (grid[i][j]);
        }
    }
}

Robot* World::getAt(int x, int y){

    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y < WORLDSIZE)){
        return grid[x][y];
    }
    return NULL;
}

void World::Display() const {

    int i,j;

    for(i = 0; i < WORLDSIZE; i++){
        for(j=0; j < WORLDSIZE; j++){
            if(grid[i][j]== NULL){
                cout << ".";
            }
            else if(grid[i][j]->getType() == OPTIMUSPRIME){
                cout << "O";
            }
            else if(grid[i][j]->getType() == ROBOCOP){
                cout << "X";
            }
            else if(grid[i][j]->getType() == ROOMBA){
                cout << "Y";
            }
            else{
                cout << "B";
            }
        }
        cout << endl;
    }
}

void World::setAt(int x, int y, Robot *robot){

    if((x>=0) && (x<WORLDSIZE) && (y>=0) && (y < WORLDSIZE)){
        grid[x][y] = robot;
    }
}

void World::Simulate(){
    int i,j;
    //Set every robot has_attakced = false
    int damage;
    
    //Set every Robot not moved
    for(i=0;i<WORLDSIZE; i++){
        for(j=0; j < WORLDSIZE; j++){
            if(grid[i][j] != NULL) grid[i][j]->has_attacked = false;
        }
    }

    //If the robot didn't move then move
    for(i = 0; i < WORLDSIZE; i++){
        for(j=0; j < WORLDSIZE; j++){
            if(grid[i][j] != NULL && grid[i][j]->has_attacked == false){
                grid[i][j]->move();
                cout << endl;
            }

           
        }
    }
    //Continue until one robot left
    if(grid[i][j]->count <= 1){
        return;
    }

    Simulate();

}

void World::hitMessage(Robot* attacker, Robot* victim, int damage) const {

    int newHit;
    if(victim->getHitpoint()-damage < 0){
        newHit = 0;
    }
    else{
        newHit = victim->getHitpoint()-damage;
    }

    cout << attacker->getName() <<"(" << attacker->getHitpoint() << ")" << " hits " << victim->getName()
                         << "(" << victim->getHitpoint() << ")" << " with " << damage << endl;
    cout << "The new hitpoints of " << victim->getName() << " is " << newHit << endl;
}