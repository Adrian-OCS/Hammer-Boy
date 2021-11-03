#include "State.h"


class PauseState: public State{
    private:
        ofImage pausedImage;
        bool paused = false;
    public:
        PauseState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        bool getPause(){return paused; };


   


};