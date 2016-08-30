#include "HelloWorldScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	
	initBG();
	initMenu();

	return true;
}


void HelloWorld::menuCallback(Ref* pSender)
{
	auto item = (MenuItem*)pSender;
	switch (item->getTag())
	{
		
		case TAG_MENUITEM_PLAY:
		{
			auto scene = TransitionFadeTR::create(1.0, GameScene::createScene());
			Director::getInstance()->replaceScene(scene);
			break;
		}
		
		case TAG_MENUITEM_QUIT:
		{
			Director::getInstance()->end();

			break;
		}
		default:
		{
			break;
		}
	}
}

void HelloWorld::initBG()
{
	auto bgSprite = Sprite::create("menuBG.jpg");
	Size winSize = Director::getInstance()->getWinSize();
	bgSprite->setPosition(Vec2(winSize.width/2,winSize.height/2));
	bgSprite->setScale(0.4);
	this->addChild(bgSprite);
	
}

void HelloWorld::initMenu()
{
	auto item_0 = MenuItemImage::create("menu-start.png", "menu-clicked-start.png", CC_CALLBACK_1(HelloWorld::menuCallback, this));
	auto item_1 = MenuItemImage::create("menu-quit.png", "menu-clicked-quit.png", CC_CALLBACK_1(HelloWorld::menuCallback, this));

	item_0->setTag(TAG_MENUITEM_PLAY);
	item_1->setTag(TAG_MENUITEM_QUIT);

	auto menu = Menu::create(item_0, item_1, NULL);
	menu->alignItemsVerticallyWithPadding(20);

	this->addChild(menu);
}

