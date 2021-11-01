#pragma once
#include "ofMain.h"
enum Direction {left, right, up, down};
class Entity {
    protected:
        int maxHealth;
        int baseDamage;
        int currentHealth;
        // Fighting coordinates and dimensions
        int fx, fy, fw, fh;
        // Overworld Coordinates and dimensions
        int ox, oy, ow, oh;
        ofImage fightingSprite;
        ofImage overworldSprite;

    public:
        Entity(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int maxHealth, int baseDamage, string fightingPath, string overworldPath);
        virtual void tickOverworld() = 0;
        virtual void tickFighting() = 0;
        virtual void renderOverworld();
        virtual void renderFighting();
        int getOX() { return ox; };
        int getOY() { return oy; };
        int getOW() { return ow; };
        int getOH() { return oh; };
        ofRectangle getBounds();
        ofRectangle getBounds(int ox, int oy);
        bool collides(Entity* entity);
        void setOX(int ox) { this-> ox = ox; };
        void setOY(int oy) { this-> oy = oy; };
        int getMaxHealth() { return maxHealth; };
        void setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; };
        int getCurrentPlayerHealth() { return currentHealth;};
        void setCurrentPlayerHealth(int currentHealth) { this->currentHealth = currentHealth; };
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
};