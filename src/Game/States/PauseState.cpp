#include "PauseState.h"
 //requierments:
 //#1 stop player movement Overworld
 //#2 stop enemy animations overworld
 //#3 Stop battlestate animations 
 //#4 stop Battlestate interactions

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