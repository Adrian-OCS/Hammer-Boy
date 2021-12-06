#pragma once
#include "Entity.h"

class staticEn : public Entity {

    private:
        int renderX = 1000;
        int renderY = 1000;

    public:
        staticEn(int ox, int oy);
        void tickOverworld();
        void renderOverworld();
        void setRenderX(int x) { renderX = x; };
        void setRenderY(int y) { renderY = y; };
        int getOX() { return ox; };
        int getOY() { return oy; };
};