#pragma once

#include "MenuLayer.h"
#include "cocos2d.h"

class MoreOptionsLayer : public cocos2d::CCLayer 
{
public:
    MoreOptionsLayer();
    virtual ~MoreOptionsLayer();

    static MoreOptionsLayer* create();

    void onSongBrowser(CCObject* sender);
    void addToggle(const char* label, const char* gv, const char* description);
    void onToggle(CCObject* sender);

    virtual bool init();
};

class OptionsLayer : public cocos2d::CCLayer
{
public:
	
public:
    OptionsLayer();
    virtual ~OptionsLayer();

    static OptionsLayer* create();

	virtual bool init();
	virtual void update(float dt);
};