#include "testWidget.h"

using namespace mercenaryBattles::interfaceModule;


testWidget::testWidget() {
	this->setName("testWidget");
	loadProperty(this->getName(), dynamic_cast<Node*>(this));
}

testWidget::~testWidget() {}
