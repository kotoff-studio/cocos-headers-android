#pragma once

#include "GD/GJGameLevel.h"
#include "GD/GJBaseGameLayer.h"
#include "cocos2d.h"

class PlayLayer : public GJBaseGameLayer
{

public:
	PlayLayer();
	virtual ~PlayLayer();

	static PlayLayer *create(GJGameLevel *pLevel);
	static cocos2d::CCScene *scene(GJGameLevel *pLevel);

	void resetLevel();
	void createObjectsFromSetup(const std::string levelStr);

	virtual bool init(GJGameLevel *);


	virtual void update(float dt);
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void visit();

};