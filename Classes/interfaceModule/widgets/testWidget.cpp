#include "testWidget.h"

using namespace mercenaryBattles::interfaceModule;


testWidget::testWidget() {
	setId("testWidget");
	loadProperty(getId(), dynamic_cast<Node*>(this));
}

testWidget::~testWidget() {}
