#ifndef _WordList_H_
#define _WordList_H_
#include "cocos2d.h"
using namespace std;
class WordList :public cocos2d::LayerColor
{

public:
	static cocos2d::Scene* create_scene();
	virtual bool init();
	CREATE_FUNC(WordList);
	cocos2d::Size visible_size;
	cocos2d::Vec2 origin_size;
	float startPosY;
private:
	cocos2d::LabelTTF* Word_List;
	cocos2d::Label* check_label;
	virtual void onEnter();

};
#endif

