#include "MyButton.h"
USING_NS_CC;
MyButton* MyButton::create(int numOFWord, int LabelStringType)//第幾個單字,文字要英文還是中文還是號碼
{
	MyButton *pRet = new (std::nothrow)MyButton();
	if (pRet && pRet->init(numOFWord,LabelStringType))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}
bool MyButton::init(int numOFWord, int LabelStringType)
{
	if (!Sprite::init())
		return false;
	setAnchorPoint(Vec2(0.5, 0.5));
	initWithFile("button4.png");
	File_word = new STRING_PROCESS(numOFWord);
	isAnser = false;
	setOpacity(180);

	label = Label::create();
	label->setSystemFontName("fonts/ARCENA.TTF");
	label->setSystemFontSize(13);
	label->setScaleY(1.1);
	label->setColor(Color3B::BLACK);
	label->setPosition(Vec2(getContentSize().width / 2, getContentSize().height / 2));
	if (LabelStringType==1)//number label
		label->setString(File_word->getNumberWord());
	else if (LabelStringType == 2)//english label
		label->setString(File_word->getEnglishWord());
	else if (LabelStringType == 3)//chinese label
	{
		label->setString(File_word->getChineseWord());
		label->setPosition(Vec2(getContentSize().width / 2+origin_size.x, getContentSize().height / 2.5+origin_size.y));
	}
	addChild(label,4,4);
	return true;
}
std::string MyButton::getLabelEnglishString()
{
	return File_word->getEnglishWord();
}
std::string MyButton::getLabelChineseString()
{
	return File_word->getChineseWord();
}
std::string MyButton::getLabelNumberString()
{
	return File_word->getNumberWord();
}
void MyButton::showString()
{
	std::string wantToShow = File_word->getEnglishWord() + "  " + File_word->getChineseWord();
	label->setString(wantToShow);
	label->setPosition(Vec2(getContentSize().width / 2 + origin_size.x, getContentSize().height / 2.5 + origin_size.y));
}
MyButton::~MyButton()
{
	delete File_word;
}
