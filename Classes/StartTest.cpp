#include "StartTest.h"
#include "MyMenu.h"
#include "MyButton.h"
USING_NS_CC;
Scene* StartTest::create_scene(int mode)//0 choose english 1 choose chinese
{
	auto layer = StartTest::create(mode);
	auto scene = Scene::create();
	scene->addChild(layer);
	return scene;
}
StartTest* StartTest::create(int mode)
{
	StartTest *pRet = new(std::nothrow) StartTest(); 
	if (pRet && pRet->init(mode))
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

bool StartTest::init(int mode)
{
	if (!LayerColor::initWithColor(Color4B::WHITE))
		return false;
	thisMode = mode;//init
	visible_size = Director::getInstance()->getVisibleSize();
	origin_size = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(StartTest::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin_size.x + visible_size.width - closeItem->getContentSize().width / 2,
		origin_size.y + closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	auto backGround = Sprite::create("BackGround.png");
	backGround->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height / 2 + origin_size.y);
	backGround->setOpacity(150);
	addChild(backGround, 0);
	
	correct = Sprite::create("correct.png");
	correct->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height * 9 / 10 + origin_size.y);
	correct->setScale(0.4);
	correct->setVisible(false);
	addChild(correct, 2);

	falsePNG = Sprite::create("false.png");
	falsePNG->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height * 9 / 10 + origin_size.y);
	falsePNG->setScale(0.4);
	falsePNG->setVisible(false);
	addChild(falsePNG, 2);

	

	int randNum[3] = { 0 };
	GeneateRandomNumber(randNum);
	if (thisMode == 0)
	{
		btn = MyButton::create(randNum[0], 2);
		btn2 = MyButton::create(randNum[1], 2);
		btn3 = MyButton::create(randNum[2], 2);
	}
	else
	{
		btn = MyButton::create(randNum[0], 3);
		btn2 = MyButton::create(randNum[1], 3);
		btn3 = MyButton::create(randNum[2], 3);
	}
	
	btn->setPosition(visible_size.width / 2+origin_size.x, visible_size.height / 2+origin_size.y);
	addChild(btn,2,0);
	
	btn2->setPosition(visible_size.width / 2+origin_size.x, visible_size.height / 3+origin_size.y);
	addChild(btn2, 2,1);

	btn3->setPosition(visible_size.width / 2+origin_size.x, visible_size.height / 6+origin_size.y);
	addChild(btn3, 2,2);
	

	MyButton* p;
	int randString = rand() % 3;
	this->setAnsernum(randString);
	if (randString == 0)
		p = btn;
	else if (randString==1)
		p = btn2;
	else
		p = btn3;

	if (thisMode==0)
		topic = LabelTTF::create(p->getLabelChineseString(), "fonts/ARCENA.TTF", 20);
	else
		topic = LabelTTF::create(p->getLabelEnglishString(), "fonts/ARCENA.TTF", 20);
	topic->setColor(Color3B::BLACK);
	topic->setPosition(visible_size.width/2+origin_size.x,visible_size.height * 7 / 10+origin_size.y);
	addChild(topic, 2);

	return true;
}
void StartTest::menuCloseCallback(Ref* psender)
{
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.4f,MyMenu::createScene()));
}
void StartTest::onEnter()
{
	LayerColor::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* t, Event* e)
	{
		static int nextScene = 1;
		if (nextScene < 2)
		{
			auto button = this->getChildByTag(this->getAnsernum());
			if (this->isTap(button, t))
			{
				this->showCorrect();
				this->correctAnimation();
			}
			else
			{
				this->showFalse();
				this->failAnimation();
			}
		}
		if (nextScene++ ==2 )//點擊兩次後 重新讀取此頁面(換下一題)
		{
			nextScene = 1;
			Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3f,StartTest::create_scene(thisMode)));
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,btn );
}
void StartTest::showCorrect()
{
	correct->setVisible(true);
}
void StartTest::showFalse()
{
	falsePNG->setVisible(true);
}
void StartTest::correctAnimation()
{
	btn->showString();
	btn2->showString();
	btn3->showString();

	btn->setOpacity(180);
	btn2->setOpacity(180);
	btn3->setOpacity(180);

}
void StartTest::failAnimation()
{
	btn->showString();
	btn2->showString();
	btn3->showString();

	btn->runAction(RotateBy::create(0.5f, 360.));
	btn2->runAction(RotateBy::create(0.5f, 360.));
	btn3->runAction(RotateBy::create(0.5f, 360.));


	btn->setOpacity(180);
	btn2->setOpacity(180);
	btn3->setOpacity(180);
}
bool StartTest::isTap(Node *node, Touch* t)
{
	Vec2 location = node->convertTouchToNodeSpace(t);
	Size s = node->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(location))
		return true;
	return false;
}
void StartTest::GeneateRandomNumber(int randNum[])
{
	for (int i = 0; i < 3; i++)
	{
		int RandNumber = rand() % 645 + 1;
		for (int j = 0; j <i; j++)
		{
			if (RandNumber == randNum[j])
			{
				i--;
				break;
			}
		}
		randNum[i] = RandNumber;
	}
}
void StartTest::setAnsernum(int wantToSet)
{
	Ansernum = wantToSet;
}
int StartTest::getAnsernum()
{
	return Ansernum;
}
