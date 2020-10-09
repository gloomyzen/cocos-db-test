#include "simpleTab.h"

using namespace mb::metaModule;


simpleTab::simpleTab() {
	this->setName("simpleTab");
	loadProperty("menuScene/tabs/" + this->getName(), dynamic_cast<Node*>(this));
}

simpleTab::~simpleTab() = default;
