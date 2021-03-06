#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);

}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::tick()
{   if(isPaused == false){
        player->tickOverworld();
        for (unsigned int i = 0; i < area->getEnemies().size(); i++)
        {
            if (!area->getEnemies().at(i)->isDead())
            {
                area->getEnemies().at(i)->tickOverworld();
                if (player->collides(area->getEnemies().at(i)))
                {
                    setEnemy(area->getEnemies().at(i));
                    setNextState("Battle");
                    setFinished(true);
                }
            }

        }
        camera->tick();
    }
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();
    ofDrawBitmapString(area->getAreaName() + "\n" + "Health: " + to_string(player->getCurrentHealth()) + "\n" + "Remaining enemies: " + to_string(area->getRemainingEnemies()), 15, 25);

    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->renderOverworld();

            // int playerDistanceX = area->getFriend()->getOX() - camera->getPlayerX();
            // int playerDistanceY = area->getFriend()->getOY() - camera->getPlayerY();
            // area->getFriend()->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            // area->getFriend()->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            // friendEn->renderOverworld();
        }
    }
    for (unsigned int i = 0; i < area->getStatic().size(); i++)
    {
        int playerDistanceX = area->getStatic().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getStatic().at(i)->getOY() - camera->getPlayerY();
        area->getStatic().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
        area->getStatic().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
        area->getStatic().at(i)->renderOverworld();
    }

}

void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);
    if (key == 'p'){
        if (isPaused == false){
            music.setVolume(0);
            isPaused = true;
        }
        else{
            music.setVolume(0.25);
            isPaused = false;
        }
	}
    if (key == '-'){
        music.setVolume(0);
    }
    if (key == '='){
        music.setVolume(0.25);
    }
}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);

    if (key == 'r'){
        area->resetEnemies();
    }
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}