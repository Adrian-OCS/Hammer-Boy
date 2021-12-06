#pragma once

#include "Player.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "Static.h"


class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        Area *nextArea;
        string areaName;
        vector<staticEn*> Static;

    public:
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string areaName, vector<staticEn*> Static);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        vector<Enemy*> getEnemies() { return enemies;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        string getAreaName() { return areaName;};
        vector<staticEn*> getStatic() { return Static;};

};