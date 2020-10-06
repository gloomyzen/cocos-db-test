#include "metaTabs.h"

using namespace mb::metaModule;


metaTabs::metaTabs() {
	this->setName("testWidget");
	loadProperty(this->getName(), dynamic_cast<Node*>(this));
}

metaTabs::~metaTabs() {}
