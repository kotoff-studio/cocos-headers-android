#pragma once

#include "cocos2d.h"

class ButtonSprite : public cocos2d::CCSprite
{
public:
	unsigned char _unknown[20 * sizeof(int)];

public:
	ButtonSprite();
	virtual ~ButtonSprite();

	static ButtonSprite *create(const char *text);
	static ButtonSprite *create(const char *text, float fontScale);
	static ButtonSprite *create(const char *text, int a2, int a3, float fontScale, bool a5);
	static ButtonSprite *create(const char *text, int a2, int buttonScale, float fontScale, bool a5, const char *fontName, const char *textureName);
	static ButtonSprite *create(const char *text, int a2, int a3, float fontScale, bool a5, const char *fontName, const char *textureName, float a8);
	static ButtonSprite *create(cocos2d::CCSprite *pSprite);
	static ButtonSprite *create(cocos2d::CCSprite *pSprite, int a2, int a3, float a4, float a5, bool a6);
	static ButtonSprite *create(cocos2d::CCSprite *pSprite, int a2, int a3, float a4, float a5, bool a6, const char *a7, bool a8);

	bool init(const char *text, int a2, int a3, float fontScale, bool a5, const char *fontName, const char *textureName, float a8);
	bool init(cocos2d::CCSprite *pSprite, int a2, int a3, float a4, float a5, bool a6, const char *a7, bool a8);
	void setColor(cocos2d::ccColor3B color);
	void setString(const char *str);
	void updateBGImage(const char *path);
	void updateSpriteBGSize();
};