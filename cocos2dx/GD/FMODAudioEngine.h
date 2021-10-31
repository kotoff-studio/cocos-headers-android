#pragma once

#include "cocos2d.h"

class FMODAudioEngine : public cocos2d::CCNode
{
public:

public:
	FMODAudioEngine();
	virtual ~FMODAudioEngine();

	static FMODAudioEngine *sharedEngine();

	void preloadBackgroundMusic(std::string songFilename);
};