#pragma once
#include "State.h"


class PauseState: public State{
    private:
        ofImage pausedImage;
        string lastState;
        
    public:
        PauseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        string getLastStateName(){return lastState;}
        void setLastState(string lastState) { this->lastState = lastState;}


   


};