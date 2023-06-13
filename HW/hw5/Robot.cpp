#include <iostream>
#include "Robot.h"


using namespace std;

int Robot::count = 0;

Robot::Robot(){
    world = NULL;
    has_attacked = false;
    hitpoint = 0;
    x=0;
    y=0;
    count++;
}

Robot::Robot(World *world, int x, int y){

    this->world = world;
    has_attacked = false;
    this->x = x;
    this->y = y;
    this->world->setAt(x,y,this);
    hitpoint =0;
    count++;
}

Robot::~Robot(){

}

void Robot::setHitpoint(int newHit){
    if(newHit < 0){
        hitpoint = 0;
    }else{
    hitpoint = newHit;
    }
}



void Robot::move(){
    int damage;
    int dir;
    //Attack arround
    if(count == 1){
        return;
    }

    //Check wheter or not there is a robot on top and make a fight until one of them dies. If one of them dies return  
    while((y>0) && (world->getAt(x,y-1) != NULL) && has_attacked == false){
            damage = getDamage();
            world->hitMessage(this, world->grid[x][y-1], damage);
            world->grid[x][y-1]->setHitpoint(world->grid[x][y-1]->getHitpoint()-damage);

            if(world->grid[x][y-1]->getHitpoint() == 0){
                //If victim dies
                cout << world->grid[x][y-1]->getName() << " dies" << endl;
                has_attacked = true;
                world->grid[x][y-1] = NULL;
                count--;
                return;
                    
            }else{
                //If victim doesnot dies, victim gonna atack next
                damage = world->grid[x][y-1]->getDamage();
                world->hitMessage(world->grid[x][y-1], this, damage);
                setHitpoint(getHitpoint()-damage);

                if(getHitpoint() == 0){
                    //First attacker dies
                    cout << getName() << " dies" << endl;
                    world->grid[x][y] = NULL;
                    count--;
                    return;
                }
            }
    }

    //Check wheter or not there is a robot at bottom and make a fight until one of them dies. If one of them dies return  
    while((y<WORLDSIZE-1) && (world->getAt(x,y+1) != NULL) && has_attacked == false){
            damage = getDamage();
            world->hitMessage(this, world->grid[x][y+1], damage);
            world->grid[x][y+1]->setHitpoint(world->grid[x][y+1]->getHitpoint()-damage);

            if(world->grid[x][y+1]->getHitpoint() == 0){
                //If victim dies
                cout << world->grid[x][y+1]->getName() << " dies" << endl;
                world->grid[x][y+1] = NULL;
                has_attacked = true;
                count--;
                return;
                    
            }else{
                //If victim doesnot dies, victim gonna atack next
                damage = world->grid[x][y+1]->getDamage();
                world->hitMessage(world->grid[x][y+1], this, damage);
                setHitpoint(getHitpoint()-damage);

                if(getHitpoint() == 0){
                    //First attacker dies
                    cout << getName() << " dies" << endl;
                    world->grid[x][y] = NULL;
                    count--;
                    return;
                }
            }
    }

    //Check wheter or not there is a robot on left and make a fight until one of them dies. If one of them dies return      
    while((x>0) && (world->getAt(x-1,y) != NULL) && has_attacked == false){
            damage = getDamage();
            world->hitMessage(this, world->grid[x-1][y], damage);
            world->grid[x-1][y]->setHitpoint(world->grid[x-1][y]->getHitpoint()-damage);

            if(world->grid[x-1][y]->getHitpoint() == 0){
                //If victim dies
                cout << world->grid[x-1][y]->getName() << " dies" << endl;
                world->grid[x-1][y] = NULL;
                has_attacked = true;
                count--;
                return;
                    
            }else{
                //If victim doesnot dies, victim gonna atack next
                damage = world->grid[x-1][y]->getDamage();
                world->hitMessage(world->grid[x-1][y], this, damage);
                setHitpoint(getHitpoint()-damage);

                if(getHitpoint() == 0){
                    //First attacker dies
                    cout << getName() << " dies" << endl;
                    world->grid[x][y] = NULL;
                    count--;
                    return;
                }
            }
    }

     //Check wheter or not there is a robot on right and make a fight until one of them dies. If one of them dies return  
    while((x<WORLDSIZE-1) && (world->getAt(x+1,y) != NULL) && has_attacked == false){
            damage = getDamage();
            world->hitMessage(this, world->grid[x+1][y], damage);
            world->grid[x+1][y]->setHitpoint(world->grid[x+1][y]->getHitpoint()-damage);

            if(world->grid[x+1][y]->getHitpoint() == 0){
                //If victim dies
                cout << world->grid[x+1][y]->getName() << " dies" << endl;
                world->grid[x+1][y] = NULL;
                has_attacked = true;
                count--;
                return;
                    
            }else{
                //If victim doesnot dies, victim gonna atack next
                damage = world->grid[x+1][y]->getDamage();
                world->hitMessage(world->grid[x+1][y], this, damage);
                setHitpoint(getHitpoint()-damage);

                if(getHitpoint() == 0){
                    //First attacker dies
                    cout << getName() << " dies" << endl;
                    world->grid[x][y] = NULL;
                    count--;
                    return;
                    
                }
            }
    }
    //IF no attacking 
    dir = rand() % 4;


    //move up
    if(dir == 0){
        if((y>0) && (world->getAt(x,y-1)==NULL)){
            world->setAt(x,y-1,this);
            world->setAt(x,y,NULL);
            y--;
        }
        
    }
    //move down
    if(dir == 1){
        if((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL)){
            world->setAt(x,y+1,this);
            world->setAt(x,y,NULL);
            y++;
        }
    }
    //move left
    if(dir == 2){
        if((x>0) && (world->getAt(x-1,y)==NULL)){
            world->setAt(x-1,y,this);
            world->setAt(x,y,NULL);
            x--;
        }
    }
    //move right
    if(dir == 3){
        if((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL)){
            world->setAt(x+1,y,this);
            world->setAt(x,y,NULL);
            x++;
        }
    }

    if(world->getAt(x,y-1) != NULL || world->getAt(x,y+1) != NULL || world->getAt(x-1,y) != NULL || world->getAt(x-1,y) != NULL){
        //If there is at least one enemy around call the function again
        this->move();
        return;        
    }

    if(has_attacked == false){
        //If the robot did not attack. call the funtion again
        this->move();
    }

}