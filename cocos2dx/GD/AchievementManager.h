#pragma once

#include "cocos2d.h"

class AchievementManager : public cocos2d::CCNode
{
public:
    AchievementManager();
    virtual ~AchievementManager();

    static AchievementManager* sharedState();

    void notifyAchievement(const char* title, const char* description, const char* sprite);
};