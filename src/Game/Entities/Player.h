#pragma once
 
#include "Fighter.h"
#include "Animation.h"
 
#define INIT_X 100
#define INIT_Y 100
#define CENTER_X 288
#define CENTER_Y 208
 
#define OXDIMENSION 2688
#define OYDIMENSION 2560
 
 
class Player : public Fighter {
    private:
        Direction direction = Direction::up;
        int speed = 8;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        vector<char> pressedKeys;
   
    public:
        Player(int maxHealth, int baseDamage);
        ~Player();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        bool StaticTouch();
        bool StaticTouch2();
        bool StaticTouch3();
};
