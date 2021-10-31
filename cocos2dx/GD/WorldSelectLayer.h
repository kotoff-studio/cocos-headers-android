#pragma once

#include "cocos2d.h"
#include "GJGameLevel.h"

class MapSelectLayer : public cocos2d::CCLayer 
{
public:
    MapSelectLayer();
    virtual ~MapSelectLayer();

    static cocos2d::CCScene* scene(int p1);
    static MapSelectLayer* create(int p1);

    void onBack(CCObject* sender);
    void onExit();

    virtual bool init(int p1);
    virtual void update(float p1);
};

class WorldSelectLayer : public cocos2d::CCLayer
{
public:
    WorldSelectLayer();
    virtual ~WorldSelectLayer();

    static cocos2d::CCScene* scene(int p1);
    static WorldSelectLayer* create(int p1);

    void animateInActiveIsland();
    void showCompleteDialog();
    void unblockButtons();
    void setupWorlds();

    void onGarage(CCObject* sender);
    void onPrev(CCObject* sender);
    void onNext(CCObject* sender);
    void onExit();
    void onBack(CCObject* sender);

    void goToPage(int p1, bool p2);

    virtual bool init(int p1);
};

class GJWorldNode : public cocos2d::CCNode
{
public:
    GJWorldNode();
    virtual ~GJWorldNode();

    static GJWorldNode* create(int p1, WorldSelectLayer* p2);

    void onLevel(CCObject* p1);
};

class WorldLevelPage : public cocos2d::CCLayer
{
public:
    WorldLevelPage();
    virtual ~WorldLevelPage();

    static WorldLevelPage* create(GJGameLevel* p1, GJWorldNode* p2);

    void onClose(CCObject* sender);
    void onPlay(CCObject* sender);
    void onInfo(CCObject* sender);

    virtual bool init(GJGameLevel* p1, GJWorldNode* p2);
    virtual void show();
};