#pragma once

#include "cocos2d.h"

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite
{
public:
	unsigned char _unknown[21 * sizeof(int)];
	cocos2d::CCPoint _animationTypePos;

public:
	CCMenuItemSpriteExtra();
	virtual ~CCMenuItemSpriteExtra();

	static CCMenuItemSpriteExtra *create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);
	bool init(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector);
		void setSizeMult(float size);

	void activate();
	void selected();
	void unselected();
};