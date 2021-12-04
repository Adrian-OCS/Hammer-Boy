#pragma once
#include "State.h"
class LoadingState: public State{
    private:
    ofImage loadImage;
    bool isLoading = false;
    int counter = 0;
    State* currentState;

    public:
        LoadingState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void keyReleased(int key);
        void startLoading(State* nextState);
        bool getLoading(){return isLoading;}

};