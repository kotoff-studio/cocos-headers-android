#ifndef __CCSCROLLLAYER__
#define __CCSCROLLLAYER__
//  CCScrollLayer.h
//
//  Copyright 2010 DK101
//  http://dk101.net/2010/11/30/implementing-page-scrolling-in-cocos2d/
//
//  Copyright 2010 Giv Parvaneh.
//  http://www.givp.org/blog/2010/12/30/scrolling-menus-in-cocos2d/
//
//  Copyright 2011 Stepan Generalov
//
//  Copyright 2011 Eli Yukelzon
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

// Original source: https://github.com/cocos2d/cocos2d-iphone-extensions/tree/master/Extensions/CCScrollLayer 
// Last updated: October 1, 2011 

#include <cocos2d.h>

namespace cocos2d {

    class CCScrollLayer;

    class CCScrollLayerDelegate
    {
    public:
        /** Called when scroll layer begins scrolling.
         * Usefull to cancel CCTouchDispatcher standardDelegates.
         */
        virtual void scrollLayerScrollingStarted(CCScrollLayer* sender) {}

        /** Called at the end of moveToPage:
         * Doesn't get called in selectPage:
         */
        virtual void scrollLayerScrolledToPageNumber(CCScrollLayer* sender, unsigned int page) {}
    };

    /** The class is incomplete and doesn't actually work, use BoomScrollLayer or CCScrollLayerExt instead.
     * This header is in the SDK only for compatibility.
     */ 
    class CCScrollLayer : public CCLayer
    {
    public:
        ~CCScrollLayer();

        static CCScrollLayer* nodeWithLayers(CCArray* layers, int widthOffset); 
        bool initWithLayers(CCArray* layers, int widthOffset); 
        
        // Holds the current page being displayed
        int currentScreen;
    
        // A count of the total screens available
        int totalScreens;
    
        // Holds the current height and width of the screen
        float scrollHeight;
        float scrollWidth;
    
        // Holds the height and width of the screen when the class was initialized
        float startHeight;
        float startWidth;
        
        // The initial point the user starts their swipe
        float startSwipe;    
        
        float maximumScrollHeight;

        CC_SYNTHESIZE(CCScrollLayerDelegate*, m_pDelegate, Delegate);

        /** Calibration property. Minimum moving touch length that is enough
         * to cancel menu items and start scrolling a layer. 
         */
        CC_SYNTHESIZE(CGFloat, m_fMinimumTouchLengthToSlide, MinimumTouchLengthToSlide);

        /** Calibration property. Minimum moving touch length that is enough to change
         * the page, without snapping back to the previous selected page.
         */
        CC_SYNTHESIZE(CGFloat, m_fMinimumTouchLengthToChangePage, MinimumTouchLengthToChangePage);

        /** If YES - when starting scrolling CCScrollLayer will claim touches, that are 
         * already claimed by others targetedTouchDelegates by calling CCTouchDispatcher#touchesCancelled
         * Usefull to have ability to scroll with touch above menus in pages.
         * If NO - scrolling will start, but no touches will be cancelled.
         * Default is YES.
         */
        CC_SYNTHESIZE(bool, m_bStealTouches, StealTouches);

        /** Whenever show or not white/grey dots under the scroll layer.
         * If yes - dots will be rendered in parents transform (rendered after scroller visit).
         */
        CC_SYNTHESIZE(bool, m_bShowPagesIndicator, ShowPagesIndicator);

        /** Position of dots center in parent coordinates. 
         * (Default value is screenWidth/2, screenHeight/4)
         */
        CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_tPagesIndicatorPosition, PagesIndicatorPosition);

        /** Total pages available in scrollLayer. */
        unsigned int getTotalScreens() const;

        /** Current page number, that is shown. Belongs to the [0, totalScreen] interval. */
        CC_SYNTHESIZE_READONLY(unsigned int, m_uCurrentScreen, CurrentScreen);

        /** Offset, that can be used to let user see next/previous page. */
        CC_SYNTHESIZE(CGFloat, m_fPagesWidthOffset, PagesWidthOffset);
        
        /** Offset that can be used to let user see empty space over first or last page. */
        CC_SYNTHESIZE(CGFloat, m_fMarginOffset, MarginOffset);

        /** Array of pages CCLayer's  */
        CC_SYNTHESIZE_READONLY(CCArray*, m_pLayers, Pages);
    protected:
        // The x coord of initial point the user starts their swipe.
        CGFloat m_fStartSwipe;

        // Internal state of scrollLayer (scrolling or idle).
        int m_iState;
        bool m_bStealingTouchInProgress;
        // Holds the touch that started the scroll
        CCTouch* m_pScrollTouch;

        bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
        void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
        void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
    };
}

#endif
