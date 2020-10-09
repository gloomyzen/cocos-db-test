#include "AppDelegate.h"
#include "coreModule/gameManager.h"
#include "coreModule/enums/statesEnums.h"
#include "coreModule/scenes/scenesFactory/scenesFactoryInstance.h"
#include "metaModule/metaTabs.h"

// #define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#endif

USING_NS_CC;

//static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
//static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);
static cocos2d::Size designResolutionSize = cocos2d::Size(1136, 640);
static cocos2d::Size smallResolutionSize = cocos2d::Size(1136, 640);//iphone se 640 x 1136
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1136, 640);//iphone 7 750 x 1334
static cocos2d::Size largeResolutionSize = cocos2d::Size(1386, 640);//iphone x pro 1125 x 2436

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() {
#if USE_AUDIO_ENGINE
	AudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs() {
	// set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

	GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages() {
	return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("Mercenary Battles", cocos2d::Rect(0, 0, mediumResolutionSize.width,
																	  mediumResolutionSize.height));
#else
		glview = GLViewImpl::create("Mercenary Battles");
#endif
		director->setOpenGLView(glview);
	}

#ifdef DEBUG
	// turn on display FPS
	director->setDisplayStats(true);
#endif

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0f / 60);

	// Set the design resolution
//	glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height,
//									ResolutionPolicy::NO_BORDER);
//	auto frameSize = glview->getFrameSize();
//	// if the frame's height is larger than the height of medium size.
//	if (frameSize.height > mediumResolutionSize.height) {
//		director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height,
//											largeResolutionSize.width / designResolutionSize.width));
//	}
//		// if the frame's height is larger than the height of small size.
//	else if (frameSize.height > smallResolutionSize.height) {
//		director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height,
//											mediumResolutionSize.width / designResolutionSize.width));
//	}
//		// if the frame's height is smaller than the height of medium size.
//	else {
//		director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height,
//											smallResolutionSize.width / designResolutionSize.width));
//	}

	register_all_packages();
	GET_SCENES_FACTORY().registerState(mb::coreModule::eGameStates::BATTLE_SCENE, [](Layer* node)->Layer*{
		auto _background = cocos2d::Sprite::create("images/ui/windows/testWindow/background.png");
		node->addChild(_background);
		auto label = Label::createWithTTF("Battle scene", "fonts/Marker Felt.ttf", 24);
		node->addChild(label);

		return node;
	});

	GET_SCENES_FACTORY().registerState(mb::coreModule::eGameStates::MAIN_MENU, [](Layer* node)->Layer*{
		auto meta = new mb::metaModule::metaTabs();
		node->addChild(meta);

		return node;
	});

	GET_GAME_MANAGER().run(mb::coreModule::eGameStates::MAIN_MENU);

	return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
	AudioEngine::pauseAll();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
	AudioEngine::resumeAll();
#endif
}
