#pragma once

#include "cocos2d.h"

class GJGameLevel : public cocos2d::CCNode
{

public:
	GJGameLevel();
	virtual ~GJGameLevel();

	static GJGameLevel *create();
	static GJGameLevel *create(cocos2d::CCDictionary *, bool);
    static GJGameLevel *createWithCoder(DS_Dictionary *pDS_Dict);

	void dataLoaded(DS_Dictionary *pDS_Dict);
	void getAudioFileName(std::string *outPath);
	void getLevelName(std::string *outName);

	int getNormalPercent();
	int getAverageDifficulty();

	void setLevelName(std::string name);
	void setStars(int starCount);
	void setDemon(int starCount);
	void setAttempts(int attCount);
	void setNormalPercent(int percent);
	void setNewNormalPercent(int percent);
	void setNewNormalPercent2(int percent);
	void setJumps(int jumps);
	void setClicks(int clicks);
	void setAttemptTime(int time);
	void setCoinsVerified(int verified);
	void setPassword(int pwd);
	void setLevelID(int lvlID);

	const char* getCoinKey(int a1);

	void unverifyCoins();
	
	// void savePercentage( ... );

	virtual void encodeWithCoder(DS_Dictionary *pDS_Dict);

	virtual bool init();
};