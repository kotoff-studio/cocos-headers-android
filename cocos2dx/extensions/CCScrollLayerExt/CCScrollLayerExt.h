/*
 *  CCScrollLayerExt.h
 *  SkeletonX
 *
 *  Created by mac on 11-11-18.
 *  Copyright 2011 GeekStudio. All rights reserved.
 *
 */

#ifndef _CCSCROLLLAYER_EXT_H
#define _CCSCROLLLAYER_EXT_H

#include "platform.h"
#include "cocos2d.h"
USING_NS_CC;

class CCContentLayer : public CCLayerColor {
public:
    static CCContentLayer *create(const ccColor4B &color, GLfloat width, GLfloat height);
    void setPosition(const CCPoint &pos);
};

class CCScrollLayerExt;

class CCScrollLayerExtDelegate {
public:
    virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt * mScrollView){} // called on finger up as we are moving
    virtual void scrollViewDidEndDecelerating(CCScrollLayerExt * mScrollView){}// called when scroll view grinds to a halt
    virtual void scrollViewTouchMoving(CCScrollLayerExt * mScrollView){}//touch moving.
    virtual void scrollViewDidEndMoving(CCScrollLayerExt * mScrollView){}//it's not decelerating
    virtual void scrollViewTouchBegin(CCScrollLayerExt * mScrollView){}//touch begin
    virtual void scrollViewTouchEnd(CCScrollLayerExt * mScrollView){}//touch end
};

class CCScrollLayerExt : public CCLayer {
private:
    CCTouch * beginTouch;
    CCPoint touchOnLocation,firstTouchLocation;//stay on screen touch, and first touch
    cc_timeval beginTime;
    CC_SYNTHESIZE(bool,isTouch,IsTouch);
    CC_SYNTHESIZE(bool,isScrolling,IsScrolling);
    CC_SYNTHESIZE(CCLayerColor *,verticalScrollIndicator,VerticalScrollIndicator);
    CC_SYNTHESIZE(CCLayerColor *,horizontalScrollIndicator,HorizontalScrollIndicator);
    float getMinY();
    float getMaxY();
    void constraintContent();
    void scrollingEnd();
    void updateIndicators(ccTime mTime);
public:
    CCScrollLayerExt(CCRect mRect=CCRectZero);
    virtual ~CCScrollLayerExt();
    
    CC_SYNTHESIZE(CCScrollLayerExtDelegate*,scrollDelegate,ScrollDelegate);
    CC_SYNTHESIZE(CCLayerColor *,contentLayer,ContentLayer);
    CC_SYNTHESIZE(bool,clipsToBounds,ClipsToBounds);
    CC_SYNTHESIZE(bool,showsHorizontalScrollIndicator,ShowsHorizontalScrollIndicator);
    CC_SYNTHESIZE(bool,showsVerticalScrollIndicator,ShowsVerticalScrollIndicator);
    CC_SYNTHESIZE(bool,lockHorizontal,LockHorizontal);//lock horizontal indicator to scrolling
    CC_SYNTHESIZE(bool,lockVertical,LockVertical);//lock vertical indicator to scrolling
    CC_SYNTHESIZE(bool,touchDispatch,TouchDispatch);
    CC_SYNTHESIZE(bool,topPadding,TopPadding);
    CC_SYNTHESIZE(bool,bottomPadding,BottomPadding);
    CC_SYNTHESIZE(bool,maxOffsetTop,MaxOffsetTop);
    CC_SYNTHESIZE(bool,maxOffsetBottom,MaxOffsetBottom);
    
public:
    void setContentLayerSize(CCSize mSize);
    void setContentOffset(CCPoint mOffset,bool mAnimate);// animate at constant velocity to new offset
    void scrollToTop();
    
    void moveToTop();
    void moveToTopWithOffset(float offset);

public:
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    virtual void ccTouchCancelled(CCTouch *touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    
    virtual void visit();
    virtual void preVisitWithClippingRect(CCRect clipRect);
    virtual void postVisit();
};

#endif