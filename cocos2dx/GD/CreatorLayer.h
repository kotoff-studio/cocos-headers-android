#pragma once

#include "cocos2d.h"

class CreatorLayer : public cocos2d::CCLayer 
{

public:
	CreatorLayer();
	virtual ~CreatorLayer();

	static CreatorLayer *create();

	void onMyLevels(CCObject* sender);
	void onSavedLevels(CCObject* sender);
	
	void onOnline(CCObject* sender);
	void onBack(CCObject* sender);
	
	void onGauntlets(CCObject* sender);
	void onTreasureRoom(CCObject* sender);

	virtual bool init();
};
/*
class CreatorLayer : public cocos2d::CCLayer
{
public:

public:
	CreatorLayer();
	virtual ~CreatorLayer();

	static CreatorLayer* create();

	void updateColor(float dt);
	
	virtual bool init();
	virtual void update(float dt);
};
*/