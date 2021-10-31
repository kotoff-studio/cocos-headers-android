#pragma once

#include "CustomListView.h"
#include "cocos2d.h"

class GJDropDownLayer : public cocos2d::CCLayerColor
{
public:
	unsigned char _unknown[7 * sizeof(int)];
	CCLayer *_pDropLayer;
	unsigned char _unknown2[2 * sizeof(int)];

public:
	GJDropDownLayer();
	virtual ~GJDropDownLayer();

	static GJDropDownLayer* create(char* label, float a2);

	virtual bool init(const char* label, float a2);
	virtual bool init(const char* label);
};