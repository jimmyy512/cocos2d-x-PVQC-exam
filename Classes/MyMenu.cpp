#include "MyMenu.h"
#include "StartTest.h"
using namespace std;
USING_NS_CC;

Scene* MyMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = MyMenu::create();
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MyMenu::init()
{
    //////////////////////////////
    // 1. super init first
	if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
	labelMove = false;//init
	visible_size = Director::getInstance()->getVisibleSize();
	origin_size = Director::getInstance()->getVisibleOrigin();

	auto created = Label::create();
	created->setPosition(visible_size.width * 8 / 11 + origin_size.x, visible_size.height * 1 / 15 + origin_size.y);
	created->setSystemFontSize(15);
	created->setColor(Color3B::BLACK);
	created->setString("created By Majitoo");
	created->setSystemFontName("fonts/21bit.TTF");
	created->setOpacity(180);
	addChild(created, 2);


	auto backGround = Sprite::create("BackGround.png");
	backGround->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height/2  + origin_size.y);
	backGround->setOpacity(200);
	addChild(backGround, 0);

	auto title = Sprite::create("Title.png");
	title->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height*8/10 + origin_size.y);
	title->setOpacity(180);
	addChild(title, 2);


	chooseEnglish = MenuItemImage::create("MenuButtonUnclick.png", "MenuButtonClick.png", [=](Object *sender){
		Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f,StartTest::create_scene(0)));
	});
	chooseEnglish->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height * 6 / 10 + origin_size.y);
	chooseEnglish->setTag(1);
	Label_chooseEnglish = Label::createWithTTF("ChooseEnglish", "fonts/ARCENA.ttf", 20);
	Label_chooseEnglish->setColor(Color3B::BLACK);
	Label_chooseEnglish->setPosition(chooseEnglish->getPositionX() - visible_size.width / 10, chooseEnglish->getPositionY());
	addChild(Label_chooseEnglish, 2);

	chooseChinese = MenuItemImage::create("MenuButtonUnclick.png", "MenuButtonClick.png", [=](Object *sender){
		Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, StartTest::create_scene(1)));
	});
	chooseChinese->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height*4/10 + origin_size.y);
	chooseChinese->setTag(2);
	Label_chooseChinese = Label::createWithTTF("ChooseChinese", "fonts/ARCENA.ttf", 20);
	Label_chooseChinese->setColor(Color3B::BLACK);
	Label_chooseChinese->setPosition(chooseChinese->getPositionX() - visible_size.width / 10, chooseChinese->getPositionY());
	addChild(Label_chooseChinese, 2);

	Exit = MenuItemImage::create("MenuButtonUnclick.png", "MenuButtonClick.png", [=](Object *sender){
		Director::getInstance()->end();
	});
	Exit->setPosition(visible_size.width / 2 + origin_size.x, visible_size.height * 2 / 10 + origin_size.y);
	Exit->setTag(3);
	Label_Exit = Label::createWithTTF("Exit APP", "fonts/ARCENA.ttf", 20);
	Label_Exit->setColor(Color3B::BLACK);
	Label_Exit->setPosition(Exit->getPositionX() - visible_size.width / 10, Exit->getPositionY());
	addChild(Label_Exit, 2);



	auto MENU = Menu::create(chooseEnglish,chooseChinese,Exit, NULL);
	MENU->setPosition(Vec2::ZERO);
	addChild(MENU, 1);

    return true;
}
void MyMenu::onEnter()
{
	Layer::onEnter();
	auto Buttonlisten = EventListenerTouchOneByOne::create();
	Buttonlisten->onTouchBegan = [=](Touch* t,Event* e)
	{
		if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation()) && !labelMove)
		{
			LabelSelect = e->getCurrentTarget()->getTag();
			if (LabelSelect==1)
				Label_chooseEnglish->setPositionY(Label_chooseEnglish->getPositionY() - visible_size.height / 50);
			else if (LabelSelect==2)
				Label_chooseChinese->setPositionY(Label_chooseChinese->getPositionY() - visible_size.height / 50);
			else
				Label_Exit->setPositionY(Label_Exit->getPositionY() - visible_size.height / 50);
			labelMove = true;
			return true;
		}
		return false;
	};
	Buttonlisten->onTouchMoved= [=](Touch* t, Event* e)
	{
		if (!(e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation())) && labelMove)
		{
			if (LabelSelect == 1)
				Label_chooseEnglish->setPositionY(Label_chooseEnglish->getPositionY() + visible_size.height / 50);
			else if (LabelSelect == 2)
				Label_chooseChinese->setPositionY(Label_chooseChinese->getPositionY() + visible_size.height / 50);
			else
				Label_Exit->setPositionY(Label_Exit->getPositionY() + visible_size.height / 50);
			labelMove = false;
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Buttonlisten, chooseEnglish);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Buttonlisten->clone(), chooseChinese);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(Buttonlisten->clone(), Exit);


}
