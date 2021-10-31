#pragma once

#include "cocos2d.h"

class GameSoundManager : public cocos2d::CCNode
{
public:

public:
	GameSoundManager();
	virtual ~GameSoundManager();

    static GameSoundManager* sharedManager();
    GameSoundManager* playEffect(std::string, float, float, float);
};
