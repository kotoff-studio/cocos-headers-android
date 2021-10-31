#include "cocos2d.h"
#include "base_nodes/CCNode.h"

class TextAlertPopup : public cocos2d::CCNode {

public:
TextAlertPopup();
virtual ~TextAlertPopup();

static TextAlertPopup* create(std::string description, float weight, float height);
static bool init(std::string description, float weight, float height);

};