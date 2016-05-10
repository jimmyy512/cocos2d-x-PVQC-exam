#ifndef __MyMenu_SCENE_H__
#define __MyMenu_SCENE_H__

#include "cocos2d.h"
class MyMenu : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MyMenu);
private:
	cocos2d::MenuItemImage* chooseEnglish;
	cocos2d::MenuItemImage* chooseChinese;
	cocos2d::MenuItemImage* Exit;
	cocos2d::Size visible_size;
	cocos2d::Vec2 origin_size;
	cocos2d::Label* Label_chooseEnglish;
	cocos2d::Label* Label_chooseChinese;
	cocos2d::Label* Label_Exit;
	bool labelMove;
	int LabelSelect;
private:
	void onEnter();
};

#endif // __MyMenu_SCENE_H__
