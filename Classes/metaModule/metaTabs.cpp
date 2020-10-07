#include "metaTabs.h"
#include "cocos2d.h"

using namespace mb::metaModule;
using namespace cocos2d;
using namespace ui;


metaTabs::metaTabs() {
	this->setName("metaTabs");
	createPageView();
	loadProperty("menuScene/" + this->getName(), dynamic_cast<Node*>(this));
	auto test = Node::create();
	auto test1 = DrawNode::create();
}

metaTabs::~metaTabs() {}

void metaTabs::createPageView() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	const int pagesCount = 5;
	cocos2d::Size pageViewSize(visibleSize.width * pagesCount, visibleSize.width);
	cocos2d::Size pageSize(visibleSize.width, visibleSize.width);


	pageView = PageView::create();
	pageView->setName("tabsHolder");
	pageView->setDirection(PageView::Direction::HORIZONTAL);
	pageView->setMagneticType(ListView::MagneticType::CENTER);
	pageView->setGravity(ListView::Gravity::CENTER_HORIZONTAL);
	pageView->setContentSize(pageViewSize);
	pageView->setBounceEnabled(true);
	this->addChild(pageView);

	for (int i = 0; i < pagesCount; i++) {
		auto page = ui::Layout::create();
		page->setContentSize(pageView->getContentSize());
		auto sprite = Sprite::create("images/undefined1.png");
		sprite->setPosition(sprite->getContentSize() / 2);
		page->addChild(sprite);
		pageView->insertPage(page, i);
	}

	pageView->addEventListener([](Ref *sender, ui::PageView::EventType type) {
		if (type == ui::PageView::EventType::TURNING) {
			auto pageView = dynamic_cast<PageView *>(sender);
			if (pageView != nullptr) {
				CCLOG("current page no =%zd", pageView->getCurrentPageIndex());
			}
		}
	});

}
