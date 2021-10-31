#ifndef DS_Dictionary_h
#define DS_Dictionary_h

#include "pugixml.hpp" 
#include "DS_Dictionary_Extra.h"
#include "cocos2d.h"
#include <map>

using namespace pugi;
using namespace std;
using namespace cocos2d;

namespace cocos2d {
	class CCObject;
	class CCPoint;
	class CCRect;
	class CCArray;
	class CCDictionary;
}

class FileOperation
{
public:
    static void saveFile();
    static string getFilePath();
};

class CC_DLL ObjectManager : public CCNode
{
public:
	static ObjectManager *instance();
	bool init();
	
	void setup();
	
	static void replaceAllOccurencesOfString(CCString *from, CCString *to, CCDictionary *in);
	
	void setLoaded(const char *animation);
	
	void loadCopiedAnimations();
	void loadCopiedSets();
	
	void animLoaded(const char *animation);
	CCDictionary *getDefinition(const char *key);
	CCDictionary *getGlobalAnimCopy(const char *key);
	
	CCDictionary *objectDefinitions_;
	CCDictionary *loadedObjects_;
};

class CC_DLL ObjectDecoder
{
public:
    static CCObject *getDecodedObject(const char *key);
};

class CC_DLL DS_Dictionary
{
private:
    //Data
    xml_document doc;
    vector<xml_node> dictTree;

    //Constructor blockers
    DS_Dictionary(const DS_Dictionary& dictionary);                //Copy constructor - blocker
    DS_Dictionary& operator= (const DS_Dictionary& dictionary);    //Assignment - blocker

                                                                   //Methods
    string cleanStringWhiteSpace(const string& _str);
    void split(const string& src, const char* token, vector<string>& vect);
    bool splitWithForm(const string& content, vector<string>& strs);
    bool rectFromString(const string& pszContent, CCRect& rect);
    bool vec2FromString(const string& pszContent, CCPoint& vec2);

public:
    //Constructor
    DS_Dictionary();

    //Methods
    bool loadRootSubDictFromFile(const char* fileName);
    bool saveRootSubDictToFile(const char* fileName);
    bool loadRootSubDictFromString(string val);
    string saveRootSubDictToString();
    bool stepIntoSubDictWithKey(const char* key);
    void stepOutOfSubDict();
    void stepBackToRootSubDict();

    uint getNumKeys();
    string getKey(uint index);
    vector<string> getAllKeys();
    uint getIndexOfKey(const char* key);
    uint getIndexOfKeyWithClosestAlphaNumericalMatch(const char* key);

    void removeKey(uint index);
    void removeKey(const char* key);
    void removeAllKeys();

    int getIntegerForKey(const char* key);
    bool getBoolForKey(const char* key);
    float getFloatForKey(const char* key);
    string getStringForKey(const char* key);
    CCPoint getVec2ForKey(const char* key);
    CCRect getRectForKey(const char* key);
    vector<string> getStringArrayForKey(const char* key);
    vector<CCPoint> getVec2ArrayForKey(const char* key);
    vector<CCRect> getRectArrayForKey(const char* key);
    CCArray *getArrayForKey(const char *key);
    CCDictionary *getDictForKey(const char *key);
    CCObject *getObjectForKey(const char *key);

    void setSubDictForKey(const char* key);
    void setSubDictForKey(const char* key, bool alphaNumericallySorted);
    void setIntegerForKey(const char* key, int value);
    void setIntegerForKey(const char* key, int value, bool alphaNumericallySorted);
    void setBoolForKey(const char* key, bool value);
    void setBoolForKey(const char* key, bool value, bool alphaNumericallySorted);
    void setFloatForKey(const char* key, float value);
    void setFloatForKey(const char* key, float value, bool alphaNumericallySorted);
    void setStringForKey(const char* key, const string& value);
    void setStringForKey(const char* key, const string& value, bool alphaNumericallySorted);
    void setVec2ForKey(const char* key, const CCPoint& value);
    void setVec2ForKey(const char* key, const CCPoint& value, bool alphaNumericallySorted);
    void setRectForKey(const char* key, const CCRect& value);
    void setRectForKey(const char* key, const CCRect& value, bool alphaNumericallySorted);
    void setStringArrayForKey(const char* key, const vector<string>& value);
    void setStringArrayForKey(const char* key, const vector<string>& value, bool alphaNumericallySorted);
    void setVec2ArrayForKey(const char* key, const vector<CCPoint>& value);
    void setVec2ArrayForKey(const char* key, const vector<CCPoint>& value, bool alphaNumericallySorted);
    void setRectArrayForKey(const char* key, const vector<CCRect>& value);
    void setRectArrayForKey(const char* key, const vector<CCRect>& value, bool alphaNumericallySorted);
    void setArrayForKey(const char *key, CCArray *value);
    void setDictForKey(const char *key, CCDictionary *value);
    void setObjectForKey(const char *key, CCObject *value);
    CCObject *decodeObjectForKey(const char *key);
};

#endif