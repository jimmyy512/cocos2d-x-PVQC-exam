#ifndef _MyButton_H_
#define _MyButton_H_
#include "cocos2d.h"
#include "String_Process.h"
using namespace std;
class MyButton :public cocos2d::Sprite
{
public:
	virtual bool init(int numOFWord, int LabelStringType);
	static MyButton* create(int numOFWord, int LabelStringType);
	std::string getLabelEnglishString();
	std::string getLabelChineseString();
	std::string getLabelNumberString();
	void showString();
private:
	~MyButton();
private:
	bool isAnser;
	STRING_PROCESS* File_word;
	cocos2d::Label* label;
	cocos2d::Size visible_size;
	cocos2d::Vec2 origin_size;
};
#endif

