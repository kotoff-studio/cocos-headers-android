#pragma once

#include "cocos2d.h"

class LevelSearchLayer : public cocos2d::CCLayer 
{

public:
	LevelSearchLayer();
	virtual ~LevelSearchLayer();

	static LevelSearchLayer *create();

	void onLatestStars(CCObject* sender);

	virtual bool init();
};