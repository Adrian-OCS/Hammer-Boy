#include "PauseState.h"


 PauseState::PauseState(){
    music.load("audio/ui/beep.wav");
    music.setVolume(0);


 }


 void PauseState::reset(){




 }


 void PauseState::tick(){


 }


 void PauseState::render(){

}


void PauseState::keyPressed(int key){
    if (key == 'p'){
            setNextState(getLastStateName());
            setFinished(true);
        }
    
}


void PauseState::mousePressed(int x, int y, int button){




}