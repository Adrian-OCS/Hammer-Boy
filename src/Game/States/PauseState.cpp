#include "PauseState.h"


 PauseState::PauseState(){
     pausedImage.load("images/ui/otherpause.png");


 }


 void PauseState::reset(){




 }


 void PauseState::tick(){


 }


 void PauseState::render(){
     if(paused){
        pausedImage.draw(ofGetWidth()/2-10, 10);
     }
}


void PauseState::keyPressed(int key){
    if (key == 'p'){
        paused = !paused;
    }
}


void PauseState::mousePressed(int x, int y, int button){




}