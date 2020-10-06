#include "metaTabs.h"

using namespace mb::metaModule;


metaTabs::metaTabs() {
	this->setName("metaTabs");
	loadProperty("menuScene/" + this->getName(), dynamic_cast<Node*>(this));
}

metaTabs::~metaTabs() {}
