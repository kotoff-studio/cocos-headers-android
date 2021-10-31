#pragma once
#include "cocos2d.h"

class GJBaseGameLayer : public cocos2d::CCLayer
{
public:
	GJBaseGameLayer();
	virtual ~GJBaseGameLayer();

	virtual void setupLayers();
	virtual void toggleGroupTriggered(int, bool) {}
	virtual void spawnGroup(int) {}
	virtual void createTextLayers();
	
	virtual bool init();
};
