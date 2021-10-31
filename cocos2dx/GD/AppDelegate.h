#pragma once

//#include "CCApplication.h"
#include "cocos2d.h"

class AppDelegate : public cocos2d::CCScene//Delegate
{
public:
	static AppDelegate *get();

	virtual float bgScale();

	virtual bool applicationDidFinishLaunching();
	virtual void applicationDidEnterBackground();
	virtual void applicationWillEnterForeground();
	virtual void applicationWillBecomeActive();
	virtual void applicationWillResignActive();
	virtual void trySaveGame();
	virtual void setupGLView();
	virtual void platformShutdown();
	virtual void willSwitchToScene(cocos2d::CCScene *pScene);
	void loadingIsFinished();
	void pauseGame();
	void resumeSound();
	bool getScenePointer();
};