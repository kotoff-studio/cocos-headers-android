#pragma once

#include "FLAlertLayer.h"
#include "cocos2d.h"

class MenuLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol
{

public:
	MenuLayer();
	virtual ~MenuLayer();

	static MenuLayer *create();
	static cocos2d::CCScene *scene(bool showOptions);

	void onMyProfile(CCObject* sender);
	void onFullVersion(CCObject* sender);
	void onCreator(CCObject* sender);
	void onPlay(CCObject* sender);
	void onGarage(CCObject* sender);
	void onOptions(CCObject* sender);
	void onQuit(CCObject* sender); 
	void onSquare(CCObject* sender); 
	void onWindow(CCObject* sender); 
	
	void onAchievements(CCObject* sender);// MenuLayer::onAchievements

	virtual bool init();
	virtual void FLAlert_Clicked(FLAlertLayer *, bool);
};

class MenuGameLayer : public cocos2d::CCLayer
{
public:

public:
	MenuGameLayer();
	virtual ~MenuGameLayer();

	static MenuGameLayer* create();

	void updateColor(float dt);
	
	virtual bool init();
	virtual void update(float dt);
};