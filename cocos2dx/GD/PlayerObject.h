#pragma once

//#include "GD/GameObject.h"
#include "cocos2d.h"

enum PlayerButton {
	Space = 1
};
/*
class PlayerObject : public GameObject
{

public:
	PlayerObject();
	virtual ~PlayerObject();

    static PlayerObject *create(int a1, int a2, cocos2d::CCLayer *a3);

	void copyAttributes(PlayerObject *);
	bool init(int, int, cocos2d::CCLayer *);
	void setSecondColor(const cocos2d::_ccColor3B &);
	void updateTimeMod(float time);
	void updatePlayerBirdFrame(int iconID);
	void updatePlayerDartFrame(int iconID);
	void updatePlayerFrame(int iconID);
	void updatePlayerRollFrame(int iconID);
	void updatePlayerShipFrame(int iconID);
	int getActiveMode();
	
	bool isInNormalMode();

	void toggleBirdMode(bool a1, bool a2);
	void toggleDartMode(bool a1, bool a2);
	void toggleFlyMode(bool a1, bool a2);
	void toggleRobotMode(bool a1, bool a2);
	void toggleRollMode(bool a1, bool a2);
	void toggleSpiderMode(bool a1, bool a2);
	void toggleSwingMode(bool a1, bool a2);

	void lockPlayer();
	void pushButton(PlayerButton btn);
	bool isFlying();

	virtual void update(float dt);
	virtual void updateJump(float dt);
	virtual void setScaleX(float);
	virtual void setScaleY(float);
	virtual void setScale(float);
	virtual void setPosition(const cocos2d::CCPoint &);
	virtual void setVisible(bool);
	virtual void setRotation(float);
	virtual void setOpacity(GLubyte opacity);
	virtual void setColor(const cocos2d::_ccColor3B & rgb);
	virtual void setFlipX(bool);
	virtual void setFlipY(bool);
	virtual void resetObject();

	virtual void animationFinished(const char *);
};*/
