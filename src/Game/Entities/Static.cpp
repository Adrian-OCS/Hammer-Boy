#include "Static.h"

staticEn::staticEn(int ox, int oy) : Entity(ox, oy, 384, 384, "images/entities/treeSprite.png") {
    vector<ofImage> staticFrame = {};
    ofImage temp; 
    
    overworldSprite.load("images/entities/Static/treeSprite.png");
    temp.load("images/entities/Static/treeSprite.png");
    staticFrame.push_back(temp);
}

void staticEn::tickOverworld() {
    overworldSprite.load("images/entities/Static/treeSprite.png");
}

void staticEn::renderOverworld() {
    overworldSprite.draw(renderX, renderY, ow, oh);
}