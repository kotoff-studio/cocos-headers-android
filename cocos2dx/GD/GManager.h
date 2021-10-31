#pragma once

#include "cocos2d.h"

class GManager : public cocos2d::CCNode
{

public:
	void save();

	virtual void setup();
	virtual void encodeDataTo(DS_Dictionary *pDS_Dict) = 0;
	virtual void dataLoaded(DS_Dictionary *pDS_Dict) = 0;
	virtual void firstLoad() = 0;
};