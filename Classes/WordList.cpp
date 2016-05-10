#include "WordList.h"
USING_NS_CC;
Scene* WordList::create_scene()
{
	auto layer = WordList::create();
	auto scene = Scene::create();
	scene->addChild(layer);

	return scene;
}
bool WordList::init()
{
	if (!LayerColor::initWithColor(Color4B::WHITE))
		return false;
	visible_size = Director::getInstance()->getVisibleSize();
	origin_size = Director::getInstance()->getVisibleOrigin();
	auto backGround = Sprite::create("ChooseEnglish.jpg");
	backGround->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height / 2 + origin_size.y);
	backGround->setOpacity(50);

	long filesize = 0;
	auto WordList = FileUtils::getInstance()->getStringFromFile("fuck.txt");
	Word_List = LabelTTF::create();
	Word_List->setString(WordList);
	//Word_List->setSystemFontName("fonts/ARCENA.ttf");
	Word_List->setColor(Color3B::BLACK);
	Word_List->setPosition(visible_size.width / 2 + visible_size.width / 7 + origin_size.x, visible_size.height / 2 + origin_size.y);
	
	check_label = Label::create();
	//check_label->setString(StringUtils::format("%d", Word_List->getStringLength()));
	check_label->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height / 2 + origin_size.y);
	check_label->setColor(Color3B::RED);
	check_label->setSystemFontSize(16);
	addChild(check_label, 2, 2);


	addChild(Word_List, 1, 1);
	addChild(backGround, 0, 0);
	return true;
}
void WordList::onEnter()
{
	LayerColor::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	float moveSlow = visible_size.height/24 + origin_size.y;
	float movefast = visible_size.height / 8 + origin_size.y;
	listener->onTouchBegan = [&](Touch* t, Event* e)
	{
		check_label->setString(StringUtils::format("%f %f", Word_List->getPositionX(), Word_List->getPositionY()));
		startPosY = t->getLocation().y;
		return true;
	};
	listener->onTouchMoved = [=](Touch* t, Event* e)
	{
		float movePosY = t->getLocation().y;
		float movedistence;
		log("pos %f", Word_List->getPositionY());
		if (movePosY > startPosY)//往下瀏覽
		{
			if (Word_List->getPositionY() < (float)4824)
			{
				movedistence = movePosY - startPosY;
				if (movedistence > visible_size.height / 2 + origin_size.y)//觸摸差距很大加速瀏覽
					Word_List->runAction(MoveBy::create(0.3, Vec3(0, movefast, 0)));
				else
					Word_List->runAction(MoveBy::create(0.3, Vec3(0, moveSlow, 0)));
			}
			
		}
		if (movePosY < startPosY)//網上流覽
		{
			if (Word_List->getPositionY() > (float) -4300)
			{
				movedistence = startPosY - movePosY;
				if (movedistence > visible_size.height / 2 + origin_size.y)//觸摸差距很大加速瀏覽
					Word_List->runAction(MoveBy::create(0.3, Vec3(0, -movefast, 0)));
				else
					Word_List->runAction(MoveBy::create(0.3, Vec3(0, -moveSlow, 0)));
			}
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, Word_List);




}