#include "cocos2d.h"

class SliderThumb : public cocos2d::CCLayer
{
public:
    SliderThumb();
    virtual ~SliderThumb();

    static SliderThumb* create(CCNode* p1, void* func, const char* p3, const char* p4);

    float getValue();
    void setValue(float value);

    virtual bool init(CCNode* p1, void* func, const char* p3, const char* p4);
};