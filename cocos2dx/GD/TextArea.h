#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class TextArea : public CCSprite
{
public:
	bool _ignoreColorCode;
	void *_pMultilineBitmapFont;
	float _limitWeight;
	unsigned char _unknown[1 * sizeof(int)];
	std::string _fontName;
	float _wrapPos;
	unsigned char _unknown2[1 * sizeof(int)];
	cocos2d::CCPoint _areaAnchor;
	unsigned char _unknown3[1 * sizeof(int)];
	float _scale;
	unsigned char _unknown4[6 * sizeof(int)];

public:
	TextArea();
	virtual ~TextArea();

	static TextArea *create(std::string text, char const *fontName, float scale, float limitWeight, cocos2d::CCPoint areaAnchor, float wrapPos, bool ignoreColorCode = false);
	bool init(std::string text, char const *fontName, float scale, float limitWeight, cocos2d::CCPoint areaAnchor, float wrapPos, bool ignoreColorCode);
	void setString(std::string text);
	
};