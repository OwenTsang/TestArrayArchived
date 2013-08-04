#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Student.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    testArrayArchived(initClassOne());
    
    testArrayUnarchived();
    
    return true;
}

CCArray* HelloWorld::initClassOne()
{
    CCArray* classOneArray = CCArray::createWithCapacity(3);
    
    Student* _s = new Student();
    _s->setId(1);
    _s->setName("Owen1");
    classOneArray->addObject(_s);
    _s->release();
    
    _s = new Student();
    _s->setId(2);
    _s->setName("Owen2");
    classOneArray->addObject(_s);
    _s->release();
    
    _s = new Student();
    _s->setId(3);
    _s->setName("Owen3");
    classOneArray->addObject(_s);
    _s->release();
    
    return classOneArray;
}

void HelloWorld::displayClasses(CCArray* classOneArray)
{
    CCLog("display Class One students' detail now ~~");
    
    Student*_s = NULL;
    CCObject* obj = NULL;
    CCARRAY_FOREACH(classOneArray, obj)
    {
        _s = (Student*)obj;
        CCLog("id = %d, name = %s",_s->getId(),_s->getName().c_str());
    }
}

void HelloWorld::testArrayArchived(CCArray* classOneArray)
{
    CCLog("enter function testArrayArchived()~~");
    
    displayClasses(classOneArray);
    
    CCUserDefault* writer = CCUserDefault::sharedUserDefault();
    OB_ARCHIVED_ARRAY(writer,"ClassOne",classOneArray);
    writer->flush();
    
}

void HelloWorld::testArrayUnarchived()
{
    CCLog("enter function testArrayUnarchived().....");
    CCArray*  classOneArray = NULL;
    
    CCUserDefault* reader = CCUserDefault::sharedUserDefault();
    OB_UNARCHIVED_ARRAY(classOneArray,reader,"ClassOne",Student);
 
    displayClasses(classOneArray);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
