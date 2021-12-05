#pragma once
#include "Entity.h"
class Fighter : public Entity {
    protected:
        int maxHealth;
        int baseDamage;
        int currentHealth;
        // Fighting coordinates and dimensions
        int fx, fy, fw, fh;
        ofImage fightingSprite;
 
    public:
 
        Fighter(int ox, int oy, int ow, int oh, string overworldPath, int fx, int fy, int fw, int fh, int maxHealth, int baseDamage, string fightingPath);
        virtual void tickFighting() = 0;
        virtual void renderFighting();
        int getMaxHealth() { return maxHealth; };
        void setMaxHealth(int maxHealth) { this->maxHealth = maxHealth; };
        int getCurrentHealth() { return currentHealth;};
        void setCurrentHealth(int currentHealth) { this->currentHealth = currentHealth; };
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
       
};
