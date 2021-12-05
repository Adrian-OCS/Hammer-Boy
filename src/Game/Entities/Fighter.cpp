#include "Fighter.h"
 
Fighter::Fighter(int ox, int oy, int ow, int oh, string overworldPath, int fx, int fy, int fw, int fh, int maxHealth, int baseDamage, string fightingPath) : Entity(ox, oy, ow, oh, overworldPath)
{
 
    this->fx = fx;
    this->fy = fy;
    this->fh = fh;
    this->fw = fw;
    this->maxHealth = maxHealth;
    this->baseDamage = baseDamage;
 
    fightingSprite.load(fightingPath);
}
 
void Fighter::renderFighting() {
    fightingSprite.draw(fx, fy, fw, fh);
}
