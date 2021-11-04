#include "LoadingState.h"


LoadingState::LoadingState(){
    music.load("audio/ui/beep.wav");

    // loadImage.load("image/ui/Loadingimage.webp");
};

void LoadingState::reset(){

};

void LoadingState::tick(){
    if (isLoading){
        counter++;
        // music.stop();
    }
    if (counter == 100){ //takes 3 seconds to load
        counter = 0;
        isLoading = false;
        currentState->toggleMusic();
    }
};

void LoadingState::keyPressed(int key){

};

void LoadingState::mousePressed(int x, int y, int button){

};
        
void LoadingState::keyReleased(int key){

};

void LoadingState::startLoading(State* nextState){
    isLoading = true;
    currentState = nextState;
    //toggleMusic();
    // music.stop();
};

void LoadingState::render(){
    if(isLoading){
        ofDrawBitmapString("It's Loading", ofGetWidth()/2, ofGetHeight()/2);
;
    }
};