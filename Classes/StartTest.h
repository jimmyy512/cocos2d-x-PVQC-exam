#ifndef _StartTest_H_
#define _StartTest_H_
#include "cocos2d.h"
#include "String_Process.h"
#include "MyButton.h"
using namespace std;
class StartTest :public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* create_scene(int mode);
	static StartTest* create(int mode);
	void setAnsernum(int wantToSet);
	int getAnsernum();
	bool isTap(cocos2d::Node *node, cocos2d::Touch* t);
	void failAnimation();
	void correctAnimation();
	void showCorrect();
	void showFalse();
	virtual bool init(int num);
	
private:
	cocos2d::Size visible_size;
	cocos2d::Vec2 origin_size;
	cocos2d::Sprite* correct;
	cocos2d::Sprite* falsePNG;
	cocos2d::LabelTTF* topic;
	MyButton* btn;
	MyButton* btn2;
	MyButton* btn3;
	int thisMode;
private:
	void menuCloseCallback(cocos2d::Ref* psender);
	int Ansernum;
	void GeneateRandomNumber(int randNum[]);
	virtual void onEnter();
};





#endif
