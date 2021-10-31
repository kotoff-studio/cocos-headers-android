#ifndef CCContentManager_h
#define CCContentManager_h

#include "cocoa/CCDictionary.h"

using namespace cocos2d;

class CC_DLL CCContentManager {
public:
	~CCContentManager();
	
    static CCContentManager *sharedManager();
    
    bool init();
    
    void addCCDict(const char *path);
    void addDict(const char *path);
    void addPath(const char *path);
    
    void clearCache();
	
    CCDictionary *dictCache_;
    CCDictionary *pathCache_;
}

#endif