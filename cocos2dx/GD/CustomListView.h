#pragma once

//#include "CCLayer.h"
//#include "CCArray.h"
#include "cocos2d.h"

class TableViewCell : public cocos2d::CCLayer 
{
public:

};

class BoomListView : public cocos2d::CCLayer 
{
    BoomListView();
    virtual ~BoomListView();
};

enum BoomListType {
    Regular = 5
};

class CustomListView : public BoomListView
{
public:
    unsigned char _unknown[300];
    int a;

public:
    CustomListView();
    virtual ~CustomListView();

    static CustomListView* create(cocos2d::CCArray* content, float width, float height, int a4, BoomListType layoutType);

    virtual void loadCell(TableViewCell* a1, int tableIndex);
	
	void scrollToBottom (float time, bool attenuated);
	void scrollToTop (float time, bool attenuated);
};

class GJListLayer : public cocos2d::CCLayer
{
public:
    GJListLayer();
    virtual ~GJListLayer();

    static GJListLayer* create(BoomListView* a1, const char* title, cocos2d::ccColor4B color, float width, float height);
};